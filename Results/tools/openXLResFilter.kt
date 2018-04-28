
import java.io.File
import java.math.BigDecimal

const val OPEN_XL_SEPARATOR = "\t"


fun main(args: Array<String>) {
    require(args.size == 5) {
        """|
        |Usage:
        |    1 arg: source path (multiple - comma-separated)
        |    2 arg: times path (multiple - comma-separated)
        |    3 arg: inv. order path
        |    4 arg: events inc
        |    5 arg: result output
        |""".trimMargin()
    }

    val openXlResults = cleanOpenXl(args[0])
    val header = openXlResults.first() + "${OPEN_XL_SEPARATOR}time"
    val times = readTimes(args[1])
    val mappings = prepareMappings(args[2])
    val incs = prepareInc(args[3])
    val results = mergeOpenXlWithTimes(openXlResults, times, mappings, incs)
    writeLinesToFile(args[4], listOf(header) + results)
}

private fun cleanOpenXl(fileName: String) =
        readMultipleFiles(fileName)
                .map { prepareSingleOpenXlFile(it) }
                .mapIndexed { i, l -> i to l }
                .flatMap { if (it.first == 0) it.second else it.second.drop(1) }

private fun prepareSingleOpenXlFile(fileLines: List<String>) =
        fileLines.filter { it.startsWith("multiply") or it.startsWith("Function") }
                .map { it.replace("(void)", "") }
                .map { it.replace("${it.split(OPEN_XL_SEPARATOR)[1]}$OPEN_XL_SEPARATOR", "") }
                .map { it.replace("multiply_matrices_", "") }
                .toList()

const val TIMES_HEADER = "Czas wykonania programu:"

private fun readTimes(fileName: String) =
        readMultipleFiles(fileName)
                .map { parseSingleTimesFile(it) /*just for safety */ }
                .flatten()

private fun parseSingleTimesFile(fileLines: List<String>) =
        fileLines.filter { it.startsWith(TIMES_HEADER) }
                .map {
                    it.substringAfter(TIMES_HEADER)
                            .substringBefore("sec")
                            .trim { it == ' ' }
                }
                .map { it.toBigDecimal() }

private fun prepareMappings(fileName: String) = readFileLines(fileName)
        .map { it.substringAfter("multiply_matrices_").substringBefore(",") }

private fun readMultipleFiles(fileNames: String) =
        fileNames.split(",").map { readFileLines(it) }

private fun readFileLines(fileName: String) = File(fileName)
        .inputStream().bufferedReader().useLines { it.toList() }

private fun prepareInc(fileName: String) = readFileLines(fileName)
        .map { it.split(";") }
        .groupBy { it.first() }
        .mapValues {it.value.first().last().bigDecimal()}

private fun mergeOpenXlWithTimes(openXlLines: List<String>, times: List<BigDecimal>,
                                 mapping: List<String>, incs: Map<String, BigDecimal>): List<String> {
    validateInputForMerging(times, mapping)
    val size = BigDecimal(times.size / mapping.size).setScale(10)
    val mergedTimes = times
            .chunked(mapping.size)
            .aggregateToAverage(size)
            .map { it.toEngineeringString() }

    val measurementWithInc = openXlLines.first()
            .split(OPEN_XL_SEPARATOR)
            .drop(1)
            .map { incs[it]!! }

    val functions = openXlLines.drop(1)
            .map { it.split(OPEN_XL_SEPARATOR) }
            .groupBy { it.first() }
            .mapValues {
                it.value.map { it.drop(1).map { it.bigDecimal() } }
                        .aggregateToAverage(size)
            }.mapValues {
                mapOpenXLMeasurements(it.value, measurementWithInc)
                        .joinToString(OPEN_XL_SEPARATOR) { it.toEngineeringString() }
            }

    return mapping
            .filter { functions.containsKey(it) }
            .map { "$it$OPEN_XL_SEPARATOR${functions[it]!!}" }
            .zip(mergedTimes)
            .map { "${it.first}$OPEN_XL_SEPARATOR${it.second}" }
}

private fun mapOpenXLMeasurements(measurements: List<BigDecimal>, incsOrdered: List<BigDecimal>) =
        measurements.zip(incsOrdered).map { it.first * it.second }


private fun List<List<BigDecimal>>.aggregateToAverage(totalSize: BigDecimal) =
        reduce { acc, list ->
            acc.zip(list) { f, s -> f + s }
        }.map { it / totalSize }

private fun String.bigDecimal() = if (isBlank()) BigDecimal.ZERO else toBigDecimal()

private fun validateInputForMerging(times: List<BigDecimal>, mapping: List<String>) {
    require(times.isNotEmpty()) { "Brak czasów" }
    require(mapping.isNotEmpty()) { "Brak mapowania" }
    require(times.size % mapping.size == 0) {
        "No stary, czasy sie wysypały... pomiarów ${times.size} a funkcji ${mapping.size}" // hyhy. too late.
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