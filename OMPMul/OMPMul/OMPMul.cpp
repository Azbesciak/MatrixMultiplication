#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "Trash.h"
#include "omp.h"
#include "Experiment.h"
#include "Runner.h"

int get_max_threads_num();

int main()
{
	Experiment experiment(100, 5, false, true);

	Runner runner("todays_results.txt", get_max_threads_num());
	runner.SetExperiment(&experiment);
	runner.RunExperiment();
	experiment.parallel = false;
	runner.RunExperiment();

	return (0);
}

int get_max_threads_num() {
	//Determine the number of threads to use
	if (USE_MULTIPLE_THREADS)
	{
		SYSTEM_INFO SysInfo;
		GetSystemInfo(&SysInfo);
		return SysInfo.dwNumberOfProcessors;
	}
	return 1;
}

