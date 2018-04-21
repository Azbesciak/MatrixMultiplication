#include "stdafx.h"
#include <string.h>
#include "Experiment.h"

void Experiment::CreateMatrix(int n)
{
	DeleteMatrices();

	this->n = n;
	matrix_a = new float*[this->n];
	for (int i = 0; i < this->n; i++) {
		matrix_a[i] = new float[this->n];

	}
	matrix_b = new float*[this->n];
	for (int i = 0; i < this->n; i++) {
		matrix_b[i] = new float[this->n];

	}
	matrix_r = new float*[this->n];
	for (int i = 0; i < this->n; i++) {
		matrix_r[i] = new float[this->n];

	}

	CleanMatrices();

}

void Experiment::ResetResultMatrix()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix_r[i][j] = 0;
		}
	}
}

void Experiment::Reset()
{
	ResetResultMatrix();
	result = 0;
	time = 0;
}

Experiment::~Experiment()
{
	DeleteMatrices();
}

void Experiment::DeleteMatrices()
{
	if (matrix_a == NULL)
		return;
	for (int i = 0; i < this->n; i++) {
		delete[] matrix_a[i];
		delete[] matrix_b[i];
		delete[] matrix_r[i];
	}
	delete[] matrix_a;
	delete[] matrix_b;
	delete[] matrix_r;
}

void Experiment::CleanMatrices()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix_a[i][j] = (float)rand() / RAND_MAX;
			matrix_b[i][j] = (float)rand() / RAND_MAX;
		}
	}
	//memset(matrix, 0, sizeof(float)*n*n);
}
