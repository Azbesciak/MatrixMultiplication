#pragma once
class Experiment
{
public:
	int n;
	int r;
	double result;
	bool parallel;
	float **matrix;
	void CreateMatrix(int n);
	~Experiment();
private:
	void DeleteMatrix();
	void CleanMatrix();
};

