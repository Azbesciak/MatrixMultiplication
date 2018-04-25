import java.io.File
import java.math.BigDecimal

const val OPEN_XL_SEPARATOR = "\t"


fun main(args: Array<String>) {
    require(args.size == 4) {
        """|
        |Usage:
        |    1 arg: source path
        |    2 arg: times path
        |    3 arg: inv. order path
        |    4 arg: result output
        |""".trimMargin()
    }

    val openXlResults = cleanOpenXl(args[0])
    val header = openXlResults.first() + "${OPEN_XL_SEPARATOR}time"
    val times = readTimes(args[1])
    val mappings = prepareMappings(args[2])
    val results = mergeOpenXlWithTimes(openXlResults, times, mappings)
    writeLinesToFile(args[3], listOf(header) + results)
}

private fun cleanOpenXl(fileName: String) = readFileLines(fileName)
        .filter { it.startsWith("multiply") or it.startsWith("Function") }
        .map { it.replace("(void)", "") }
        .map { it.replace("${it.split(OPEN_XL_SEPARATOR)[1]}$OPEN_XL_SEPARATOR", "") }
        .map { it.replace("multiply_matrices_", "") }
        .toList()

const val TIMES_HEADER = "Czas wykonania programu:"

private fun readTimes(fileName: String) = readFileLines(fileName)
        .filter { it.startsWith(TIMES_HEADER) }
        .map {
            it.substringAfter(TIMES_HEADER)
                    .substringBefore("sec")
                    .trim { it == ' ' }
        }
        .map { it.toBigDecimal() } //just for safety

private fun prepareMappings(fileName: String) = readFileLines(fileName)
        .map { it.substringAfter("multiply_matrices_").substringBefore(",") }

private fun readFileLines(fileName: String) = File(fileName)
        .inputStream().bufferedReader().useLines { it.toList() }

private fun mergeOpenXlWithTimes(openXlLines: List<String>, times: List<BigDecimal>, mapping: List<String>): List<String> {
    require(times.size % mapping.size == 0) {
        "No stary, czasy sie wysypały... pomiarów ${times.size} a funkcji ${mapping.size}" // hyhy. too late.
    }
    val size = BigDecimal(times.size)
    val mergedTimes = times.chunked(mapping.size)
            .reduce { list, acc -> list.zip(acc) { a, b -> a + b } }
            .map { it / size }
            .map { it.toEngineeringString() }
    val functions = openXlLines.drop(1)
            .map { it.split(OPEN_XL_SEPARATOR) }
            .groupBy { it.first() }

    return mapping
            .filter { functions.containsKey(it) }
            .map { "$it$OPEN_XL_SEPARATOR${functions[it]!![0].drop(1).joinToString(OPEN_XL_SEPARATOR)}" }
            .zip(mergedTimes)
            .map { "${it.first}$OPEN_XL_SEPARATOR${it.second}" }
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