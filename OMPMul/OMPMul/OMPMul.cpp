

#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "omp.h"

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


void reset_result_matrix()
{
#pragma omp parallel for
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			matrix_r[i][j] = 0.0;
}

void initialize_matrices()
{
#pragma omp parallel for
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			matrix_a[i][j] = (float)rand() / RAND_MAX;
			matrix_b[i][j] = (float)rand() / RAND_MAX;
		}
	}
}

void multiply_matrices_ijk()
{
#pragma omp parallel for
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			float sum = 0.0;
			for (int k = 0; k < COLUMNS; k++)
			{
				sum += matrix_a[i][k] * matrix_b[k][j];
			}
			matrix_r[i][j] = sum;
		}
	}
}

void multiply_matrices_ijk_ikj()
{
#pragma omp parallel for
	for (int i = 0; i < ROWS; i += R)
		for (int j = 0; j < COLUMNS; j += R)
			for (int k = 0; k < COLUMNS; k += R)
				for (int ii = i; ii < i + R; ii++)
					for (int kk = k; kk < k + R; kk++)
						for (int jj = j; jj < j + R; jj++)
							matrix_r[ii][jj] += matrix_a[ii][kk] * matrix_b[kk][jj];
}

void multiply_matrices_ikj()
{
	for (int i = 0; i < ROWS; i++)
		for (int k = 0; k < COLUMNS; k++)
			for (int j = 0; j < COLUMNS; j++)
				matrix_r[i][j] += matrix_a[i][k] * matrix_b[k][j];
}


void measure_invocation(void (*f)())
{
	const auto start = (double)clock() / CLK_TCK;
	f();
	const auto end = (double)clock() / CLK_TCK;
	const auto resolution = 1.0 / CLK_TCK;
	printf("Czas: %8.4f sec \n", end - start);
	float sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			sum += matrix_r[i][j];
	fprintf(result_file,
	        "Czas wykonania programu: %8.4f sec (%6.4f sec rozdzielczosc pomiaru)\n",
	        end - start, resolution);
	printf("wynik: %f\n", sum);
}

void measure_invocation(const char* title, void (*f)())
{
	reset_result_matrix();
	printf("%s: ", title);
	measure_invocation(f);
}

int main()
{
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

	initialize_matrices();

	measure_invocation("SEQ IKJ", multiply_matrices_ikj);
	measure_invocation("IJK", multiply_matrices_ijk);
	measure_invocation("IKJ", multiply_matrices_ijk_ikj);

	fclose(result_file);

	return (0);
}
