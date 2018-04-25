import java.io.File

fun main(args: Array<String>) {
    require(args.size == 2) {
        """|
        |Usage:
        |    1 arg: source path
        |    2 arg: result output
        |""".trimMargin()
    }

    val lines = File(args[0]).inputStream().bufferedReader().useLines { lines ->
        lines.filter { it.startsWith("multiply") or it.startsWith("Function") }
                .map { it.replace("(void)", "") }
                .map { it.replace("${it.split("\t")[1]}\t", "") }
                .toList()
    }

    File(args[1]).apply {
        parentFile.mkdirs()
        createNewFile()
        bufferedWriter().use { writer ->
            lines.forEach {
                writer.write(it)
                writer.newLine()
            }
        }
    }
}