
#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "omp.h"

#define USE_MULTIPLE_THREADS true
#define MAXTHREADS 128
int NumThreads;

static const int ROWS = 1000;     // liczba wierszy macierzy
static const int COLUMNS = 1000;  // lizba kolumn macierzy

float matrix_a[ROWS][COLUMNS];    // lewy operand 
float matrix_b[ROWS][COLUMNS];    // prawy operand
float matrix_r[ROWS][COLUMNS];    // wynik

FILE *result_file;


void reset_result_matrix()
{
	// zdefiniowanie zawarosci poczatkowej macierzy
#pragma omp parallel for 
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			matrix_r[i][j] = 0.0;
		}
	}
}

void initialize_matrices()
{
	// zdefiniowanie zawarosci poczatkowej macierzy
	//#pragma omp parallel for 
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			matrix_a[i][j] = (float)rand() / RAND_MAX;
			matrix_b[i][j] = (float)rand() / RAND_MAX;
		}
	}
}

void print_result()
{
	// wydruk wyniku
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			fprintf(result_file, "%6.4f ", matrix_r[i][j]);
		}
		fprintf(result_file, "\n");
	}
}

void multiply_matrices_IJK()
{
#pragma omp parallel for 
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			float sum = 0.0;
			for (int k = 0; k < COLUMNS; k++) {
				sum = sum + matrix_a[i][k] * matrix_b[k][j];
			}
			matrix_r[i][j] = sum;
		}
	}
}

void multiply_matrices_IKJ()
{
#pragma omp parallel for 
	for (int i = 0; i < ROWS; i++)
		for (int k = 0; k < COLUMNS; k++)
			for (int j = 0; j < COLUMNS; j++)
				matrix_r[i][j] += matrix_a[i][k] * matrix_b[k][j];

}

void measure_invocation(void(*f)())
{
	const auto start = (double)clock() / CLK_TCK;
	f();
	const auto elapsed = (double)clock() / CLK_TCK;
	const auto resolution = 1.0 / CLK_TCK;
	printf("Czas: %8.4f sec \n", elapsed - start);

	fprintf(result_file,
		"Czas wykonania programu: %8.4f sec (%6.4f sec rozdzielczosc pomiaru)\n",
		elapsed - start, resolution);
}

void measure_invocation(const char * title, void(*f)())
{
	reset_result_matrix();
	printf(title);
	measure_invocation(f);
}

int main()
{
	if ((result_file = fopen("classic.txt", "a")) == NULL) {
		fprintf(stderr, "nie mozna otworzyc pliku wyniku \n");
		perror("classic");
		return(EXIT_FAILURE);
	}

	//Determine the number of threads to use
	if (USE_MULTIPLE_THREADS) {
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

	measure_invocation("IJK", multiply_matrices_IJK);
	measure_invocation("IKJ", multiply_matrices_IKJ);

	fclose(result_file);

	return(0);
}
