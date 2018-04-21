#include "stdafx.h"
#include "Experiment.h"

void Experiment::CreateMatrix(int n)
{
	matrix = new float*[n];
	for (int i = 0; i < this->n; i++) {
		matrix[i] = new float[n];
	}
	CleanMatrix();
}

Experiment::~Experiment()
{
	DeleteMatrix();
}

void Experiment::DeleteMatrix()
{
	for (int i = 0; i < this->n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Experiment::CleanMatrix()
{
	memset(matrix, 0, sizeof(matrix[0][0])*n*n);
}
