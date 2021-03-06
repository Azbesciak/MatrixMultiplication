// stdafx.h: dołącz plik do standardowych systemowych plików dołączanych,
// lub specyficzne dla projektu pliki dołączane, które są często wykorzystywane, ale
// są rzadko zmieniane
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>

#define CALC_RESULT true
#define MAX_R 1500
#define MAX_C 1500
using namespace std;

struct Experiment {
	float **matrix;
	int n;
	int r;
	bool parallel;
	const char* name;
};

typedef void(*mul_fun)();
typedef void(*timer_fun)(mul_fun fun, Experiment *experiment);




// TODO: W tym miejscu odwołaj się do dodatkowych nagłówków wymaganych przez program
