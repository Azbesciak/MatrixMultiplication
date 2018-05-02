import java.io.File

private const val rootPath = "./src/main/resources/merge/%s.txt"
fun main(args: Array<String>) {
    val codeXl = getFileLines("resultsCodeXL", "\t")
    val vtune = getFileLines("resultsVtune", ",")
    val merged = vtune.second.mapValues {
        codeXl.second[it.key].let { code ->
            if (code != null) code + it.value else emptyList()
        }
    }
            .filterValues { it.isNotEmpty() }
    val result = listOf("function," + codeXl.first.joinToString(",") + "," + vtune.first.joinToString(",")) +
            merged.toList()
                    .sortedByDescending {
                        val indexOfFirstNumber = it.first.indexOfFirst { it in '1'..'9' }
                        val key = it.first.take(indexOfFirstNumber)
                        val values = it.first.drop(indexOfFirstNumber).split("_").map { it.toInt() }
                        Entr(key, values)
                    }
                    .map { "${it.first},${it.second.joinToString(",")}" }
    writeLinesToFile(String.format(rootPath, "mergedResult"), result)
}

class Entr(val key: String, val values: List<Int>) : Comparable<Entr> {
    override fun compareTo(other: Entr): Int {
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

private fun readFileLines(fileName: String) = File(fileName)
        .inputStream().bufferedReader().useLines { it.toList() }

private fun getFileLines(fileName: String, separator: String): Pair<List<String>, Map<String, List<String>>> {
    val allLines = readFileLines(String.format(rootPath, fileName))
            .map { it.split(separator) }
    val header = allLines.first().drop(1)
    return header to allLines
            .drop(1)
            .groupBy { it.first() }
            .mapValues { it.value.first().drop(1) }
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