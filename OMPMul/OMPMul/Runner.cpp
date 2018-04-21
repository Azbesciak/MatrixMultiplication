#include "stdafx.h"
#include "Runner.h"
#include <time.h>
using namespace std;

Runner::Runner(string output_filename, int threads_num)
{
	this->max_threads_num = threads_num;
	result_file = fopen(output_filename.c_str(), "w");
	fprintf(result_file, "n;r;parallel?;result;3loops?\n");
}
Runner::~Runner()
{
#if CALC_RESULTS
	fprintf(result_file,"Saving results true\n");
#else
	fprintf(result_file, "Not saving\n");
#endif
	fclose(result_file);
}


void Runner::RunExperiment()
{
	experiment->Reset();

	Experiment_fun function = experiment->threeLoops ? &Runner::Run3Loops : &Runner::Run6Loops;
	//function = this->Run3Loops;//
	
	Timer(experiment->threeLoops ? &Runner::Run3Loops : &Runner::Run6Loops);
	CommitExperimentResults();
}

void Runner::SetExperiment(Experiment *experiment)
{
	this->experiment = experiment;
}

void Runner::Run3Loops()
{
#pragma omp parallel for if experiment->parallel
	for (int i = 0; i < experiment->n; i++) {
		for (int j = 0; j < experiment->n; j++) {
			float sum = 0.0;
			for (int k = 0; k < experiment->n; k++) {
				sum += experiment->matrix_a[i][k] * experiment->matrix_b[k][j];
			}
			experiment->matrix_r[i][j] = sum;
		}
	}
}

void Runner::Run6Loops()
{
#pragma omp parallel for if experiment->parallel
	for (int i = 0; i < experiment->n; i += experiment->r)
		for (int j = 0; j < experiment->n; j += experiment->r)
			for (int k = 0; k < experiment->n; k += experiment->r)
				for (int ii = i; ii < i + experiment->r; ii++)
					for (int kk = k; kk < k + experiment->r; kk++)
						for (int jj = j; jj < j + experiment->r; jj++)
							experiment->matrix_r[ii][jj] += experiment->matrix_a[ii][kk] * experiment->matrix_b[kk][jj];

						
}

void Runner::Timer(Experiment_fun fun)
{
	const auto start = (double)clock() / CLK_TCK;
	(this->*fun)();
	const auto end = (double)clock() / CLK_TCK;

#if CALC_RESULTS
	for (int i = 0; i < experiment->n; i++) {
		for (int j = 0; j < experiment->n; j++) {
			experiment->result += experiment->matrix_r[i][j];
		}
	}
#endif
		const auto resolution = 1.0 / CLK_TCK;
		experiment->time = end - start;

}

void Runner::CommitExperimentResults()
{
	fprintf(result_file , "%d;%d;%d;%f;%d,%f\n" ,
		experiment->n,
		experiment->r,
		experiment->parallel,
		experiment->result,
		experiment->threeLoops,
		experiment->time);

	fflush(result_file);
}

