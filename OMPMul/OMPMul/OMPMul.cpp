

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Trash.h"
#include "omp.h"

#define USE_MULTIPLE_THREADS true
#define MAXTHREADS 128
int NumThreads;


FILE* result_file;

void measure_invocation(mul_fun fun, Experiment *experiment)
{
	const auto start = (double)clock() / CLK_TCK;
	fun();
	const auto end = (double)clock() / CLK_TCK;
	const auto resolution = 1.0 / CLK_TCK;
	printf("%8.4f \n", end - start);
	double result = 0;
#if CALC_RESULT
	for (int r = 0; r < experiment->n; r++) {
		for (int c = 0; c < experiment->n; c++) {
			result += experiment->matrix[r][c];
		}
	}
#endif

	fprintf(result_file, "%s;%d;%d;%d;%f;%8.4f\n",
		experiment->name,
		experiment->n,
		experiment->r,
		experiment->parallel,
		result,
		end - start);

	fflush(result_file);
}
void measure(timer_fun fun);


int main()
{
	if ((result_file = fopen("results_classic.csv", "w")) == NULL)
	{
		fprintf(stderr, "Nie mozna otworzyc pliku wyniku \n");
		perror("Classic version - file opening error");
		return (EXIT_FAILURE);
	}

	//Determine the number of threads to use
	if (USE_MULTIPLE_THREADS)
	{
		SYSTEM_INFO SysInfo;
		GetSystemInfo(&SysInfo);
		NumThreads = SysInfo.dwNumberOfProcessors;
		if (NumThreads > MAXTHREADS)
			NumThreads = MAXTHREADS;
	}
	else
		NumThreads = 1;

	fprintf(result_file, "Liczba watkow %d \n", NumThreads);
	fprintf(result_file, "name;n;r;parallel;time;result;loops_no\n");
	printf("liczba watkow  = %d\n\n", NumThreads);


	for (int i = 0; i < 10; i++) {
		measure(measure_invocation);
	}
	fclose(result_file);

	return (0);
}

