

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Trash.h"
#include "omp.h"

#define USE_MULTIPLE_THREADS true
#define MAXTHREADS 4
#define ITERATIONS 30
int NumThreads;

FILE* result_file;

void clean()
{
	const int size = 20 * 1024 * 1024; // Allocate 20M. Set much larger then L2
	char *c = (char *)malloc(size);
	for (int j = 0; j < size; j++)
		c[j] = 0xffff * j;
	free(c);
}

void measure_invocation(void (*f)(), InvData data)
{
	clean();
	const auto start = (double)clock() / CLK_TCK;
	f();
	const auto end = (double)clock() / CLK_TCK;
	const auto resolution = 1.0 / CLK_TCK;
	printf("%s %8.4f\n", data.name,end - start);
	fprintf(result_file, "%s;%d;%d;%8.4f\n",
			data.name,
			data.n,
			data.r,
			end - start);
	fflush(result_file);
}

int main()
{
	if ((result_file = fopen("times_results.csv", "w")) == NULL)
	{
		fprintf(stderr, "Nie mozna otworzyc pliku wyniku \n");
		perror("Classic version - file opening error");
		return (EXIT_FAILURE);
	}

	omp_set_num_threads(MAXTHREADS);
	fprintf(result_file, "Liczba watkow %d\n", MAXTHREADS);
	fprintf(result_file, "name;n;r;time\n");
	printf("liczba watkow  = %d\n\n", MAXTHREADS);
		
	for (int i = 0; i < ITERATIONS; i++) {
		measure(measure_invocation);
	}
	fclose(result_file);

	return (0);
}

