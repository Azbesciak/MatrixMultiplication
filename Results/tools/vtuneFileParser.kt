import FunTimeData.Companion.create
import java.io.File
import java.math.BigDecimal
import java.math.RoundingMode

private const val VTUNE_SEPARATOR = ","


fun main(args: Array<String>) {
    require(args.size == 3) {
        """|
        |Usage:
        |    1 arg: source path (multiple - comma-separated)
        |    2 arg: times path (multiple - comma-separated)
        |    3 arg: result output
        |""".trimMargin()
    }

    val vtuneResults = vtuneFile(args[0])
    val otherColumns = listOf("time_avg", "time_min", "time_max", "type","n", "r").toHeader()
    val header = vtuneResults.first() + otherColumns
    val times = readTimes(args[1])
    val results = mergeVtuneWithTimes(vtuneResults, times)
    writeLinesToFile(args[2], listOf(header) + results)
}

private fun List<String?>.toHeader() = joinToString("") {"$VTUNE_SEPARATOR$it"}

private fun vtuneFile(fileName: String) =
        readMultipleFiles(fileName)
                .map { prepareSingleVtuneFile(it) }
                .mapIndexed { i, l -> i to l }
                .flatMap { if (it.first == 0) it.second else it.second.drop(1) }

private fun prepareSingleVtuneFile(fileLines: List<String>) =
        fileLines.map { it.replace("\"", "") }
                .filter { it.startsWith("multiply") or it.startsWith("Function") }
                .map { it.replace("(void)", "") }
                .map { it.replace("\$omp\$1", "") }
                .map { it.replace("multiply_matrices_", "") }
                .toList()


private fun readTimes(fileName: String) =
        readMultipleFiles(fileName)
                .map { parseSingleTimesFile(it) /*just for safety */ }
                .flatten()

private fun parseSingleTimesFile(fileLines: List<String>) =
        fileLines.drop(2)
                .map {
                    it.replace("SEQ_", "").split(";")
                            .map { it.trim() }
                }
                .map(::create)


class FunTimeData(val name: String, val type: String, val n: Int, val r: Int, val time: BigDecimal) {
    companion object {
        fun create(list: List<String>): FunTimeData {
            val name = list[0].toLowerCase()
            val indexOfFirst = name.indexOfFirst { it in '0'..'9' }
            val type = name.take(indexOfFirst - 1)
            return FunTimeData(name, type, list[1].toInt(), list[2].toInt(), list[3].bigDecimal())
        }
    }
}

private fun readMultipleFiles(fileNames: String) =
        fileNames.split(",").map { readFileLines(it) }

private fun readFileLines(fileName: String) = File(fileName)
        .inputStream().bufferedReader().useLines { it.toList() }

private fun mergeVtuneWithTimes(vtuneLines: List<String>, times: List<FunTimeData>): List<String> {
    val vtuneWithoutHeader = vtuneLines.drop(1)
    validateInputForMerging(times, vtuneWithoutHeader)
    val size = BigDecimal(Math.ceil(times.size.toDouble() / vtuneWithoutHeader.size)).setScale(10)

    val timesGrouped = times.groupBy { it.name }
    val funParams = timesGrouped
            .mapValues { it.value.first() }
            .mapValues { it.value.let { "${it.type}$VTUNE_SEPARATOR${it.n}$VTUNE_SEPARATOR${it.r}" } }
    val timesByFunction = timesGrouped
            .mapValues { it.value.map { it.time } }
    val timesAverage = timesByFunction
            .mapValues { it.value.reduce { acc, v -> acc + v } / size }
            .mapValues { it.value.asString() }
    val timesMax = timesByFunction.mapValues { it.value.max()!!.asString() }
    val timesMin = timesByFunction.mapValues { it.value.min()!!.asString() }
    val functions = vtuneWithoutHeader
            .map { it.split(VTUNE_SEPARATOR) }
            .groupBy { it.first() }
            .mapValues {
                it.value.map { it.drop(1).map { it.bigDecimal().setScale(10) } }
                        .aggregateToAverage(size)
            }.mapValues { it.value.joinToString(VTUNE_SEPARATOR) { it.asString(0) } }

    return functions
            .toList()
            .sortedByDescending { extractInstanceKey(it) }
            .map {
                it.first + listOf(it.second, timesAverage[it.first], timesMin[it.first], timesMax[it.first], funParams[it.first]).toHeader()
            }
}


private fun extractInstanceKey(it: Pair<String, *>): InstanceName {
    val indexOfFirstNumber = it.first.indexOfFirst { it in '1'..'9' }
    val key = it.first.take(indexOfFirstNumber)
    val values = it.first.drop(indexOfFirstNumber).split("_").map { it.toInt() }
    return InstanceName(key, values)
}

private fun BigDecimal.asString(scale: Int = 5) =
        setScale(scale, RoundingMode.HALF_UP)
                .stripTrailingZeros()
                .toEngineeringString()

private fun List<List<BigDecimal>>.aggregateToAverage(totalSize: BigDecimal) =
        reduce { acc, list ->
            acc.zip(list) { f, s -> f + s }
        }.map { it / totalSize }

private fun String.bigDecimal() = if (isBlank()) BigDecimal.ZERO else toBigDecimal()

private fun validateInputForMerging(times: List<FunTimeData>, inv: List<String>) {
    require(times.isNotEmpty()) { "Brak czasów" }
    require(inv.isNotEmpty()) { "Brak wywołań" }
    val timesNames = times.map { it.name }.distinct()
    val invMapped = inv.map { it.split(VTUNE_SEPARATOR).first() }.distinct()
    val notIncludedInTimes = invMapped
            .filterNot { timesNames.contains(it) }
    val notIncludedInInv = timesNames.filterNot { invMapped.contains(it) }
    require(timesNames.size == invMapped.size) {
        "No stary, czasy sie wysypały... pomiarów ${timesNames.size} a funkcji ${invMapped.size}, \nbrakuje w funkcjach: $notIncludedInInv,\n w czasach: $notIncludedInTimes" // hyhy. too late.
    }
}

private fun writeLinesToFile(path: String, lines: Iterable<String>) = File(path).apply {
    parentFile.mkdirs()
    createNewFile()
    bufferedWriter().use { writer ->
        lines.forEach {
            writer.write(it)
            writer.newLine()
        }
    }
}


private class InstanceName(val key: String, val values: List<Int>) : Comparable<InstanceName> {
    override fun compareTo(other: InstanceName): Int {
        val compareTo = key.compareTo(other.key)
        if (compareTo != 0) return compareTo
        val sizeEqual = values.size.compareTo(other.values.size)
        if (sizeEqual != 0) return sizeEqual
        return values.zip(other.values)
                .map { -(it.first.compareTo(it.second)) }
                .filter { it != 0 }
                .firstOrNull() ?: 0
    }

}