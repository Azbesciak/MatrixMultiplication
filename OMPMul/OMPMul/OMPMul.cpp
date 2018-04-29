

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Trash.h"
#include "omp.h"

#define USE_MULTIPLE_THREADS true
#define MAXTHREADS 4
int NumThreads;


FILE* result_file;



void measure_invocation(void (*f)(), InvData data)
{
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
		omp_set_num_threads(8);
		NumThreads = SysInfo.dwNumberOfProcessors;
		if (NumThreads > MAXTHREADS)
			NumThreads = MAXTHREADS;
	}
	else
		NumThreads = 1;
	omp_set_num_threads(4);
	
	fprintf(result_file, "Liczba watkow %d\n", MAXTHREADS);
	fprintf(result_file, "name;n;r;time\n");
	printf("liczba watkow  = %d\n\n", MAXTHREADS);
		
	for (int i = 0; i < 10; i++) {
		measure(measure_invocation);
	}
	fclose(result_file);

	return (0);
}

