#include "stdafx.h"
#include "Runner.h"
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Experiment.h"
using namespace std;

//Runner::Runner(string output_filename)
//{
//	result_file = fopen(output_filename.c_str(), "a");
//}


void Runner::Run3Loops()
{
//#pragma omp parallel for if experiment.parallel
//	for (int i = 0; i < experiment.n; i++) {
//		for (int j = 0; j < experiment.n; j++) {
//			float sum = 0.0;
//			for (int k = 0; k < experiment.n; k++) {
//				sum += experiment.matrix[i][k] * experiment.matrix[k][j];
//			}
//			experiment.matrix[i][j] = sum;
//		}
//	}
}

void Runner::Run6Loops()
{
//#pragma omp parallel for if experiment.parallel
	//for (int i = 0; i < experiment.n; i += experiment.r)
	//	for (int j = 0; j < experiment.n; j += experiment.r)
	//		for (int k = 0; k < experiment.n; k += experiment.r)
	//			for (int ii = i; ii < i + experiment.r; ii++)
	//				for (int kk = k; kk < k + experiment.r; kk++)
	//					for (int jj = j; jj < j + experiment.r; jj++)
	//						experiment.matrix[ii][jj] += experiment.matrix[ii][kk] * experiment.matrix[kk][jj];
}

