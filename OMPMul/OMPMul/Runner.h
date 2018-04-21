#pragma once
#include "Experiment.h"
using namespace std;

class Runner
{
	typedef void(Runner::*Experiment_fun)();
public:
	void (Runner::*fun)() const = NULL;

	Runner(string output_filename, int threads_num);
	~Runner();

	void RunExperiment();
	void SetExperiment(Experiment *experiment);
private:
	Runner() {};
	void Run3Loops();
	void Run6Loops();
	void Timer(Experiment_fun fun);
	void CommitExperimentResults();
	FILE* result_file;
	Experiment *experiment;
	unsigned int max_threads_num;
	float *matrix;
};

