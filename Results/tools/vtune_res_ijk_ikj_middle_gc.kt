import java.io.File

private const val VTUNE_SEPARATOR = ","


fun main(args: Array<String>) {
    require(args.size == 2) {
        """|
        |Usage:
        |    1 arg: source path
        |    2 arg: result output
        |""".trimMargin()
    }

    val vtuneResults = vtuneFile(args[0])
    writeLinesToFile(args[1], vtuneResults)
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


private fun vtuneFile(fileName: String): List<String> {
    val lines = readFileLines(fileName)
    val headers = lines.first().split(VTUNE_SEPARATOR)
    val body = lines.drop(1).map { headers.zip(it.split(VTUNE_SEPARATOR)).toMap()}
            .filter { it["type"] != "ijk" }
            .groupBy { it["n"] }
            .flatMap { it.value.let {
                val ikj = it.find { it["type"] == "ikj" }
                val sorted = it.filter { it["type"] == "ijk_ikj" }
                        .sortedBy { it["time_avg"]!!.toBigDecimal() }
                listOf(sorted.first(), sorted.last(), ikj)
            } }
            .map { v -> headers.map { h ->  v!![h]}}

    return (listOf(headers) + body).map { it.joinToString(VTUNE_SEPARATOR) }

}

private fun readFileLines(fileName: String) = File(fileName)
        .inputStream().bufferedReader().useLines { it.toList() }
