import java.io.File
const val MEASURE_HEADER = "void measure(void(*measure_invocation)(void(*ff)()))"

fun main(args: Array<String>) {


    val generated = generateTrashCpp()

    File("somefile.txt").printWriter().use { out ->
        generated.forEach {
            out.println(it)
        }
    }
}

fun generateTrashCpp() =
    listOf("#include \"stdafx.h\"\n" +
            "#include \"Trash.h\"\n" +
            "#include <stdio.h>\n" +
            "#include <time.h>\n" +
            "#include <cstdlib>") +
            generateMatrixes() +
            generateFunction() +
            listOf("""$MEASURE_HEADER {
            |      ${generateInvocations().joinToString("\n\t")}
            |}""".trimMargin())

fun <T> generateInRange(f: (i : Int) -> T)= IntProgression.fromClosedRange(50, 1500, 50).map(f)
fun <T> generateSubranges(max: Int, f: (i: Int) -> T) = IntProgression.fromClosedRange(50, max, 1)
        .filter { max % it == 0 }.map(f)
fun generateMatrixes(): List<String> = generateInRange {
    """
        float matrix_a_$it[$it][$it];
        float matrix_b_$it[$it][$it];
        float matrix_r_$it[$it][$it];

    """.trimIndent()
}

fun generateCleaners() = generateInRange {
    """
    void clean_$it()
    {
    #pragma omp parallel for
        for (int i = 0; i < $it; i++)
            for (int j = 0; j < $it; j++)
            {
                matrix_r_$it[i][j] = 0.0;
                matrix_a_$it[i][j] = (float)rand() / RAND_MAX;
                matrix_b_$it[i][j] = (float)rand() / RAND_MAX;
            }
    }
    """.trimIndent()
}

fun generateHeaders(): List<String> {
    return listOf("$MEASURE_HEADER;") +
            generateInRange {
                """void clean_$it();
        |void measure_invocation_$it(const char* title, void(*f)(), void(*callback)(void(*ff)()));
    """.trimMargin()
            }
}

fun generateInvocations(): List<String> {
    val res = generateInRange {
        """measure_invocation_$it("SEQ_IKJ $it", multiply_matrices_ikj_$it, measure_invocation);
          |measure_invocation_$it("IJK $it", multiply_matrices_ijk_$it, measure_invocation);""".trimMargin()
    }

    val res3 = IntProgression.fromClosedRange(50, 1500, 50).flatMap { n ->
        generateSubranges(n) { r ->
            """measure_invocation_$n("IJK_IKJ ${n}_$r", multiply_matrices_ijk_ikj_${n}_$r, measure_invocation);"""
        }
    }

    return res + res3
}

fun generateFunction(): List<String> {
    val threeLines = generateInRange {
        """

            void measure_invocation_$it(const char* title, void(*f)(), void(*callback)(void(*ff)()))
            {
                clean_$it();
                printf("%s: ", title);
                callback(f);
            }
            void clean_$it()
            {
            #pragma omp parallel for
                for (int i = 0; i < $it; i++)
                    for (int j = 0; j < $it; j++)
                    {
                        matrix_r_$it[i][j] = 0.0;
                        matrix_a_$it[i][j] = (float)rand() / RAND_MAX;
                        matrix_b_$it[i][j] = (float)rand() / RAND_MAX;
                    }
            }
            void multiply_matrices_ikj_$it()
            {
                for (int i = 0; i < $it; i++)
                    for (int k = 0; k < $it; k++)
                        for (int j = 0; j < $it; j++)
                            matrix_r_$it[i][j] += matrix_a_$it[i][k] * matrix_b_$it[k][j];
            }

            void multiply_matrices_ijk_$it()
            {
            #pragma omp parallel for
                for (int i = 0; i < $it; i++)
                {
                    for (int j = 0; j < $it; j++)
                    {
                        float sum = 0.0;
                        for (int k = 0; k < $it; k++)
                        {
                            sum += matrix_a_$it[i][k] * matrix_b_$it[k][j];
                        }
                        matrix_r_$it[i][j] = sum;
                    }
                }
            }
        """.trimIndent()
    }
    val sixlines = IntProgression.fromClosedRange(50, 1500, 50).flatMap { n ->
        generateSubranges(n) { r ->
            """
            void multiply_matrices_ijk_ikj_${n}_$r()
            {
            #pragma omp parallel for
                for (int i = 0; i < $n; i += $r)
                    for (int j = 0; j < $n; j += $r)
                        for (int k = 0; k < $n; k += $r)
                            for (int ii = i; ii < i + $r; ii++)
                                for (int kk = k; kk < k + $r; kk++)
                                    for (int jj = j; jj < j + $r; jj++)
                                        matrix_r_$n[ii][jj] += matrix_a_$n[ii][kk] * matrix_b_$n[kk][jj];
            }
            """.trimIndent()

        }
    }
    return threeLines + sixlines

}

fun generateInvHeadersOnly(): List<String> {
    val threeLines = generateInRange {
        """
            void multiply_matrices_ikj_$it();
            void multiply_matrices_ijk_$it();
        """.trimIndent()
    }
    val sixlines = IntProgression.fromClosedRange(50, 1500, 50).flatMap { n ->
        generateSubranges(n) { r ->
            """
            void multiply_matrices_ijk_ikj_${n}_$r();
            """.trimIndent()

        }
    }
    return threeLines + sixlines
}