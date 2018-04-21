#pragma once
class Experiment
{
public:
	int n;
	int r;
	bool threeLoops;
	double result;
	bool parallel;
	float **matrix_a;
	float **matrix_b;
	float **matrix_r;
	double time;
	void CreateMatrix(int n);
	void ResetResultMatrix();
	void Reset();
	Experiment() {};
	Experiment(int n, int r, bool threeLoops, bool parallel) : n(n), r(r), threeLoops(threeLoops), parallel(parallel) { CreateMatrix(n); };
	~Experiment();
private:
	void DeleteMatrices();
	void CleanMatrices();
};

