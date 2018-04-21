#pragma once

using namespace std;

class Runner
{
public:
	//Runner(string output_filename);
	~Runner();

private:
	//void RunExperiment(Experiment experiment);
	void Run3Loops();
	void Run6Loops();

	typedef void(*metoda)();
	int n;
	int r;
	FILE* result_file;
	//Experiment experiment;
	float *matrix;
};

