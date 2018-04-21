#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Trash.h"
#include "omp.h"
#include "Experiment.h"
#include "Runner.h"

#define CALC_RESULTS 1
#define USE_MULTIPLE_THREADS true
#define MAXTHREADS 128
int NumThreads;

static const int ROWS = 1000; // liczba wierszy macierzy
static const int COLUMNS = 1000; // lizba kolumn macierzy
static const int R = 50;

float matrix_a[ROWS][COLUMNS]; // lewy operand 
float matrix_b[ROWS][COLUMNS]; // prawy operand
float matrix_r[ROWS][COLUMNS]; // wynik

FILE* result_file;

void measure_invocation(void (*f)())
{
	const auto start = (double)clock() / CLK_TCK;
	f();
	const auto end = (double)clock() / CLK_TCK;
	const auto resolution = 1.0 / CLK_TCK;
	printf("%8.4f \n", end - start);
	fprintf(result_file,
	        "Czas wykonania programu: %8.4f sec (%6.4f sec rozdzielczosc pomiaru)\n",
	        end - start, resolution);
}

void measure(void(*f)(void(*ff)()));


int main()
{
	Experiment experiment(100, 10, false, true);

	Runner runner("todays_results.txt");
	runner.SetExperiment(experiment);
	runner.RunExperiment();
	


	if ((result_file = fopen("results_classic.txt", "a")) == NULL)
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
	fprintf(result_file, "Klasyczny algorytm mnozenia macierzy, liczba watkow %d \n", NumThreads);
	printf("liczba watkow  = %d\n\n", NumThreads);

	
	for (int i = 0; i < 10; i++) {
		measure(measure_invocation);
	}
	fclose(result_file);

	return (0);
}

