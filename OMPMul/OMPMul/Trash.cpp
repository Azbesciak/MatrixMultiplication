#include "stdafx.h"
#include "Trash.h"
#include <stdio.h>
#include <time.h>
#include <cstdlib>
float matrix_a_50[50][50];
float matrix_b_50[50][50];
float matrix_r_50[50][50];

float matrix_a_100[100][100];
float matrix_b_100[100][100];
float matrix_r_100[100][100];

float matrix_a_150[150][150];
float matrix_b_150[150][150];
float matrix_r_150[150][150];

float matrix_a_200[200][200];
float matrix_b_200[200][200];
float matrix_r_200[200][200];

float matrix_a_250[250][250];
float matrix_b_250[250][250];
float matrix_r_250[250][250];

float matrix_a_300[300][300];
float matrix_b_300[300][300];
float matrix_r_300[300][300];

float matrix_a_350[350][350];
float matrix_b_350[350][350];
float matrix_r_350[350][350];

float matrix_a_400[400][400];
float matrix_b_400[400][400];
float matrix_r_400[400][400];

float matrix_a_450[450][450];
float matrix_b_450[450][450];
float matrix_r_450[450][450];

float matrix_a_500[500][500];
float matrix_b_500[500][500];
float matrix_r_500[500][500];

float matrix_a_550[550][550];
float matrix_b_550[550][550];
float matrix_r_550[550][550];

float matrix_a_600[600][600];
float matrix_b_600[600][600];
float matrix_r_600[600][600];

float matrix_a_650[650][650];
float matrix_b_650[650][650];
float matrix_r_650[650][650];

float matrix_a_700[700][700];
float matrix_b_700[700][700];
float matrix_r_700[700][700];

float matrix_a_750[750][750];
float matrix_b_750[750][750];
float matrix_r_750[750][750];

float matrix_a_800[800][800];
float matrix_b_800[800][800];
float matrix_r_800[800][800];

float matrix_a_850[850][850];
float matrix_b_850[850][850];
float matrix_r_850[850][850];

float matrix_a_900[900][900];
float matrix_b_900[900][900];
float matrix_r_900[900][900];

float matrix_a_950[950][950];
float matrix_b_950[950][950];
float matrix_r_950[950][950];

float matrix_a_1000[1000][1000];
float matrix_b_1000[1000][1000];
float matrix_r_1000[1000][1000];

float matrix_a_1050[1050][1050];
float matrix_b_1050[1050][1050];
float matrix_r_1050[1050][1050];

float matrix_a_1100[1100][1100];
float matrix_b_1100[1100][1100];
float matrix_r_1100[1100][1100];

float matrix_a_1150[1150][1150];
float matrix_b_1150[1150][1150];
float matrix_r_1150[1150][1150];

float matrix_a_1200[1200][1200];
float matrix_b_1200[1200][1200];
float matrix_r_1200[1200][1200];

float matrix_a_1250[1250][1250];
float matrix_b_1250[1250][1250];
float matrix_r_1250[1250][1250];

float matrix_a_1300[1300][1300];
float matrix_b_1300[1300][1300];
float matrix_r_1300[1300][1300];

float matrix_a_1350[1350][1350];
float matrix_b_1350[1350][1350];
float matrix_r_1350[1350][1350];

float matrix_a_1400[1400][1400];
float matrix_b_1400[1400][1400];
float matrix_r_1400[1400][1400];

float matrix_a_1450[1450][1450];
float matrix_b_1450[1450][1450];
float matrix_r_1450[1450][1450];

float matrix_a_1500[1500][1500];
float matrix_b_1500[1500][1500];
float matrix_r_1500[1500][1500];


void measure_invocation_50(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_50();
	printf("%s: ", title);
	callback(f);
}
void clean_50() {
	#pragma omp parallel for
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++) {
			matrix_r_50[i][j] = 0.0;
			matrix_a_50[i][j] = (float)rand() / RAND_MAX;
			matrix_b_50[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_50() {
	for (int i = 0; i < 50; i++)
		for (int k = 0; k < 50; k++)
			for (int j = 0; j < 50; j++)
				matrix_r_50[i][j] += matrix_a_50[i][k] * matrix_b_50[k][j];
}

void multiply_matrices_ijk_50() {
	#pragma omp parallel for
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			float sum = 0.0;
			for (int k = 0; k < 50; k++) {
				sum += matrix_a_50[i][k] * matrix_b_50[k][j];
			}
			matrix_r_50[i][j] = sum;
		}
	}
}

void measure_invocation_100(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_100();
	printf("%s: ", title);
	callback(f);
}
void clean_100() {
	#pragma omp parallel for
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) {
			matrix_r_100[i][j] = 0.0;
			matrix_a_100[i][j] = (float)rand() / RAND_MAX;
			matrix_b_100[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_100() {
	for (int i = 0; i < 100; i++)
		for (int k = 0; k < 100; k++)
			for (int j = 0; j < 100; j++)
				matrix_r_100[i][j] += matrix_a_100[i][k] * matrix_b_100[k][j];
}

void multiply_matrices_ijk_100() {
	#pragma omp parallel for
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			float sum = 0.0;
			for (int k = 0; k < 100; k++) {
				sum += matrix_a_100[i][k] * matrix_b_100[k][j];
			}
			matrix_r_100[i][j] = sum;
		}
	}
}

void measure_invocation_150(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_150();
	printf("%s: ", title);
	callback(f);
}
void clean_150() {
	#pragma omp parallel for
	for (int i = 0; i < 150; i++)
		for (int j = 0; j < 150; j++) {
			matrix_r_150[i][j] = 0.0;
			matrix_a_150[i][j] = (float)rand() / RAND_MAX;
			matrix_b_150[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_150() {
	for (int i = 0; i < 150; i++)
		for (int k = 0; k < 150; k++)
			for (int j = 0; j < 150; j++)
				matrix_r_150[i][j] += matrix_a_150[i][k] * matrix_b_150[k][j];
}

void multiply_matrices_ijk_150() {
	#pragma omp parallel for
	for (int i = 0; i < 150; i++) {
		for (int j = 0; j < 150; j++) {
			float sum = 0.0;
			for (int k = 0; k < 150; k++) {
				sum += matrix_a_150[i][k] * matrix_b_150[k][j];
			}
			matrix_r_150[i][j] = sum;
		}
	}
}

void measure_invocation_200(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_200();
	printf("%s: ", title);
	callback(f);
}
void clean_200() {
	#pragma omp parallel for
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++) {
			matrix_r_200[i][j] = 0.0;
			matrix_a_200[i][j] = (float)rand() / RAND_MAX;
			matrix_b_200[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_200() {
	for (int i = 0; i < 200; i++)
		for (int k = 0; k < 200; k++)
			for (int j = 0; j < 200; j++)
				matrix_r_200[i][j] += matrix_a_200[i][k] * matrix_b_200[k][j];
}

void multiply_matrices_ijk_200() {
	#pragma omp parallel for
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			float sum = 0.0;
			for (int k = 0; k < 200; k++) {
				sum += matrix_a_200[i][k] * matrix_b_200[k][j];
			}
			matrix_r_200[i][j] = sum;
		}
	}
}

void measure_invocation_250(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_250();
	printf("%s: ", title);
	callback(f);
}
void clean_250() {
	#pragma omp parallel for
	for (int i = 0; i < 250; i++)
		for (int j = 0; j < 250; j++) {
			matrix_r_250[i][j] = 0.0;
			matrix_a_250[i][j] = (float)rand() / RAND_MAX;
			matrix_b_250[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_250() {
	for (int i = 0; i < 250; i++)
		for (int k = 0; k < 250; k++)
			for (int j = 0; j < 250; j++)
				matrix_r_250[i][j] += matrix_a_250[i][k] * matrix_b_250[k][j];
}

void multiply_matrices_ijk_250() {
	#pragma omp parallel for
	for (int i = 0; i < 250; i++) {
		for (int j = 0; j < 250; j++) {
			float sum = 0.0;
			for (int k = 0; k < 250; k++) {
				sum += matrix_a_250[i][k] * matrix_b_250[k][j];
			}
			matrix_r_250[i][j] = sum;
		}
	}
}

void measure_invocation_300(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_300();
	printf("%s: ", title);
	callback(f);
}
void clean_300() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 300; j++) {
			matrix_r_300[i][j] = 0.0;
			matrix_a_300[i][j] = (float)rand() / RAND_MAX;
			matrix_b_300[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_300() {
	for (int i = 0; i < 300; i++)
		for (int k = 0; k < 300; k++)
			for (int j = 0; j < 300; j++)
				matrix_r_300[i][j] += matrix_a_300[i][k] * matrix_b_300[k][j];
}

void multiply_matrices_ijk_300() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			float sum = 0.0;
			for (int k = 0; k < 300; k++) {
				sum += matrix_a_300[i][k] * matrix_b_300[k][j];
			}
			matrix_r_300[i][j] = sum;
		}
	}
}

void measure_invocation_350(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_350();
	printf("%s: ", title);
	callback(f);
}
void clean_350() {
	#pragma omp parallel for
	for (int i = 0; i < 350; i++)
		for (int j = 0; j < 350; j++) {
			matrix_r_350[i][j] = 0.0;
			matrix_a_350[i][j] = (float)rand() / RAND_MAX;
			matrix_b_350[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_350() {
	for (int i = 0; i < 350; i++)
		for (int k = 0; k < 350; k++)
			for (int j = 0; j < 350; j++)
				matrix_r_350[i][j] += matrix_a_350[i][k] * matrix_b_350[k][j];
}

void multiply_matrices_ijk_350() {
	#pragma omp parallel for
	for (int i = 0; i < 350; i++) {
		for (int j = 0; j < 350; j++) {
			float sum = 0.0;
			for (int k = 0; k < 350; k++) {
				sum += matrix_a_350[i][k] * matrix_b_350[k][j];
			}
			matrix_r_350[i][j] = sum;
		}
	}
}

void measure_invocation_400(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_400();
	printf("%s: ", title);
	callback(f);
}
void clean_400() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++) {
			matrix_r_400[i][j] = 0.0;
			matrix_a_400[i][j] = (float)rand() / RAND_MAX;
			matrix_b_400[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_400() {
	for (int i = 0; i < 400; i++)
		for (int k = 0; k < 400; k++)
			for (int j = 0; j < 400; j++)
				matrix_r_400[i][j] += matrix_a_400[i][k] * matrix_b_400[k][j];
}

void multiply_matrices_ijk_400() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 400; j++) {
			float sum = 0.0;
			for (int k = 0; k < 400; k++) {
				sum += matrix_a_400[i][k] * matrix_b_400[k][j];
			}
			matrix_r_400[i][j] = sum;
		}
	}
}

void measure_invocation_450(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_450();
	printf("%s: ", title);
	callback(f);
}
void clean_450() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i++)
		for (int j = 0; j < 450; j++) {
			matrix_r_450[i][j] = 0.0;
			matrix_a_450[i][j] = (float)rand() / RAND_MAX;
			matrix_b_450[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_450() {
	for (int i = 0; i < 450; i++)
		for (int k = 0; k < 450; k++)
			for (int j = 0; j < 450; j++)
				matrix_r_450[i][j] += matrix_a_450[i][k] * matrix_b_450[k][j];
}

void multiply_matrices_ijk_450() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i++) {
		for (int j = 0; j < 450; j++) {
			float sum = 0.0;
			for (int k = 0; k < 450; k++) {
				sum += matrix_a_450[i][k] * matrix_b_450[k][j];
			}
			matrix_r_450[i][j] = sum;
		}
	}
}

void measure_invocation_500(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_500();
	printf("%s: ", title);
	callback(f);
}
void clean_500() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++) {
			matrix_r_500[i][j] = 0.0;
			matrix_a_500[i][j] = (float)rand() / RAND_MAX;
			matrix_b_500[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_500() {
	for (int i = 0; i < 500; i++)
		for (int k = 0; k < 500; k++)
			for (int j = 0; j < 500; j++)
				matrix_r_500[i][j] += matrix_a_500[i][k] * matrix_b_500[k][j];
}

void multiply_matrices_ijk_500() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			float sum = 0.0;
			for (int k = 0; k < 500; k++) {
				sum += matrix_a_500[i][k] * matrix_b_500[k][j];
			}
			matrix_r_500[i][j] = sum;
		}
	}
}

void measure_invocation_550(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_550();
	printf("%s: ", title);
	callback(f);
}
void clean_550() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i++)
		for (int j = 0; j < 550; j++) {
			matrix_r_550[i][j] = 0.0;
			matrix_a_550[i][j] = (float)rand() / RAND_MAX;
			matrix_b_550[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_550() {
	for (int i = 0; i < 550; i++)
		for (int k = 0; k < 550; k++)
			for (int j = 0; j < 550; j++)
				matrix_r_550[i][j] += matrix_a_550[i][k] * matrix_b_550[k][j];
}

void multiply_matrices_ijk_550() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i++) {
		for (int j = 0; j < 550; j++) {
			float sum = 0.0;
			for (int k = 0; k < 550; k++) {
				sum += matrix_a_550[i][k] * matrix_b_550[k][j];
			}
			matrix_r_550[i][j] = sum;
		}
	}
}

void measure_invocation_600(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_600();
	printf("%s: ", title);
	callback(f);
}
void clean_600() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i++)
		for (int j = 0; j < 600; j++) {
			matrix_r_600[i][j] = 0.0;
			matrix_a_600[i][j] = (float)rand() / RAND_MAX;
			matrix_b_600[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_600() {
	for (int i = 0; i < 600; i++)
		for (int k = 0; k < 600; k++)
			for (int j = 0; j < 600; j++)
				matrix_r_600[i][j] += matrix_a_600[i][k] * matrix_b_600[k][j];
}

void multiply_matrices_ijk_600() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j < 600; j++) {
			float sum = 0.0;
			for (int k = 0; k < 600; k++) {
				sum += matrix_a_600[i][k] * matrix_b_600[k][j];
			}
			matrix_r_600[i][j] = sum;
		}
	}
}

void measure_invocation_650(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_650();
	printf("%s: ", title);
	callback(f);
}
void clean_650() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i++)
		for (int j = 0; j < 650; j++) {
			matrix_r_650[i][j] = 0.0;
			matrix_a_650[i][j] = (float)rand() / RAND_MAX;
			matrix_b_650[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_650() {
	for (int i = 0; i < 650; i++)
		for (int k = 0; k < 650; k++)
			for (int j = 0; j < 650; j++)
				matrix_r_650[i][j] += matrix_a_650[i][k] * matrix_b_650[k][j];
}

void multiply_matrices_ijk_650() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i++) {
		for (int j = 0; j < 650; j++) {
			float sum = 0.0;
			for (int k = 0; k < 650; k++) {
				sum += matrix_a_650[i][k] * matrix_b_650[k][j];
			}
			matrix_r_650[i][j] = sum;
		}
	}
}

void measure_invocation_700(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_700();
	printf("%s: ", title);
	callback(f);
}
void clean_700() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i++)
		for (int j = 0; j < 700; j++) {
			matrix_r_700[i][j] = 0.0;
			matrix_a_700[i][j] = (float)rand() / RAND_MAX;
			matrix_b_700[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_700() {
	for (int i = 0; i < 700; i++)
		for (int k = 0; k < 700; k++)
			for (int j = 0; j < 700; j++)
				matrix_r_700[i][j] += matrix_a_700[i][k] * matrix_b_700[k][j];
}

void multiply_matrices_ijk_700() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i++) {
		for (int j = 0; j < 700; j++) {
			float sum = 0.0;
			for (int k = 0; k < 700; k++) {
				sum += matrix_a_700[i][k] * matrix_b_700[k][j];
			}
			matrix_r_700[i][j] = sum;
		}
	}
}

void measure_invocation_750(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_750();
	printf("%s: ", title);
	callback(f);
}
void clean_750() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i++)
		for (int j = 0; j < 750; j++) {
			matrix_r_750[i][j] = 0.0;
			matrix_a_750[i][j] = (float)rand() / RAND_MAX;
			matrix_b_750[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_750() {
	for (int i = 0; i < 750; i++)
		for (int k = 0; k < 750; k++)
			for (int j = 0; j < 750; j++)
				matrix_r_750[i][j] += matrix_a_750[i][k] * matrix_b_750[k][j];
}

void multiply_matrices_ijk_750() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i++) {
		for (int j = 0; j < 750; j++) {
			float sum = 0.0;
			for (int k = 0; k < 750; k++) {
				sum += matrix_a_750[i][k] * matrix_b_750[k][j];
			}
			matrix_r_750[i][j] = sum;
		}
	}
}

void measure_invocation_800(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_800();
	printf("%s: ", title);
	callback(f);
}
void clean_800() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i++)
		for (int j = 0; j < 800; j++) {
			matrix_r_800[i][j] = 0.0;
			matrix_a_800[i][j] = (float)rand() / RAND_MAX;
			matrix_b_800[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_800() {
	for (int i = 0; i < 800; i++)
		for (int k = 0; k < 800; k++)
			for (int j = 0; j < 800; j++)
				matrix_r_800[i][j] += matrix_a_800[i][k] * matrix_b_800[k][j];
}

void multiply_matrices_ijk_800() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i++) {
		for (int j = 0; j < 800; j++) {
			float sum = 0.0;
			for (int k = 0; k < 800; k++) {
				sum += matrix_a_800[i][k] * matrix_b_800[k][j];
			}
			matrix_r_800[i][j] = sum;
		}
	}
}

void measure_invocation_850(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_850();
	printf("%s: ", title);
	callback(f);
}
void clean_850() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i++)
		for (int j = 0; j < 850; j++) {
			matrix_r_850[i][j] = 0.0;
			matrix_a_850[i][j] = (float)rand() / RAND_MAX;
			matrix_b_850[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_850() {
	for (int i = 0; i < 850; i++)
		for (int k = 0; k < 850; k++)
			for (int j = 0; j < 850; j++)
				matrix_r_850[i][j] += matrix_a_850[i][k] * matrix_b_850[k][j];
}

void multiply_matrices_ijk_850() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i++) {
		for (int j = 0; j < 850; j++) {
			float sum = 0.0;
			for (int k = 0; k < 850; k++) {
				sum += matrix_a_850[i][k] * matrix_b_850[k][j];
			}
			matrix_r_850[i][j] = sum;
		}
	}
}

void measure_invocation_900(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_900();
	printf("%s: ", title);
	callback(f);
}
void clean_900() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i++)
		for (int j = 0; j < 900; j++) {
			matrix_r_900[i][j] = 0.0;
			matrix_a_900[i][j] = (float)rand() / RAND_MAX;
			matrix_b_900[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_900() {
	for (int i = 0; i < 900; i++)
		for (int k = 0; k < 900; k++)
			for (int j = 0; j < 900; j++)
				matrix_r_900[i][j] += matrix_a_900[i][k] * matrix_b_900[k][j];
}

void multiply_matrices_ijk_900() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i++) {
		for (int j = 0; j < 900; j++) {
			float sum = 0.0;
			for (int k = 0; k < 900; k++) {
				sum += matrix_a_900[i][k] * matrix_b_900[k][j];
			}
			matrix_r_900[i][j] = sum;
		}
	}
}

void measure_invocation_950(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_950();
	printf("%s: ", title);
	callback(f);
}
void clean_950() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i++)
		for (int j = 0; j < 950; j++) {
			matrix_r_950[i][j] = 0.0;
			matrix_a_950[i][j] = (float)rand() / RAND_MAX;
			matrix_b_950[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_950() {
	for (int i = 0; i < 950; i++)
		for (int k = 0; k < 950; k++)
			for (int j = 0; j < 950; j++)
				matrix_r_950[i][j] += matrix_a_950[i][k] * matrix_b_950[k][j];
}

void multiply_matrices_ijk_950() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i++) {
		for (int j = 0; j < 950; j++) {
			float sum = 0.0;
			for (int k = 0; k < 950; k++) {
				sum += matrix_a_950[i][k] * matrix_b_950[k][j];
			}
			matrix_r_950[i][j] = sum;
		}
	}
}

void measure_invocation_1000(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1000();
	printf("%s: ", title);
	callback(f);
}
void clean_1000() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++) {
			matrix_r_1000[i][j] = 0.0;
			matrix_a_1000[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1000[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1000() {
	for (int i = 0; i < 1000; i++)
		for (int k = 0; k < 1000; k++)
			for (int j = 0; j < 1000; j++)
				matrix_r_1000[i][j] += matrix_a_1000[i][k] * matrix_b_1000[k][j];
}

void multiply_matrices_ijk_1000() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1000; k++) {
				sum += matrix_a_1000[i][k] * matrix_b_1000[k][j];
			}
			matrix_r_1000[i][j] = sum;
		}
	}
}

void measure_invocation_1050(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1050();
	printf("%s: ", title);
	callback(f);
}
void clean_1050() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i++)
		for (int j = 0; j < 1050; j++) {
			matrix_r_1050[i][j] = 0.0;
			matrix_a_1050[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1050[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1050() {
	for (int i = 0; i < 1050; i++)
		for (int k = 0; k < 1050; k++)
			for (int j = 0; j < 1050; j++)
				matrix_r_1050[i][j] += matrix_a_1050[i][k] * matrix_b_1050[k][j];
}

void multiply_matrices_ijk_1050() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i++) {
		for (int j = 0; j < 1050; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1050; k++) {
				sum += matrix_a_1050[i][k] * matrix_b_1050[k][j];
			}
			matrix_r_1050[i][j] = sum;
		}
	}
}

void measure_invocation_1100(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1100();
	printf("%s: ", title);
	callback(f);
}
void clean_1100() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i++)
		for (int j = 0; j < 1100; j++) {
			matrix_r_1100[i][j] = 0.0;
			matrix_a_1100[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1100[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1100() {
	for (int i = 0; i < 1100; i++)
		for (int k = 0; k < 1100; k++)
			for (int j = 0; j < 1100; j++)
				matrix_r_1100[i][j] += matrix_a_1100[i][k] * matrix_b_1100[k][j];
}

void multiply_matrices_ijk_1100() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i++) {
		for (int j = 0; j < 1100; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1100; k++) {
				sum += matrix_a_1100[i][k] * matrix_b_1100[k][j];
			}
			matrix_r_1100[i][j] = sum;
		}
	}
}

void measure_invocation_1150(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1150();
	printf("%s: ", title);
	callback(f);
}
void clean_1150() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i++)
		for (int j = 0; j < 1150; j++) {
			matrix_r_1150[i][j] = 0.0;
			matrix_a_1150[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1150[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1150() {
	for (int i = 0; i < 1150; i++)
		for (int k = 0; k < 1150; k++)
			for (int j = 0; j < 1150; j++)
				matrix_r_1150[i][j] += matrix_a_1150[i][k] * matrix_b_1150[k][j];
}

void multiply_matrices_ijk_1150() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i++) {
		for (int j = 0; j < 1150; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1150; k++) {
				sum += matrix_a_1150[i][k] * matrix_b_1150[k][j];
			}
			matrix_r_1150[i][j] = sum;
		}
	}
}

void measure_invocation_1200(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1200();
	printf("%s: ", title);
	callback(f);
}
void clean_1200() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i++)
		for (int j = 0; j < 1200; j++) {
			matrix_r_1200[i][j] = 0.0;
			matrix_a_1200[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1200[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1200() {
	for (int i = 0; i < 1200; i++)
		for (int k = 0; k < 1200; k++)
			for (int j = 0; j < 1200; j++)
				matrix_r_1200[i][j] += matrix_a_1200[i][k] * matrix_b_1200[k][j];
}

void multiply_matrices_ijk_1200() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i++) {
		for (int j = 0; j < 1200; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1200; k++) {
				sum += matrix_a_1200[i][k] * matrix_b_1200[k][j];
			}
			matrix_r_1200[i][j] = sum;
		}
	}
}

void measure_invocation_1250(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1250();
	printf("%s: ", title);
	callback(f);
}
void clean_1250() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i++)
		for (int j = 0; j < 1250; j++) {
			matrix_r_1250[i][j] = 0.0;
			matrix_a_1250[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1250[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1250() {
	for (int i = 0; i < 1250; i++)
		for (int k = 0; k < 1250; k++)
			for (int j = 0; j < 1250; j++)
				matrix_r_1250[i][j] += matrix_a_1250[i][k] * matrix_b_1250[k][j];
}

void multiply_matrices_ijk_1250() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i++) {
		for (int j = 0; j < 1250; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1250; k++) {
				sum += matrix_a_1250[i][k] * matrix_b_1250[k][j];
			}
			matrix_r_1250[i][j] = sum;
		}
	}
}

void measure_invocation_1300(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1300();
	printf("%s: ", title);
	callback(f);
}
void clean_1300() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i++)
		for (int j = 0; j < 1300; j++) {
			matrix_r_1300[i][j] = 0.0;
			matrix_a_1300[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1300[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1300() {
	for (int i = 0; i < 1300; i++)
		for (int k = 0; k < 1300; k++)
			for (int j = 0; j < 1300; j++)
				matrix_r_1300[i][j] += matrix_a_1300[i][k] * matrix_b_1300[k][j];
}

void multiply_matrices_ijk_1300() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i++) {
		for (int j = 0; j < 1300; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1300; k++) {
				sum += matrix_a_1300[i][k] * matrix_b_1300[k][j];
			}
			matrix_r_1300[i][j] = sum;
		}
	}
}

void measure_invocation_1350(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1350();
	printf("%s: ", title);
	callback(f);
}
void clean_1350() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i++)
		for (int j = 0; j < 1350; j++) {
			matrix_r_1350[i][j] = 0.0;
			matrix_a_1350[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1350[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1350() {
	for (int i = 0; i < 1350; i++)
		for (int k = 0; k < 1350; k++)
			for (int j = 0; j < 1350; j++)
				matrix_r_1350[i][j] += matrix_a_1350[i][k] * matrix_b_1350[k][j];
}

void multiply_matrices_ijk_1350() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i++) {
		for (int j = 0; j < 1350; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1350; k++) {
				sum += matrix_a_1350[i][k] * matrix_b_1350[k][j];
			}
			matrix_r_1350[i][j] = sum;
		}
	}
}

void measure_invocation_1400(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1400();
	printf("%s: ", title);
	callback(f);
}
void clean_1400() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i++)
		for (int j = 0; j < 1400; j++) {
			matrix_r_1400[i][j] = 0.0;
			matrix_a_1400[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1400[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1400() {
	for (int i = 0; i < 1400; i++)
		for (int k = 0; k < 1400; k++)
			for (int j = 0; j < 1400; j++)
				matrix_r_1400[i][j] += matrix_a_1400[i][k] * matrix_b_1400[k][j];
}

void multiply_matrices_ijk_1400() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i++) {
		for (int j = 0; j < 1400; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1400; k++) {
				sum += matrix_a_1400[i][k] * matrix_b_1400[k][j];
			}
			matrix_r_1400[i][j] = sum;
		}
	}
}

void measure_invocation_1450(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1450();
	printf("%s: ", title);
	callback(f);
}
void clean_1450() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i++)
		for (int j = 0; j < 1450; j++) {
			matrix_r_1450[i][j] = 0.0;
			matrix_a_1450[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1450[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1450() {
	for (int i = 0; i < 1450; i++)
		for (int k = 0; k < 1450; k++)
			for (int j = 0; j < 1450; j++)
				matrix_r_1450[i][j] += matrix_a_1450[i][k] * matrix_b_1450[k][j];
}

void multiply_matrices_ijk_1450() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i++) {
		for (int j = 0; j < 1450; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1450; k++) {
				sum += matrix_a_1450[i][k] * matrix_b_1450[k][j];
			}
			matrix_r_1450[i][j] = sum;
		}
	}
}

void measure_invocation_1500(const char* title, void(*f)(), void(*callback)(void(*ff)())) {
	clean_1500();
	printf("%s: ", title);
	callback(f);
}
void clean_1500() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i++)
		for (int j = 0; j < 1500; j++) {
			matrix_r_1500[i][j] = 0.0;
			matrix_a_1500[i][j] = (float)rand() / RAND_MAX;
			matrix_b_1500[i][j] = (float)rand() / RAND_MAX;
		}
}
void multiply_matrices_ikj_1500() {
	for (int i = 0; i < 1500; i++)
		for (int k = 0; k < 1500; k++)
			for (int j = 0; j < 1500; j++)
				matrix_r_1500[i][j] += matrix_a_1500[i][k] * matrix_b_1500[k][j];
}

void multiply_matrices_ijk_1500() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i++) {
		for (int j = 0; j < 1500; j++) {
			float sum = 0.0;
			for (int k = 0; k < 1500; k++) {
				sum += matrix_a_1500[i][k] * matrix_b_1500[k][j];
			}
			matrix_r_1500[i][j] = sum;
		}
	}
}
void multiply_matrices_ijk_ikj_50_50() {
	#pragma omp parallel for
	for (int i = 0; i < 50; i += 50)
		for (int j = 0; j < 50; j += 50)
			for (int k = 0; k < 50; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_50[ii][jj] += matrix_a_50[ii][kk] * matrix_b_50[kk][jj];
}
void multiply_matrices_ijk_ikj_100_50() {
	#pragma omp parallel for
	for (int i = 0; i < 100; i += 50)
		for (int j = 0; j < 100; j += 50)
			for (int k = 0; k < 100; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_100[ii][jj] += matrix_a_100[ii][kk] * matrix_b_100[kk][jj];
}
void multiply_matrices_ijk_ikj_100_100() {
	#pragma omp parallel for
	for (int i = 0; i < 100; i += 100)
		for (int j = 0; j < 100; j += 100)
			for (int k = 0; k < 100; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_100[ii][jj] += matrix_a_100[ii][kk] * matrix_b_100[kk][jj];
}
void multiply_matrices_ijk_ikj_150_50() {
	#pragma omp parallel for
	for (int i = 0; i < 150; i += 50)
		for (int j = 0; j < 150; j += 50)
			for (int k = 0; k < 150; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_150[ii][jj] += matrix_a_150[ii][kk] * matrix_b_150[kk][jj];
}
void multiply_matrices_ijk_ikj_150_75() {
	#pragma omp parallel for
	for (int i = 0; i < 150; i += 75)
		for (int j = 0; j < 150; j += 75)
			for (int k = 0; k < 150; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_150[ii][jj] += matrix_a_150[ii][kk] * matrix_b_150[kk][jj];
}
void multiply_matrices_ijk_ikj_150_150() {
	#pragma omp parallel for
	for (int i = 0; i < 150; i += 150)
		for (int j = 0; j < 150; j += 150)
			for (int k = 0; k < 150; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_150[ii][jj] += matrix_a_150[ii][kk] * matrix_b_150[kk][jj];
}
void multiply_matrices_ijk_ikj_200_50() {
	#pragma omp parallel for
	for (int i = 0; i < 200; i += 50)
		for (int j = 0; j < 200; j += 50)
			for (int k = 0; k < 200; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_200[ii][jj] += matrix_a_200[ii][kk] * matrix_b_200[kk][jj];
}
void multiply_matrices_ijk_ikj_200_100() {
	#pragma omp parallel for
	for (int i = 0; i < 200; i += 100)
		for (int j = 0; j < 200; j += 100)
			for (int k = 0; k < 200; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_200[ii][jj] += matrix_a_200[ii][kk] * matrix_b_200[kk][jj];
}
void multiply_matrices_ijk_ikj_200_200() {
	#pragma omp parallel for
	for (int i = 0; i < 200; i += 200)
		for (int j = 0; j < 200; j += 200)
			for (int k = 0; k < 200; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_200[ii][jj] += matrix_a_200[ii][kk] * matrix_b_200[kk][jj];
}
void multiply_matrices_ijk_ikj_250_50() {
	#pragma omp parallel for
	for (int i = 0; i < 250; i += 50)
		for (int j = 0; j < 250; j += 50)
			for (int k = 0; k < 250; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_250[ii][jj] += matrix_a_250[ii][kk] * matrix_b_250[kk][jj];
}
void multiply_matrices_ijk_ikj_250_125() {
	#pragma omp parallel for
	for (int i = 0; i < 250; i += 125)
		for (int j = 0; j < 250; j += 125)
			for (int k = 0; k < 250; k += 125)
				for (int ii = i; ii < i + 125; ii++)
					for (int kk = k; kk < k + 125; kk++)
						for (int jj = j; jj < j + 125; jj++)
							matrix_r_250[ii][jj] += matrix_a_250[ii][kk] * matrix_b_250[kk][jj];
}
void multiply_matrices_ijk_ikj_250_250() {
	#pragma omp parallel for
	for (int i = 0; i < 250; i += 250)
		for (int j = 0; j < 250; j += 250)
			for (int k = 0; k < 250; k += 250)
				for (int ii = i; ii < i + 250; ii++)
					for (int kk = k; kk < k + 250; kk++)
						for (int jj = j; jj < j + 250; jj++)
							matrix_r_250[ii][jj] += matrix_a_250[ii][kk] * matrix_b_250[kk][jj];
}
void multiply_matrices_ijk_ikj_300_50() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i += 50)
		for (int j = 0; j < 300; j += 50)
			for (int k = 0; k < 300; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_300[ii][jj] += matrix_a_300[ii][kk] * matrix_b_300[kk][jj];
}
void multiply_matrices_ijk_ikj_300_60() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i += 60)
		for (int j = 0; j < 300; j += 60)
			for (int k = 0; k < 300; k += 60)
				for (int ii = i; ii < i + 60; ii++)
					for (int kk = k; kk < k + 60; kk++)
						for (int jj = j; jj < j + 60; jj++)
							matrix_r_300[ii][jj] += matrix_a_300[ii][kk] * matrix_b_300[kk][jj];
}
void multiply_matrices_ijk_ikj_300_75() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i += 75)
		for (int j = 0; j < 300; j += 75)
			for (int k = 0; k < 300; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_300[ii][jj] += matrix_a_300[ii][kk] * matrix_b_300[kk][jj];
}
void multiply_matrices_ijk_ikj_300_100() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i += 100)
		for (int j = 0; j < 300; j += 100)
			for (int k = 0; k < 300; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_300[ii][jj] += matrix_a_300[ii][kk] * matrix_b_300[kk][jj];
}
void multiply_matrices_ijk_ikj_300_150() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i += 150)
		for (int j = 0; j < 300; j += 150)
			for (int k = 0; k < 300; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_300[ii][jj] += matrix_a_300[ii][kk] * matrix_b_300[kk][jj];
}
void multiply_matrices_ijk_ikj_300_300() {
	#pragma omp parallel for
	for (int i = 0; i < 300; i += 300)
		for (int j = 0; j < 300; j += 300)
			for (int k = 0; k < 300; k += 300)
				for (int ii = i; ii < i + 300; ii++)
					for (int kk = k; kk < k + 300; kk++)
						for (int jj = j; jj < j + 300; jj++)
							matrix_r_300[ii][jj] += matrix_a_300[ii][kk] * matrix_b_300[kk][jj];
}
void multiply_matrices_ijk_ikj_350_50() {
	#pragma omp parallel for
	for (int i = 0; i < 350; i += 50)
		for (int j = 0; j < 350; j += 50)
			for (int k = 0; k < 350; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_350[ii][jj] += matrix_a_350[ii][kk] * matrix_b_350[kk][jj];
}
void multiply_matrices_ijk_ikj_350_70() {
	#pragma omp parallel for
	for (int i = 0; i < 350; i += 70)
		for (int j = 0; j < 350; j += 70)
			for (int k = 0; k < 350; k += 70)
				for (int ii = i; ii < i + 70; ii++)
					for (int kk = k; kk < k + 70; kk++)
						for (int jj = j; jj < j + 70; jj++)
							matrix_r_350[ii][jj] += matrix_a_350[ii][kk] * matrix_b_350[kk][jj];
}
void multiply_matrices_ijk_ikj_350_175() {
	#pragma omp parallel for
	for (int i = 0; i < 350; i += 175)
		for (int j = 0; j < 350; j += 175)
			for (int k = 0; k < 350; k += 175)
				for (int ii = i; ii < i + 175; ii++)
					for (int kk = k; kk < k + 175; kk++)
						for (int jj = j; jj < j + 175; jj++)
							matrix_r_350[ii][jj] += matrix_a_350[ii][kk] * matrix_b_350[kk][jj];
}
void multiply_matrices_ijk_ikj_350_350() {
	#pragma omp parallel for
	for (int i = 0; i < 350; i += 350)
		for (int j = 0; j < 350; j += 350)
			for (int k = 0; k < 350; k += 350)
				for (int ii = i; ii < i + 350; ii++)
					for (int kk = k; kk < k + 350; kk++)
						for (int jj = j; jj < j + 350; jj++)
							matrix_r_350[ii][jj] += matrix_a_350[ii][kk] * matrix_b_350[kk][jj];
}
void multiply_matrices_ijk_ikj_400_50() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i += 50)
		for (int j = 0; j < 400; j += 50)
			for (int k = 0; k < 400; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_400[ii][jj] += matrix_a_400[ii][kk] * matrix_b_400[kk][jj];
}
void multiply_matrices_ijk_ikj_400_80() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i += 80)
		for (int j = 0; j < 400; j += 80)
			for (int k = 0; k < 400; k += 80)
				for (int ii = i; ii < i + 80; ii++)
					for (int kk = k; kk < k + 80; kk++)
						for (int jj = j; jj < j + 80; jj++)
							matrix_r_400[ii][jj] += matrix_a_400[ii][kk] * matrix_b_400[kk][jj];
}
void multiply_matrices_ijk_ikj_400_100() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i += 100)
		for (int j = 0; j < 400; j += 100)
			for (int k = 0; k < 400; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_400[ii][jj] += matrix_a_400[ii][kk] * matrix_b_400[kk][jj];
}
void multiply_matrices_ijk_ikj_400_200() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i += 200)
		for (int j = 0; j < 400; j += 200)
			for (int k = 0; k < 400; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_400[ii][jj] += matrix_a_400[ii][kk] * matrix_b_400[kk][jj];
}
void multiply_matrices_ijk_ikj_400_400() {
	#pragma omp parallel for
	for (int i = 0; i < 400; i += 400)
		for (int j = 0; j < 400; j += 400)
			for (int k = 0; k < 400; k += 400)
				for (int ii = i; ii < i + 400; ii++)
					for (int kk = k; kk < k + 400; kk++)
						for (int jj = j; jj < j + 400; jj++)
							matrix_r_400[ii][jj] += matrix_a_400[ii][kk] * matrix_b_400[kk][jj];
}
void multiply_matrices_ijk_ikj_450_50() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i += 50)
		for (int j = 0; j < 450; j += 50)
			for (int k = 0; k < 450; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_450[ii][jj] += matrix_a_450[ii][kk] * matrix_b_450[kk][jj];
}
void multiply_matrices_ijk_ikj_450_75() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i += 75)
		for (int j = 0; j < 450; j += 75)
			for (int k = 0; k < 450; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_450[ii][jj] += matrix_a_450[ii][kk] * matrix_b_450[kk][jj];
}
void multiply_matrices_ijk_ikj_450_90() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i += 90)
		for (int j = 0; j < 450; j += 90)
			for (int k = 0; k < 450; k += 90)
				for (int ii = i; ii < i + 90; ii++)
					for (int kk = k; kk < k + 90; kk++)
						for (int jj = j; jj < j + 90; jj++)
							matrix_r_450[ii][jj] += matrix_a_450[ii][kk] * matrix_b_450[kk][jj];
}
void multiply_matrices_ijk_ikj_450_150() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i += 150)
		for (int j = 0; j < 450; j += 150)
			for (int k = 0; k < 450; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_450[ii][jj] += matrix_a_450[ii][kk] * matrix_b_450[kk][jj];
}
void multiply_matrices_ijk_ikj_450_225() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i += 225)
		for (int j = 0; j < 450; j += 225)
			for (int k = 0; k < 450; k += 225)
				for (int ii = i; ii < i + 225; ii++)
					for (int kk = k; kk < k + 225; kk++)
						for (int jj = j; jj < j + 225; jj++)
							matrix_r_450[ii][jj] += matrix_a_450[ii][kk] * matrix_b_450[kk][jj];
}
void multiply_matrices_ijk_ikj_450_450() {
	#pragma omp parallel for
	for (int i = 0; i < 450; i += 450)
		for (int j = 0; j < 450; j += 450)
			for (int k = 0; k < 450; k += 450)
				for (int ii = i; ii < i + 450; ii++)
					for (int kk = k; kk < k + 450; kk++)
						for (int jj = j; jj < j + 450; jj++)
							matrix_r_450[ii][jj] += matrix_a_450[ii][kk] * matrix_b_450[kk][jj];
}
void multiply_matrices_ijk_ikj_500_50() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i += 50)
		for (int j = 0; j < 500; j += 50)
			for (int k = 0; k < 500; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_500[ii][jj] += matrix_a_500[ii][kk] * matrix_b_500[kk][jj];
}
void multiply_matrices_ijk_ikj_500_100() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i += 100)
		for (int j = 0; j < 500; j += 100)
			for (int k = 0; k < 500; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_500[ii][jj] += matrix_a_500[ii][kk] * matrix_b_500[kk][jj];
}
void multiply_matrices_ijk_ikj_500_125() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i += 125)
		for (int j = 0; j < 500; j += 125)
			for (int k = 0; k < 500; k += 125)
				for (int ii = i; ii < i + 125; ii++)
					for (int kk = k; kk < k + 125; kk++)
						for (int jj = j; jj < j + 125; jj++)
							matrix_r_500[ii][jj] += matrix_a_500[ii][kk] * matrix_b_500[kk][jj];
}
void multiply_matrices_ijk_ikj_500_250() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i += 250)
		for (int j = 0; j < 500; j += 250)
			for (int k = 0; k < 500; k += 250)
				for (int ii = i; ii < i + 250; ii++)
					for (int kk = k; kk < k + 250; kk++)
						for (int jj = j; jj < j + 250; jj++)
							matrix_r_500[ii][jj] += matrix_a_500[ii][kk] * matrix_b_500[kk][jj];
}
void multiply_matrices_ijk_ikj_500_500() {
	#pragma omp parallel for
	for (int i = 0; i < 500; i += 500)
		for (int j = 0; j < 500; j += 500)
			for (int k = 0; k < 500; k += 500)
				for (int ii = i; ii < i + 500; ii++)
					for (int kk = k; kk < k + 500; kk++)
						for (int jj = j; jj < j + 500; jj++)
							matrix_r_500[ii][jj] += matrix_a_500[ii][kk] * matrix_b_500[kk][jj];
}
void multiply_matrices_ijk_ikj_550_50() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i += 50)
		for (int j = 0; j < 550; j += 50)
			for (int k = 0; k < 550; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_550[ii][jj] += matrix_a_550[ii][kk] * matrix_b_550[kk][jj];
}
void multiply_matrices_ijk_ikj_550_55() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i += 55)
		for (int j = 0; j < 550; j += 55)
			for (int k = 0; k < 550; k += 55)
				for (int ii = i; ii < i + 55; ii++)
					for (int kk = k; kk < k + 55; kk++)
						for (int jj = j; jj < j + 55; jj++)
							matrix_r_550[ii][jj] += matrix_a_550[ii][kk] * matrix_b_550[kk][jj];
}
void multiply_matrices_ijk_ikj_550_110() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i += 110)
		for (int j = 0; j < 550; j += 110)
			for (int k = 0; k < 550; k += 110)
				for (int ii = i; ii < i + 110; ii++)
					for (int kk = k; kk < k + 110; kk++)
						for (int jj = j; jj < j + 110; jj++)
							matrix_r_550[ii][jj] += matrix_a_550[ii][kk] * matrix_b_550[kk][jj];
}
void multiply_matrices_ijk_ikj_550_275() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i += 275)
		for (int j = 0; j < 550; j += 275)
			for (int k = 0; k < 550; k += 275)
				for (int ii = i; ii < i + 275; ii++)
					for (int kk = k; kk < k + 275; kk++)
						for (int jj = j; jj < j + 275; jj++)
							matrix_r_550[ii][jj] += matrix_a_550[ii][kk] * matrix_b_550[kk][jj];
}
void multiply_matrices_ijk_ikj_550_550() {
	#pragma omp parallel for
	for (int i = 0; i < 550; i += 550)
		for (int j = 0; j < 550; j += 550)
			for (int k = 0; k < 550; k += 550)
				for (int ii = i; ii < i + 550; ii++)
					for (int kk = k; kk < k + 550; kk++)
						for (int jj = j; jj < j + 550; jj++)
							matrix_r_550[ii][jj] += matrix_a_550[ii][kk] * matrix_b_550[kk][jj];
}
void multiply_matrices_ijk_ikj_600_50() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 50)
		for (int j = 0; j < 600; j += 50)
			for (int k = 0; k < 600; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_60() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 60)
		for (int j = 0; j < 600; j += 60)
			for (int k = 0; k < 600; k += 60)
				for (int ii = i; ii < i + 60; ii++)
					for (int kk = k; kk < k + 60; kk++)
						for (int jj = j; jj < j + 60; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_75() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 75)
		for (int j = 0; j < 600; j += 75)
			for (int k = 0; k < 600; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_100() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 100)
		for (int j = 0; j < 600; j += 100)
			for (int k = 0; k < 600; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_120() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 120)
		for (int j = 0; j < 600; j += 120)
			for (int k = 0; k < 600; k += 120)
				for (int ii = i; ii < i + 120; ii++)
					for (int kk = k; kk < k + 120; kk++)
						for (int jj = j; jj < j + 120; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_150() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 150)
		for (int j = 0; j < 600; j += 150)
			for (int k = 0; k < 600; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_200() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 200)
		for (int j = 0; j < 600; j += 200)
			for (int k = 0; k < 600; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_300() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 300)
		for (int j = 0; j < 600; j += 300)
			for (int k = 0; k < 600; k += 300)
				for (int ii = i; ii < i + 300; ii++)
					for (int kk = k; kk < k + 300; kk++)
						for (int jj = j; jj < j + 300; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_600_600() {
	#pragma omp parallel for
	for (int i = 0; i < 600; i += 600)
		for (int j = 0; j < 600; j += 600)
			for (int k = 0; k < 600; k += 600)
				for (int ii = i; ii < i + 600; ii++)
					for (int kk = k; kk < k + 600; kk++)
						for (int jj = j; jj < j + 600; jj++)
							matrix_r_600[ii][jj] += matrix_a_600[ii][kk] * matrix_b_600[kk][jj];
}
void multiply_matrices_ijk_ikj_650_50() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i += 50)
		for (int j = 0; j < 650; j += 50)
			for (int k = 0; k < 650; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_650[ii][jj] += matrix_a_650[ii][kk] * matrix_b_650[kk][jj];
}
void multiply_matrices_ijk_ikj_650_65() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i += 65)
		for (int j = 0; j < 650; j += 65)
			for (int k = 0; k < 650; k += 65)
				for (int ii = i; ii < i + 65; ii++)
					for (int kk = k; kk < k + 65; kk++)
						for (int jj = j; jj < j + 65; jj++)
							matrix_r_650[ii][jj] += matrix_a_650[ii][kk] * matrix_b_650[kk][jj];
}
void multiply_matrices_ijk_ikj_650_130() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i += 130)
		for (int j = 0; j < 650; j += 130)
			for (int k = 0; k < 650; k += 130)
				for (int ii = i; ii < i + 130; ii++)
					for (int kk = k; kk < k + 130; kk++)
						for (int jj = j; jj < j + 130; jj++)
							matrix_r_650[ii][jj] += matrix_a_650[ii][kk] * matrix_b_650[kk][jj];
}
void multiply_matrices_ijk_ikj_650_325() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i += 325)
		for (int j = 0; j < 650; j += 325)
			for (int k = 0; k < 650; k += 325)
				for (int ii = i; ii < i + 325; ii++)
					for (int kk = k; kk < k + 325; kk++)
						for (int jj = j; jj < j + 325; jj++)
							matrix_r_650[ii][jj] += matrix_a_650[ii][kk] * matrix_b_650[kk][jj];
}
void multiply_matrices_ijk_ikj_650_650() {
	#pragma omp parallel for
	for (int i = 0; i < 650; i += 650)
		for (int j = 0; j < 650; j += 650)
			for (int k = 0; k < 650; k += 650)
				for (int ii = i; ii < i + 650; ii++)
					for (int kk = k; kk < k + 650; kk++)
						for (int jj = j; jj < j + 650; jj++)
							matrix_r_650[ii][jj] += matrix_a_650[ii][kk] * matrix_b_650[kk][jj];
}
void multiply_matrices_ijk_ikj_700_50() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 50)
		for (int j = 0; j < 700; j += 50)
			for (int k = 0; k < 700; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_700_70() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 70)
		for (int j = 0; j < 700; j += 70)
			for (int k = 0; k < 700; k += 70)
				for (int ii = i; ii < i + 70; ii++)
					for (int kk = k; kk < k + 70; kk++)
						for (int jj = j; jj < j + 70; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_700_100() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 100)
		for (int j = 0; j < 700; j += 100)
			for (int k = 0; k < 700; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_700_140() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 140)
		for (int j = 0; j < 700; j += 140)
			for (int k = 0; k < 700; k += 140)
				for (int ii = i; ii < i + 140; ii++)
					for (int kk = k; kk < k + 140; kk++)
						for (int jj = j; jj < j + 140; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_700_175() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 175)
		for (int j = 0; j < 700; j += 175)
			for (int k = 0; k < 700; k += 175)
				for (int ii = i; ii < i + 175; ii++)
					for (int kk = k; kk < k + 175; kk++)
						for (int jj = j; jj < j + 175; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_700_350() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 350)
		for (int j = 0; j < 700; j += 350)
			for (int k = 0; k < 700; k += 350)
				for (int ii = i; ii < i + 350; ii++)
					for (int kk = k; kk < k + 350; kk++)
						for (int jj = j; jj < j + 350; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_700_700() {
	#pragma omp parallel for
	for (int i = 0; i < 700; i += 700)
		for (int j = 0; j < 700; j += 700)
			for (int k = 0; k < 700; k += 700)
				for (int ii = i; ii < i + 700; ii++)
					for (int kk = k; kk < k + 700; kk++)
						for (int jj = j; jj < j + 700; jj++)
							matrix_r_700[ii][jj] += matrix_a_700[ii][kk] * matrix_b_700[kk][jj];
}
void multiply_matrices_ijk_ikj_750_50() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 50)
		for (int j = 0; j < 750; j += 50)
			for (int k = 0; k < 750; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_750_75() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 75)
		for (int j = 0; j < 750; j += 75)
			for (int k = 0; k < 750; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_750_125() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 125)
		for (int j = 0; j < 750; j += 125)
			for (int k = 0; k < 750; k += 125)
				for (int ii = i; ii < i + 125; ii++)
					for (int kk = k; kk < k + 125; kk++)
						for (int jj = j; jj < j + 125; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_750_150() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 150)
		for (int j = 0; j < 750; j += 150)
			for (int k = 0; k < 750; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_750_250() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 250)
		for (int j = 0; j < 750; j += 250)
			for (int k = 0; k < 750; k += 250)
				for (int ii = i; ii < i + 250; ii++)
					for (int kk = k; kk < k + 250; kk++)
						for (int jj = j; jj < j + 250; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_750_375() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 375)
		for (int j = 0; j < 750; j += 375)
			for (int k = 0; k < 750; k += 375)
				for (int ii = i; ii < i + 375; ii++)
					for (int kk = k; kk < k + 375; kk++)
						for (int jj = j; jj < j + 375; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_750_750() {
	#pragma omp parallel for
	for (int i = 0; i < 750; i += 750)
		for (int j = 0; j < 750; j += 750)
			for (int k = 0; k < 750; k += 750)
				for (int ii = i; ii < i + 750; ii++)
					for (int kk = k; kk < k + 750; kk++)
						for (int jj = j; jj < j + 750; jj++)
							matrix_r_750[ii][jj] += matrix_a_750[ii][kk] * matrix_b_750[kk][jj];
}
void multiply_matrices_ijk_ikj_800_50() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 50)
		for (int j = 0; j < 800; j += 50)
			for (int k = 0; k < 800; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_800_80() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 80)
		for (int j = 0; j < 800; j += 80)
			for (int k = 0; k < 800; k += 80)
				for (int ii = i; ii < i + 80; ii++)
					for (int kk = k; kk < k + 80; kk++)
						for (int jj = j; jj < j + 80; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_800_100() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 100)
		for (int j = 0; j < 800; j += 100)
			for (int k = 0; k < 800; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_800_160() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 160)
		for (int j = 0; j < 800; j += 160)
			for (int k = 0; k < 800; k += 160)
				for (int ii = i; ii < i + 160; ii++)
					for (int kk = k; kk < k + 160; kk++)
						for (int jj = j; jj < j + 160; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_800_200() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 200)
		for (int j = 0; j < 800; j += 200)
			for (int k = 0; k < 800; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_800_400() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 400)
		for (int j = 0; j < 800; j += 400)
			for (int k = 0; k < 800; k += 400)
				for (int ii = i; ii < i + 400; ii++)
					for (int kk = k; kk < k + 400; kk++)
						for (int jj = j; jj < j + 400; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_800_800() {
	#pragma omp parallel for
	for (int i = 0; i < 800; i += 800)
		for (int j = 0; j < 800; j += 800)
			for (int k = 0; k < 800; k += 800)
				for (int ii = i; ii < i + 800; ii++)
					for (int kk = k; kk < k + 800; kk++)
						for (int jj = j; jj < j + 800; jj++)
							matrix_r_800[ii][jj] += matrix_a_800[ii][kk] * matrix_b_800[kk][jj];
}
void multiply_matrices_ijk_ikj_850_50() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i += 50)
		for (int j = 0; j < 850; j += 50)
			for (int k = 0; k < 850; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_850[ii][jj] += matrix_a_850[ii][kk] * matrix_b_850[kk][jj];
}
void multiply_matrices_ijk_ikj_850_85() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i += 85)
		for (int j = 0; j < 850; j += 85)
			for (int k = 0; k < 850; k += 85)
				for (int ii = i; ii < i + 85; ii++)
					for (int kk = k; kk < k + 85; kk++)
						for (int jj = j; jj < j + 85; jj++)
							matrix_r_850[ii][jj] += matrix_a_850[ii][kk] * matrix_b_850[kk][jj];
}
void multiply_matrices_ijk_ikj_850_170() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i += 170)
		for (int j = 0; j < 850; j += 170)
			for (int k = 0; k < 850; k += 170)
				for (int ii = i; ii < i + 170; ii++)
					for (int kk = k; kk < k + 170; kk++)
						for (int jj = j; jj < j + 170; jj++)
							matrix_r_850[ii][jj] += matrix_a_850[ii][kk] * matrix_b_850[kk][jj];
}
void multiply_matrices_ijk_ikj_850_425() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i += 425)
		for (int j = 0; j < 850; j += 425)
			for (int k = 0; k < 850; k += 425)
				for (int ii = i; ii < i + 425; ii++)
					for (int kk = k; kk < k + 425; kk++)
						for (int jj = j; jj < j + 425; jj++)
							matrix_r_850[ii][jj] += matrix_a_850[ii][kk] * matrix_b_850[kk][jj];
}
void multiply_matrices_ijk_ikj_850_850() {
	#pragma omp parallel for
	for (int i = 0; i < 850; i += 850)
		for (int j = 0; j < 850; j += 850)
			for (int k = 0; k < 850; k += 850)
				for (int ii = i; ii < i + 850; ii++)
					for (int kk = k; kk < k + 850; kk++)
						for (int jj = j; jj < j + 850; jj++)
							matrix_r_850[ii][jj] += matrix_a_850[ii][kk] * matrix_b_850[kk][jj];
}
void multiply_matrices_ijk_ikj_900_50() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 50)
		for (int j = 0; j < 900; j += 50)
			for (int k = 0; k < 900; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_60() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 60)
		for (int j = 0; j < 900; j += 60)
			for (int k = 0; k < 900; k += 60)
				for (int ii = i; ii < i + 60; ii++)
					for (int kk = k; kk < k + 60; kk++)
						for (int jj = j; jj < j + 60; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_75() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 75)
		for (int j = 0; j < 900; j += 75)
			for (int k = 0; k < 900; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_90() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 90)
		for (int j = 0; j < 900; j += 90)
			for (int k = 0; k < 900; k += 90)
				for (int ii = i; ii < i + 90; ii++)
					for (int kk = k; kk < k + 90; kk++)
						for (int jj = j; jj < j + 90; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_100() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 100)
		for (int j = 0; j < 900; j += 100)
			for (int k = 0; k < 900; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_150() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 150)
		for (int j = 0; j < 900; j += 150)
			for (int k = 0; k < 900; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_180() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 180)
		for (int j = 0; j < 900; j += 180)
			for (int k = 0; k < 900; k += 180)
				for (int ii = i; ii < i + 180; ii++)
					for (int kk = k; kk < k + 180; kk++)
						for (int jj = j; jj < j + 180; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_225() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 225)
		for (int j = 0; j < 900; j += 225)
			for (int k = 0; k < 900; k += 225)
				for (int ii = i; ii < i + 225; ii++)
					for (int kk = k; kk < k + 225; kk++)
						for (int jj = j; jj < j + 225; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_300() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 300)
		for (int j = 0; j < 900; j += 300)
			for (int k = 0; k < 900; k += 300)
				for (int ii = i; ii < i + 300; ii++)
					for (int kk = k; kk < k + 300; kk++)
						for (int jj = j; jj < j + 300; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_450() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 450)
		for (int j = 0; j < 900; j += 450)
			for (int k = 0; k < 900; k += 450)
				for (int ii = i; ii < i + 450; ii++)
					for (int kk = k; kk < k + 450; kk++)
						for (int jj = j; jj < j + 450; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_900_900() {
	#pragma omp parallel for
	for (int i = 0; i < 900; i += 900)
		for (int j = 0; j < 900; j += 900)
			for (int k = 0; k < 900; k += 900)
				for (int ii = i; ii < i + 900; ii++)
					for (int kk = k; kk < k + 900; kk++)
						for (int jj = j; jj < j + 900; jj++)
							matrix_r_900[ii][jj] += matrix_a_900[ii][kk] * matrix_b_900[kk][jj];
}
void multiply_matrices_ijk_ikj_950_50() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i += 50)
		for (int j = 0; j < 950; j += 50)
			for (int k = 0; k < 950; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_950[ii][jj] += matrix_a_950[ii][kk] * matrix_b_950[kk][jj];
}
void multiply_matrices_ijk_ikj_950_95() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i += 95)
		for (int j = 0; j < 950; j += 95)
			for (int k = 0; k < 950; k += 95)
				for (int ii = i; ii < i + 95; ii++)
					for (int kk = k; kk < k + 95; kk++)
						for (int jj = j; jj < j + 95; jj++)
							matrix_r_950[ii][jj] += matrix_a_950[ii][kk] * matrix_b_950[kk][jj];
}
void multiply_matrices_ijk_ikj_950_190() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i += 190)
		for (int j = 0; j < 950; j += 190)
			for (int k = 0; k < 950; k += 190)
				for (int ii = i; ii < i + 190; ii++)
					for (int kk = k; kk < k + 190; kk++)
						for (int jj = j; jj < j + 190; jj++)
							matrix_r_950[ii][jj] += matrix_a_950[ii][kk] * matrix_b_950[kk][jj];
}
void multiply_matrices_ijk_ikj_950_475() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i += 475)
		for (int j = 0; j < 950; j += 475)
			for (int k = 0; k < 950; k += 475)
				for (int ii = i; ii < i + 475; ii++)
					for (int kk = k; kk < k + 475; kk++)
						for (int jj = j; jj < j + 475; jj++)
							matrix_r_950[ii][jj] += matrix_a_950[ii][kk] * matrix_b_950[kk][jj];
}
void multiply_matrices_ijk_ikj_950_950() {
	#pragma omp parallel for
	for (int i = 0; i < 950; i += 950)
		for (int j = 0; j < 950; j += 950)
			for (int k = 0; k < 950; k += 950)
				for (int ii = i; ii < i + 950; ii++)
					for (int kk = k; kk < k + 950; kk++)
						for (int jj = j; jj < j + 950; jj++)
							matrix_r_950[ii][jj] += matrix_a_950[ii][kk] * matrix_b_950[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 50)
		for (int j = 0; j < 1000; j += 50)
			for (int k = 0; k < 1000; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_100() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 100)
		for (int j = 0; j < 1000; j += 100)
			for (int k = 0; k < 1000; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_125() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 125)
		for (int j = 0; j < 1000; j += 125)
			for (int k = 0; k < 1000; k += 125)
				for (int ii = i; ii < i + 125; ii++)
					for (int kk = k; kk < k + 125; kk++)
						for (int jj = j; jj < j + 125; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_200() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 200)
		for (int j = 0; j < 1000; j += 200)
			for (int k = 0; k < 1000; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_250() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 250)
		for (int j = 0; j < 1000; j += 250)
			for (int k = 0; k < 1000; k += 250)
				for (int ii = i; ii < i + 250; ii++)
					for (int kk = k; kk < k + 250; kk++)
						for (int jj = j; jj < j + 250; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_500() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 500)
		for (int j = 0; j < 1000; j += 500)
			for (int k = 0; k < 1000; k += 500)
				for (int ii = i; ii < i + 500; ii++)
					for (int kk = k; kk < k + 500; kk++)
						for (int jj = j; jj < j + 500; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1000_1000() {
	#pragma omp parallel for
	for (int i = 0; i < 1000; i += 1000)
		for (int j = 0; j < 1000; j += 1000)
			for (int k = 0; k < 1000; k += 1000)
				for (int ii = i; ii < i + 1000; ii++)
					for (int kk = k; kk < k + 1000; kk++)
						for (int jj = j; jj < j + 1000; jj++)
							matrix_r_1000[ii][jj] += matrix_a_1000[ii][kk] * matrix_b_1000[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 50)
		for (int j = 0; j < 1050; j += 50)
			for (int k = 0; k < 1050; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_70() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 70)
		for (int j = 0; j < 1050; j += 70)
			for (int k = 0; k < 1050; k += 70)
				for (int ii = i; ii < i + 70; ii++)
					for (int kk = k; kk < k + 70; kk++)
						for (int jj = j; jj < j + 70; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_75() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 75)
		for (int j = 0; j < 1050; j += 75)
			for (int k = 0; k < 1050; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_105() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 105)
		for (int j = 0; j < 1050; j += 105)
			for (int k = 0; k < 1050; k += 105)
				for (int ii = i; ii < i + 105; ii++)
					for (int kk = k; kk < k + 105; kk++)
						for (int jj = j; jj < j + 105; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_150() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 150)
		for (int j = 0; j < 1050; j += 150)
			for (int k = 0; k < 1050; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_175() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 175)
		for (int j = 0; j < 1050; j += 175)
			for (int k = 0; k < 1050; k += 175)
				for (int ii = i; ii < i + 175; ii++)
					for (int kk = k; kk < k + 175; kk++)
						for (int jj = j; jj < j + 175; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_210() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 210)
		for (int j = 0; j < 1050; j += 210)
			for (int k = 0; k < 1050; k += 210)
				for (int ii = i; ii < i + 210; ii++)
					for (int kk = k; kk < k + 210; kk++)
						for (int jj = j; jj < j + 210; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_350() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 350)
		for (int j = 0; j < 1050; j += 350)
			for (int k = 0; k < 1050; k += 350)
				for (int ii = i; ii < i + 350; ii++)
					for (int kk = k; kk < k + 350; kk++)
						for (int jj = j; jj < j + 350; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_525() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 525)
		for (int j = 0; j < 1050; j += 525)
			for (int k = 0; k < 1050; k += 525)
				for (int ii = i; ii < i + 525; ii++)
					for (int kk = k; kk < k + 525; kk++)
						for (int jj = j; jj < j + 525; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1050_1050() {
	#pragma omp parallel for
	for (int i = 0; i < 1050; i += 1050)
		for (int j = 0; j < 1050; j += 1050)
			for (int k = 0; k < 1050; k += 1050)
				for (int ii = i; ii < i + 1050; ii++)
					for (int kk = k; kk < k + 1050; kk++)
						for (int jj = j; jj < j + 1050; jj++)
							matrix_r_1050[ii][jj] += matrix_a_1050[ii][kk] * matrix_b_1050[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 50)
		for (int j = 0; j < 1100; j += 50)
			for (int k = 0; k < 1100; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_55() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 55)
		for (int j = 0; j < 1100; j += 55)
			for (int k = 0; k < 1100; k += 55)
				for (int ii = i; ii < i + 55; ii++)
					for (int kk = k; kk < k + 55; kk++)
						for (int jj = j; jj < j + 55; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_100() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 100)
		for (int j = 0; j < 1100; j += 100)
			for (int k = 0; k < 1100; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_110() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 110)
		for (int j = 0; j < 1100; j += 110)
			for (int k = 0; k < 1100; k += 110)
				for (int ii = i; ii < i + 110; ii++)
					for (int kk = k; kk < k + 110; kk++)
						for (int jj = j; jj < j + 110; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_220() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 220)
		for (int j = 0; j < 1100; j += 220)
			for (int k = 0; k < 1100; k += 220)
				for (int ii = i; ii < i + 220; ii++)
					for (int kk = k; kk < k + 220; kk++)
						for (int jj = j; jj < j + 220; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_275() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 275)
		for (int j = 0; j < 1100; j += 275)
			for (int k = 0; k < 1100; k += 275)
				for (int ii = i; ii < i + 275; ii++)
					for (int kk = k; kk < k + 275; kk++)
						for (int jj = j; jj < j + 275; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_550() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 550)
		for (int j = 0; j < 1100; j += 550)
			for (int k = 0; k < 1100; k += 550)
				for (int ii = i; ii < i + 550; ii++)
					for (int kk = k; kk < k + 550; kk++)
						for (int jj = j; jj < j + 550; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1100_1100() {
	#pragma omp parallel for
	for (int i = 0; i < 1100; i += 1100)
		for (int j = 0; j < 1100; j += 1100)
			for (int k = 0; k < 1100; k += 1100)
				for (int ii = i; ii < i + 1100; ii++)
					for (int kk = k; kk < k + 1100; kk++)
						for (int jj = j; jj < j + 1100; jj++)
							matrix_r_1100[ii][jj] += matrix_a_1100[ii][kk] * matrix_b_1100[kk][jj];
}
void multiply_matrices_ijk_ikj_1150_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i += 50)
		for (int j = 0; j < 1150; j += 50)
			for (int k = 0; k < 1150; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1150[ii][jj] += matrix_a_1150[ii][kk] * matrix_b_1150[kk][jj];
}
void multiply_matrices_ijk_ikj_1150_115() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i += 115)
		for (int j = 0; j < 1150; j += 115)
			for (int k = 0; k < 1150; k += 115)
				for (int ii = i; ii < i + 115; ii++)
					for (int kk = k; kk < k + 115; kk++)
						for (int jj = j; jj < j + 115; jj++)
							matrix_r_1150[ii][jj] += matrix_a_1150[ii][kk] * matrix_b_1150[kk][jj];
}
void multiply_matrices_ijk_ikj_1150_230() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i += 230)
		for (int j = 0; j < 1150; j += 230)
			for (int k = 0; k < 1150; k += 230)
				for (int ii = i; ii < i + 230; ii++)
					for (int kk = k; kk < k + 230; kk++)
						for (int jj = j; jj < j + 230; jj++)
							matrix_r_1150[ii][jj] += matrix_a_1150[ii][kk] * matrix_b_1150[kk][jj];
}
void multiply_matrices_ijk_ikj_1150_575() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i += 575)
		for (int j = 0; j < 1150; j += 575)
			for (int k = 0; k < 1150; k += 575)
				for (int ii = i; ii < i + 575; ii++)
					for (int kk = k; kk < k + 575; kk++)
						for (int jj = j; jj < j + 575; jj++)
							matrix_r_1150[ii][jj] += matrix_a_1150[ii][kk] * matrix_b_1150[kk][jj];
}
void multiply_matrices_ijk_ikj_1150_1150() {
	#pragma omp parallel for
	for (int i = 0; i < 1150; i += 1150)
		for (int j = 0; j < 1150; j += 1150)
			for (int k = 0; k < 1150; k += 1150)
				for (int ii = i; ii < i + 1150; ii++)
					for (int kk = k; kk < k + 1150; kk++)
						for (int jj = j; jj < j + 1150; jj++)
							matrix_r_1150[ii][jj] += matrix_a_1150[ii][kk] * matrix_b_1150[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 50)
		for (int j = 0; j < 1200; j += 50)
			for (int k = 0; k < 1200; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_60() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 60)
		for (int j = 0; j < 1200; j += 60)
			for (int k = 0; k < 1200; k += 60)
				for (int ii = i; ii < i + 60; ii++)
					for (int kk = k; kk < k + 60; kk++)
						for (int jj = j; jj < j + 60; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_75() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 75)
		for (int j = 0; j < 1200; j += 75)
			for (int k = 0; k < 1200; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_80() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 80)
		for (int j = 0; j < 1200; j += 80)
			for (int k = 0; k < 1200; k += 80)
				for (int ii = i; ii < i + 80; ii++)
					for (int kk = k; kk < k + 80; kk++)
						for (int jj = j; jj < j + 80; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_100() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 100)
		for (int j = 0; j < 1200; j += 100)
			for (int k = 0; k < 1200; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_120() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 120)
		for (int j = 0; j < 1200; j += 120)
			for (int k = 0; k < 1200; k += 120)
				for (int ii = i; ii < i + 120; ii++)
					for (int kk = k; kk < k + 120; kk++)
						for (int jj = j; jj < j + 120; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_150() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 150)
		for (int j = 0; j < 1200; j += 150)
			for (int k = 0; k < 1200; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_200() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 200)
		for (int j = 0; j < 1200; j += 200)
			for (int k = 0; k < 1200; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_240() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 240)
		for (int j = 0; j < 1200; j += 240)
			for (int k = 0; k < 1200; k += 240)
				for (int ii = i; ii < i + 240; ii++)
					for (int kk = k; kk < k + 240; kk++)
						for (int jj = j; jj < j + 240; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_300() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 300)
		for (int j = 0; j < 1200; j += 300)
			for (int k = 0; k < 1200; k += 300)
				for (int ii = i; ii < i + 300; ii++)
					for (int kk = k; kk < k + 300; kk++)
						for (int jj = j; jj < j + 300; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_400() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 400)
		for (int j = 0; j < 1200; j += 400)
			for (int k = 0; k < 1200; k += 400)
				for (int ii = i; ii < i + 400; ii++)
					for (int kk = k; kk < k + 400; kk++)
						for (int jj = j; jj < j + 400; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_600() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 600)
		for (int j = 0; j < 1200; j += 600)
			for (int k = 0; k < 1200; k += 600)
				for (int ii = i; ii < i + 600; ii++)
					for (int kk = k; kk < k + 600; kk++)
						for (int jj = j; jj < j + 600; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1200_1200() {
	#pragma omp parallel for
	for (int i = 0; i < 1200; i += 1200)
		for (int j = 0; j < 1200; j += 1200)
			for (int k = 0; k < 1200; k += 1200)
				for (int ii = i; ii < i + 1200; ii++)
					for (int kk = k; kk < k + 1200; kk++)
						for (int jj = j; jj < j + 1200; jj++)
							matrix_r_1200[ii][jj] += matrix_a_1200[ii][kk] * matrix_b_1200[kk][jj];
}
void multiply_matrices_ijk_ikj_1250_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i += 50)
		for (int j = 0; j < 1250; j += 50)
			for (int k = 0; k < 1250; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1250[ii][jj] += matrix_a_1250[ii][kk] * matrix_b_1250[kk][jj];
}
void multiply_matrices_ijk_ikj_1250_125() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i += 125)
		for (int j = 0; j < 1250; j += 125)
			for (int k = 0; k < 1250; k += 125)
				for (int ii = i; ii < i + 125; ii++)
					for (int kk = k; kk < k + 125; kk++)
						for (int jj = j; jj < j + 125; jj++)
							matrix_r_1250[ii][jj] += matrix_a_1250[ii][kk] * matrix_b_1250[kk][jj];
}
void multiply_matrices_ijk_ikj_1250_250() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i += 250)
		for (int j = 0; j < 1250; j += 250)
			for (int k = 0; k < 1250; k += 250)
				for (int ii = i; ii < i + 250; ii++)
					for (int kk = k; kk < k + 250; kk++)
						for (int jj = j; jj < j + 250; jj++)
							matrix_r_1250[ii][jj] += matrix_a_1250[ii][kk] * matrix_b_1250[kk][jj];
}
void multiply_matrices_ijk_ikj_1250_625() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i += 625)
		for (int j = 0; j < 1250; j += 625)
			for (int k = 0; k < 1250; k += 625)
				for (int ii = i; ii < i + 625; ii++)
					for (int kk = k; kk < k + 625; kk++)
						for (int jj = j; jj < j + 625; jj++)
							matrix_r_1250[ii][jj] += matrix_a_1250[ii][kk] * matrix_b_1250[kk][jj];
}
void multiply_matrices_ijk_ikj_1250_1250() {
	#pragma omp parallel for
	for (int i = 0; i < 1250; i += 1250)
		for (int j = 0; j < 1250; j += 1250)
			for (int k = 0; k < 1250; k += 1250)
				for (int ii = i; ii < i + 1250; ii++)
					for (int kk = k; kk < k + 1250; kk++)
						for (int jj = j; jj < j + 1250; jj++)
							matrix_r_1250[ii][jj] += matrix_a_1250[ii][kk] * matrix_b_1250[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 50)
		for (int j = 0; j < 1300; j += 50)
			for (int k = 0; k < 1300; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_52() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 52)
		for (int j = 0; j < 1300; j += 52)
			for (int k = 0; k < 1300; k += 52)
				for (int ii = i; ii < i + 52; ii++)
					for (int kk = k; kk < k + 52; kk++)
						for (int jj = j; jj < j + 52; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_65() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 65)
		for (int j = 0; j < 1300; j += 65)
			for (int k = 0; k < 1300; k += 65)
				for (int ii = i; ii < i + 65; ii++)
					for (int kk = k; kk < k + 65; kk++)
						for (int jj = j; jj < j + 65; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_100() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 100)
		for (int j = 0; j < 1300; j += 100)
			for (int k = 0; k < 1300; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_130() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 130)
		for (int j = 0; j < 1300; j += 130)
			for (int k = 0; k < 1300; k += 130)
				for (int ii = i; ii < i + 130; ii++)
					for (int kk = k; kk < k + 130; kk++)
						for (int jj = j; jj < j + 130; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_260() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 260)
		for (int j = 0; j < 1300; j += 260)
			for (int k = 0; k < 1300; k += 260)
				for (int ii = i; ii < i + 260; ii++)
					for (int kk = k; kk < k + 260; kk++)
						for (int jj = j; jj < j + 260; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_325() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 325)
		for (int j = 0; j < 1300; j += 325)
			for (int k = 0; k < 1300; k += 325)
				for (int ii = i; ii < i + 325; ii++)
					for (int kk = k; kk < k + 325; kk++)
						for (int jj = j; jj < j + 325; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_650() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 650)
		for (int j = 0; j < 1300; j += 650)
			for (int k = 0; k < 1300; k += 650)
				for (int ii = i; ii < i + 650; ii++)
					for (int kk = k; kk < k + 650; kk++)
						for (int jj = j; jj < j + 650; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1300_1300() {
	#pragma omp parallel for
	for (int i = 0; i < 1300; i += 1300)
		for (int j = 0; j < 1300; j += 1300)
			for (int k = 0; k < 1300; k += 1300)
				for (int ii = i; ii < i + 1300; ii++)
					for (int kk = k; kk < k + 1300; kk++)
						for (int jj = j; jj < j + 1300; jj++)
							matrix_r_1300[ii][jj] += matrix_a_1300[ii][kk] * matrix_b_1300[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 50)
		for (int j = 0; j < 1350; j += 50)
			for (int k = 0; k < 1350; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_54() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 54)
		for (int j = 0; j < 1350; j += 54)
			for (int k = 0; k < 1350; k += 54)
				for (int ii = i; ii < i + 54; ii++)
					for (int kk = k; kk < k + 54; kk++)
						for (int jj = j; jj < j + 54; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_75() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 75)
		for (int j = 0; j < 1350; j += 75)
			for (int k = 0; k < 1350; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_90() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 90)
		for (int j = 0; j < 1350; j += 90)
			for (int k = 0; k < 1350; k += 90)
				for (int ii = i; ii < i + 90; ii++)
					for (int kk = k; kk < k + 90; kk++)
						for (int jj = j; jj < j + 90; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_135() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 135)
		for (int j = 0; j < 1350; j += 135)
			for (int k = 0; k < 1350; k += 135)
				for (int ii = i; ii < i + 135; ii++)
					for (int kk = k; kk < k + 135; kk++)
						for (int jj = j; jj < j + 135; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_150() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 150)
		for (int j = 0; j < 1350; j += 150)
			for (int k = 0; k < 1350; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_225() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 225)
		for (int j = 0; j < 1350; j += 225)
			for (int k = 0; k < 1350; k += 225)
				for (int ii = i; ii < i + 225; ii++)
					for (int kk = k; kk < k + 225; kk++)
						for (int jj = j; jj < j + 225; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_270() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 270)
		for (int j = 0; j < 1350; j += 270)
			for (int k = 0; k < 1350; k += 270)
				for (int ii = i; ii < i + 270; ii++)
					for (int kk = k; kk < k + 270; kk++)
						for (int jj = j; jj < j + 270; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_450() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 450)
		for (int j = 0; j < 1350; j += 450)
			for (int k = 0; k < 1350; k += 450)
				for (int ii = i; ii < i + 450; ii++)
					for (int kk = k; kk < k + 450; kk++)
						for (int jj = j; jj < j + 450; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_675() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 675)
		for (int j = 0; j < 1350; j += 675)
			for (int k = 0; k < 1350; k += 675)
				for (int ii = i; ii < i + 675; ii++)
					for (int kk = k; kk < k + 675; kk++)
						for (int jj = j; jj < j + 675; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1350_1350() {
	#pragma omp parallel for
	for (int i = 0; i < 1350; i += 1350)
		for (int j = 0; j < 1350; j += 1350)
			for (int k = 0; k < 1350; k += 1350)
				for (int ii = i; ii < i + 1350; ii++)
					for (int kk = k; kk < k + 1350; kk++)
						for (int jj = j; jj < j + 1350; jj++)
							matrix_r_1350[ii][jj] += matrix_a_1350[ii][kk] * matrix_b_1350[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 50)
		for (int j = 0; j < 1400; j += 50)
			for (int k = 0; k < 1400; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_56() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 56)
		for (int j = 0; j < 1400; j += 56)
			for (int k = 0; k < 1400; k += 56)
				for (int ii = i; ii < i + 56; ii++)
					for (int kk = k; kk < k + 56; kk++)
						for (int jj = j; jj < j + 56; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_70() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 70)
		for (int j = 0; j < 1400; j += 70)
			for (int k = 0; k < 1400; k += 70)
				for (int ii = i; ii < i + 70; ii++)
					for (int kk = k; kk < k + 70; kk++)
						for (int jj = j; jj < j + 70; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_100() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 100)
		for (int j = 0; j < 1400; j += 100)
			for (int k = 0; k < 1400; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_140() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 140)
		for (int j = 0; j < 1400; j += 140)
			for (int k = 0; k < 1400; k += 140)
				for (int ii = i; ii < i + 140; ii++)
					for (int kk = k; kk < k + 140; kk++)
						for (int jj = j; jj < j + 140; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_175() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 175)
		for (int j = 0; j < 1400; j += 175)
			for (int k = 0; k < 1400; k += 175)
				for (int ii = i; ii < i + 175; ii++)
					for (int kk = k; kk < k + 175; kk++)
						for (int jj = j; jj < j + 175; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_200() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 200)
		for (int j = 0; j < 1400; j += 200)
			for (int k = 0; k < 1400; k += 200)
				for (int ii = i; ii < i + 200; ii++)
					for (int kk = k; kk < k + 200; kk++)
						for (int jj = j; jj < j + 200; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_280() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 280)
		for (int j = 0; j < 1400; j += 280)
			for (int k = 0; k < 1400; k += 280)
				for (int ii = i; ii < i + 280; ii++)
					for (int kk = k; kk < k + 280; kk++)
						for (int jj = j; jj < j + 280; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_350() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 350)
		for (int j = 0; j < 1400; j += 350)
			for (int k = 0; k < 1400; k += 350)
				for (int ii = i; ii < i + 350; ii++)
					for (int kk = k; kk < k + 350; kk++)
						for (int jj = j; jj < j + 350; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_700() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 700)
		for (int j = 0; j < 1400; j += 700)
			for (int k = 0; k < 1400; k += 700)
				for (int ii = i; ii < i + 700; ii++)
					for (int kk = k; kk < k + 700; kk++)
						for (int jj = j; jj < j + 700; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1400_1400() {
	#pragma omp parallel for
	for (int i = 0; i < 1400; i += 1400)
		for (int j = 0; j < 1400; j += 1400)
			for (int k = 0; k < 1400; k += 1400)
				for (int ii = i; ii < i + 1400; ii++)
					for (int kk = k; kk < k + 1400; kk++)
						for (int jj = j; jj < j + 1400; jj++)
							matrix_r_1400[ii][jj] += matrix_a_1400[ii][kk] * matrix_b_1400[kk][jj];
}
void multiply_matrices_ijk_ikj_1450_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i += 50)
		for (int j = 0; j < 1450; j += 50)
			for (int k = 0; k < 1450; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1450[ii][jj] += matrix_a_1450[ii][kk] * matrix_b_1450[kk][jj];
}
void multiply_matrices_ijk_ikj_1450_58() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i += 58)
		for (int j = 0; j < 1450; j += 58)
			for (int k = 0; k < 1450; k += 58)
				for (int ii = i; ii < i + 58; ii++)
					for (int kk = k; kk < k + 58; kk++)
						for (int jj = j; jj < j + 58; jj++)
							matrix_r_1450[ii][jj] += matrix_a_1450[ii][kk] * matrix_b_1450[kk][jj];
}
void multiply_matrices_ijk_ikj_1450_145() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i += 145)
		for (int j = 0; j < 1450; j += 145)
			for (int k = 0; k < 1450; k += 145)
				for (int ii = i; ii < i + 145; ii++)
					for (int kk = k; kk < k + 145; kk++)
						for (int jj = j; jj < j + 145; jj++)
							matrix_r_1450[ii][jj] += matrix_a_1450[ii][kk] * matrix_b_1450[kk][jj];
}
void multiply_matrices_ijk_ikj_1450_290() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i += 290)
		for (int j = 0; j < 1450; j += 290)
			for (int k = 0; k < 1450; k += 290)
				for (int ii = i; ii < i + 290; ii++)
					for (int kk = k; kk < k + 290; kk++)
						for (int jj = j; jj < j + 290; jj++)
							matrix_r_1450[ii][jj] += matrix_a_1450[ii][kk] * matrix_b_1450[kk][jj];
}
void multiply_matrices_ijk_ikj_1450_725() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i += 725)
		for (int j = 0; j < 1450; j += 725)
			for (int k = 0; k < 1450; k += 725)
				for (int ii = i; ii < i + 725; ii++)
					for (int kk = k; kk < k + 725; kk++)
						for (int jj = j; jj < j + 725; jj++)
							matrix_r_1450[ii][jj] += matrix_a_1450[ii][kk] * matrix_b_1450[kk][jj];
}
void multiply_matrices_ijk_ikj_1450_1450() {
	#pragma omp parallel for
	for (int i = 0; i < 1450; i += 1450)
		for (int j = 0; j < 1450; j += 1450)
			for (int k = 0; k < 1450; k += 1450)
				for (int ii = i; ii < i + 1450; ii++)
					for (int kk = k; kk < k + 1450; kk++)
						for (int jj = j; jj < j + 1450; jj++)
							matrix_r_1450[ii][jj] += matrix_a_1450[ii][kk] * matrix_b_1450[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_50() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 50)
		for (int j = 0; j < 1500; j += 50)
			for (int k = 0; k < 1500; k += 50)
				for (int ii = i; ii < i + 50; ii++)
					for (int kk = k; kk < k + 50; kk++)
						for (int jj = j; jj < j + 50; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_60() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 60)
		for (int j = 0; j < 1500; j += 60)
			for (int k = 0; k < 1500; k += 60)
				for (int ii = i; ii < i + 60; ii++)
					for (int kk = k; kk < k + 60; kk++)
						for (int jj = j; jj < j + 60; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_75() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 75)
		for (int j = 0; j < 1500; j += 75)
			for (int k = 0; k < 1500; k += 75)
				for (int ii = i; ii < i + 75; ii++)
					for (int kk = k; kk < k + 75; kk++)
						for (int jj = j; jj < j + 75; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_100() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 100)
		for (int j = 0; j < 1500; j += 100)
			for (int k = 0; k < 1500; k += 100)
				for (int ii = i; ii < i + 100; ii++)
					for (int kk = k; kk < k + 100; kk++)
						for (int jj = j; jj < j + 100; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_125() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 125)
		for (int j = 0; j < 1500; j += 125)
			for (int k = 0; k < 1500; k += 125)
				for (int ii = i; ii < i + 125; ii++)
					for (int kk = k; kk < k + 125; kk++)
						for (int jj = j; jj < j + 125; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_150() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 150)
		for (int j = 0; j < 1500; j += 150)
			for (int k = 0; k < 1500; k += 150)
				for (int ii = i; ii < i + 150; ii++)
					for (int kk = k; kk < k + 150; kk++)
						for (int jj = j; jj < j + 150; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_250() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 250)
		for (int j = 0; j < 1500; j += 250)
			for (int k = 0; k < 1500; k += 250)
				for (int ii = i; ii < i + 250; ii++)
					for (int kk = k; kk < k + 250; kk++)
						for (int jj = j; jj < j + 250; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_300() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 300)
		for (int j = 0; j < 1500; j += 300)
			for (int k = 0; k < 1500; k += 300)
				for (int ii = i; ii < i + 300; ii++)
					for (int kk = k; kk < k + 300; kk++)
						for (int jj = j; jj < j + 300; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_375() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 375)
		for (int j = 0; j < 1500; j += 375)
			for (int k = 0; k < 1500; k += 375)
				for (int ii = i; ii < i + 375; ii++)
					for (int kk = k; kk < k + 375; kk++)
						for (int jj = j; jj < j + 375; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_500() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 500)
		for (int j = 0; j < 1500; j += 500)
			for (int k = 0; k < 1500; k += 500)
				for (int ii = i; ii < i + 500; ii++)
					for (int kk = k; kk < k + 500; kk++)
						for (int jj = j; jj < j + 500; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_750() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 750)
		for (int j = 0; j < 1500; j += 750)
			for (int k = 0; k < 1500; k += 750)
				for (int ii = i; ii < i + 750; ii++)
					for (int kk = k; kk < k + 750; kk++)
						for (int jj = j; jj < j + 750; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void multiply_matrices_ijk_ikj_1500_1500() {
	#pragma omp parallel for
	for (int i = 0; i < 1500; i += 1500)
		for (int j = 0; j < 1500; j += 1500)
			for (int k = 0; k < 1500; k += 1500)
				for (int ii = i; ii < i + 1500; ii++)
					for (int kk = k; kk < k + 1500; kk++)
						for (int jj = j; jj < j + 1500; jj++)
							matrix_r_1500[ii][jj] += matrix_a_1500[ii][kk] * matrix_b_1500[kk][jj];
}
void measure(void(*measure_invocation)(void(*ff)())) {
	measure_invocation_50("SEQ_IKJ 50", multiply_matrices_ikj_50, measure_invocation);
	measure_invocation_50("IJK 50", multiply_matrices_ijk_50, measure_invocation);
	measure_invocation_100("SEQ_IKJ 100", multiply_matrices_ikj_100, measure_invocation);
	measure_invocation_100("IJK 100", multiply_matrices_ijk_100, measure_invocation);
	measure_invocation_150("SEQ_IKJ 150", multiply_matrices_ikj_150, measure_invocation);
	measure_invocation_150("IJK 150", multiply_matrices_ijk_150, measure_invocation);
	measure_invocation_200("SEQ_IKJ 200", multiply_matrices_ikj_200, measure_invocation);
	measure_invocation_200("IJK 200", multiply_matrices_ijk_200, measure_invocation);
	measure_invocation_250("SEQ_IKJ 250", multiply_matrices_ikj_250, measure_invocation);
	measure_invocation_250("IJK 250", multiply_matrices_ijk_250, measure_invocation);
	measure_invocation_300("SEQ_IKJ 300", multiply_matrices_ikj_300, measure_invocation);
	measure_invocation_300("IJK 300", multiply_matrices_ijk_300, measure_invocation);
	measure_invocation_350("SEQ_IKJ 350", multiply_matrices_ikj_350, measure_invocation);
	measure_invocation_350("IJK 350", multiply_matrices_ijk_350, measure_invocation);
	measure_invocation_400("SEQ_IKJ 400", multiply_matrices_ikj_400, measure_invocation);
	measure_invocation_400("IJK 400", multiply_matrices_ijk_400, measure_invocation);
	measure_invocation_450("SEQ_IKJ 450", multiply_matrices_ikj_450, measure_invocation);
	measure_invocation_450("IJK 450", multiply_matrices_ijk_450, measure_invocation);
	measure_invocation_500("SEQ_IKJ 500", multiply_matrices_ikj_500, measure_invocation);
	measure_invocation_500("IJK 500", multiply_matrices_ijk_500, measure_invocation);
	measure_invocation_550("SEQ_IKJ 550", multiply_matrices_ikj_550, measure_invocation);
	measure_invocation_550("IJK 550", multiply_matrices_ijk_550, measure_invocation);
	measure_invocation_600("SEQ_IKJ 600", multiply_matrices_ikj_600, measure_invocation);
	measure_invocation_600("IJK 600", multiply_matrices_ijk_600, measure_invocation);
	measure_invocation_650("SEQ_IKJ 650", multiply_matrices_ikj_650, measure_invocation);
	measure_invocation_650("IJK 650", multiply_matrices_ijk_650, measure_invocation);
	measure_invocation_700("SEQ_IKJ 700", multiply_matrices_ikj_700, measure_invocation);
	measure_invocation_700("IJK 700", multiply_matrices_ijk_700, measure_invocation);
	measure_invocation_750("SEQ_IKJ 750", multiply_matrices_ikj_750, measure_invocation);
	measure_invocation_750("IJK 750", multiply_matrices_ijk_750, measure_invocation);
	measure_invocation_800("SEQ_IKJ 800", multiply_matrices_ikj_800, measure_invocation);
	measure_invocation_800("IJK 800", multiply_matrices_ijk_800, measure_invocation);
	measure_invocation_850("SEQ_IKJ 850", multiply_matrices_ikj_850, measure_invocation);
	measure_invocation_850("IJK 850", multiply_matrices_ijk_850, measure_invocation);
	measure_invocation_900("SEQ_IKJ 900", multiply_matrices_ikj_900, measure_invocation);
	measure_invocation_900("IJK 900", multiply_matrices_ijk_900, measure_invocation);
	measure_invocation_950("SEQ_IKJ 950", multiply_matrices_ikj_950, measure_invocation);
	measure_invocation_950("IJK 950", multiply_matrices_ijk_950, measure_invocation);
	measure_invocation_1000("SEQ_IKJ 1000", multiply_matrices_ikj_1000, measure_invocation);
	measure_invocation_1000("IJK 1000", multiply_matrices_ijk_1000, measure_invocation);
	measure_invocation_1050("SEQ_IKJ 1050", multiply_matrices_ikj_1050, measure_invocation);
	measure_invocation_1050("IJK 1050", multiply_matrices_ijk_1050, measure_invocation);
	measure_invocation_1100("SEQ_IKJ 1100", multiply_matrices_ikj_1100, measure_invocation);
	measure_invocation_1100("IJK 1100", multiply_matrices_ijk_1100, measure_invocation);
	measure_invocation_1150("SEQ_IKJ 1150", multiply_matrices_ikj_1150, measure_invocation);
	measure_invocation_1150("IJK 1150", multiply_matrices_ijk_1150, measure_invocation);
	measure_invocation_1200("SEQ_IKJ 1200", multiply_matrices_ikj_1200, measure_invocation);
	measure_invocation_1200("IJK 1200", multiply_matrices_ijk_1200, measure_invocation);
	measure_invocation_1250("SEQ_IKJ 1250", multiply_matrices_ikj_1250, measure_invocation);
	measure_invocation_1250("IJK 1250", multiply_matrices_ijk_1250, measure_invocation);
	measure_invocation_1300("SEQ_IKJ 1300", multiply_matrices_ikj_1300, measure_invocation);
	measure_invocation_1300("IJK 1300", multiply_matrices_ijk_1300, measure_invocation);
	measure_invocation_1350("SEQ_IKJ 1350", multiply_matrices_ikj_1350, measure_invocation);
	measure_invocation_1350("IJK 1350", multiply_matrices_ijk_1350, measure_invocation);
	measure_invocation_1400("SEQ_IKJ 1400", multiply_matrices_ikj_1400, measure_invocation);
	measure_invocation_1400("IJK 1400", multiply_matrices_ijk_1400, measure_invocation);
	measure_invocation_1450("SEQ_IKJ 1450", multiply_matrices_ikj_1450, measure_invocation);
	measure_invocation_1450("IJK 1450", multiply_matrices_ijk_1450, measure_invocation);
	measure_invocation_1500("SEQ_IKJ 1500", multiply_matrices_ikj_1500, measure_invocation);
	measure_invocation_1500("IJK 1500", multiply_matrices_ijk_1500, measure_invocation);
	measure_invocation_50("IJK_IKJ 50_50", multiply_matrices_ijk_ikj_50_50, measure_invocation);
	measure_invocation_100("IJK_IKJ 100_50", multiply_matrices_ijk_ikj_100_50, measure_invocation);
	measure_invocation_100("IJK_IKJ 100_100", multiply_matrices_ijk_ikj_100_100, measure_invocation);
	measure_invocation_150("IJK_IKJ 150_50", multiply_matrices_ijk_ikj_150_50, measure_invocation);
	measure_invocation_150("IJK_IKJ 150_75", multiply_matrices_ijk_ikj_150_75, measure_invocation);
	measure_invocation_150("IJK_IKJ 150_150", multiply_matrices_ijk_ikj_150_150, measure_invocation);
	measure_invocation_200("IJK_IKJ 200_50", multiply_matrices_ijk_ikj_200_50, measure_invocation);
	measure_invocation_200("IJK_IKJ 200_100", multiply_matrices_ijk_ikj_200_100, measure_invocation);
	measure_invocation_200("IJK_IKJ 200_200", multiply_matrices_ijk_ikj_200_200, measure_invocation);
	measure_invocation_250("IJK_IKJ 250_50", multiply_matrices_ijk_ikj_250_50, measure_invocation);
	measure_invocation_250("IJK_IKJ 250_125", multiply_matrices_ijk_ikj_250_125, measure_invocation);
	measure_invocation_250("IJK_IKJ 250_250", multiply_matrices_ijk_ikj_250_250, measure_invocation);
	measure_invocation_300("IJK_IKJ 300_50", multiply_matrices_ijk_ikj_300_50, measure_invocation);
	measure_invocation_300("IJK_IKJ 300_60", multiply_matrices_ijk_ikj_300_60, measure_invocation);
	measure_invocation_300("IJK_IKJ 300_75", multiply_matrices_ijk_ikj_300_75, measure_invocation);
	measure_invocation_300("IJK_IKJ 300_100", multiply_matrices_ijk_ikj_300_100, measure_invocation);
	measure_invocation_300("IJK_IKJ 300_150", multiply_matrices_ijk_ikj_300_150, measure_invocation);
	measure_invocation_300("IJK_IKJ 300_300", multiply_matrices_ijk_ikj_300_300, measure_invocation);
	measure_invocation_350("IJK_IKJ 350_50", multiply_matrices_ijk_ikj_350_50, measure_invocation);
	measure_invocation_350("IJK_IKJ 350_70", multiply_matrices_ijk_ikj_350_70, measure_invocation);
	measure_invocation_350("IJK_IKJ 350_175", multiply_matrices_ijk_ikj_350_175, measure_invocation);
	measure_invocation_350("IJK_IKJ 350_350", multiply_matrices_ijk_ikj_350_350, measure_invocation);
	measure_invocation_400("IJK_IKJ 400_50", multiply_matrices_ijk_ikj_400_50, measure_invocation);
	measure_invocation_400("IJK_IKJ 400_80", multiply_matrices_ijk_ikj_400_80, measure_invocation);
	measure_invocation_400("IJK_IKJ 400_100", multiply_matrices_ijk_ikj_400_100, measure_invocation);
	measure_invocation_400("IJK_IKJ 400_200", multiply_matrices_ijk_ikj_400_200, measure_invocation);
	measure_invocation_400("IJK_IKJ 400_400", multiply_matrices_ijk_ikj_400_400, measure_invocation);
	measure_invocation_450("IJK_IKJ 450_50", multiply_matrices_ijk_ikj_450_50, measure_invocation);
	measure_invocation_450("IJK_IKJ 450_75", multiply_matrices_ijk_ikj_450_75, measure_invocation);
	measure_invocation_450("IJK_IKJ 450_90", multiply_matrices_ijk_ikj_450_90, measure_invocation);
	measure_invocation_450("IJK_IKJ 450_150", multiply_matrices_ijk_ikj_450_150, measure_invocation);
	measure_invocation_450("IJK_IKJ 450_225", multiply_matrices_ijk_ikj_450_225, measure_invocation);
	measure_invocation_450("IJK_IKJ 450_450", multiply_matrices_ijk_ikj_450_450, measure_invocation);
	measure_invocation_500("IJK_IKJ 500_50", multiply_matrices_ijk_ikj_500_50, measure_invocation);
	measure_invocation_500("IJK_IKJ 500_100", multiply_matrices_ijk_ikj_500_100, measure_invocation);
	measure_invocation_500("IJK_IKJ 500_125", multiply_matrices_ijk_ikj_500_125, measure_invocation);
	measure_invocation_500("IJK_IKJ 500_250", multiply_matrices_ijk_ikj_500_250, measure_invocation);
	measure_invocation_500("IJK_IKJ 500_500", multiply_matrices_ijk_ikj_500_500, measure_invocation);
	measure_invocation_550("IJK_IKJ 550_50", multiply_matrices_ijk_ikj_550_50, measure_invocation);
	measure_invocation_550("IJK_IKJ 550_55", multiply_matrices_ijk_ikj_550_55, measure_invocation);
	measure_invocation_550("IJK_IKJ 550_110", multiply_matrices_ijk_ikj_550_110, measure_invocation);
	measure_invocation_550("IJK_IKJ 550_275", multiply_matrices_ijk_ikj_550_275, measure_invocation);
	measure_invocation_550("IJK_IKJ 550_550", multiply_matrices_ijk_ikj_550_550, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_50", multiply_matrices_ijk_ikj_600_50, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_60", multiply_matrices_ijk_ikj_600_60, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_75", multiply_matrices_ijk_ikj_600_75, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_100", multiply_matrices_ijk_ikj_600_100, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_120", multiply_matrices_ijk_ikj_600_120, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_150", multiply_matrices_ijk_ikj_600_150, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_200", multiply_matrices_ijk_ikj_600_200, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_300", multiply_matrices_ijk_ikj_600_300, measure_invocation);
	measure_invocation_600("IJK_IKJ 600_600", multiply_matrices_ijk_ikj_600_600, measure_invocation);
	measure_invocation_650("IJK_IKJ 650_50", multiply_matrices_ijk_ikj_650_50, measure_invocation);
	measure_invocation_650("IJK_IKJ 650_65", multiply_matrices_ijk_ikj_650_65, measure_invocation);
	measure_invocation_650("IJK_IKJ 650_130", multiply_matrices_ijk_ikj_650_130, measure_invocation);
	measure_invocation_650("IJK_IKJ 650_325", multiply_matrices_ijk_ikj_650_325, measure_invocation);
	measure_invocation_650("IJK_IKJ 650_650", multiply_matrices_ijk_ikj_650_650, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_50", multiply_matrices_ijk_ikj_700_50, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_70", multiply_matrices_ijk_ikj_700_70, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_100", multiply_matrices_ijk_ikj_700_100, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_140", multiply_matrices_ijk_ikj_700_140, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_175", multiply_matrices_ijk_ikj_700_175, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_350", multiply_matrices_ijk_ikj_700_350, measure_invocation);
	measure_invocation_700("IJK_IKJ 700_700", multiply_matrices_ijk_ikj_700_700, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_50", multiply_matrices_ijk_ikj_750_50, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_75", multiply_matrices_ijk_ikj_750_75, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_125", multiply_matrices_ijk_ikj_750_125, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_150", multiply_matrices_ijk_ikj_750_150, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_250", multiply_matrices_ijk_ikj_750_250, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_375", multiply_matrices_ijk_ikj_750_375, measure_invocation);
	measure_invocation_750("IJK_IKJ 750_750", multiply_matrices_ijk_ikj_750_750, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_50", multiply_matrices_ijk_ikj_800_50, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_80", multiply_matrices_ijk_ikj_800_80, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_100", multiply_matrices_ijk_ikj_800_100, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_160", multiply_matrices_ijk_ikj_800_160, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_200", multiply_matrices_ijk_ikj_800_200, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_400", multiply_matrices_ijk_ikj_800_400, measure_invocation);
	measure_invocation_800("IJK_IKJ 800_800", multiply_matrices_ijk_ikj_800_800, measure_invocation);
	measure_invocation_850("IJK_IKJ 850_50", multiply_matrices_ijk_ikj_850_50, measure_invocation);
	measure_invocation_850("IJK_IKJ 850_85", multiply_matrices_ijk_ikj_850_85, measure_invocation);
	measure_invocation_850("IJK_IKJ 850_170", multiply_matrices_ijk_ikj_850_170, measure_invocation);
	measure_invocation_850("IJK_IKJ 850_425", multiply_matrices_ijk_ikj_850_425, measure_invocation);
	measure_invocation_850("IJK_IKJ 850_850", multiply_matrices_ijk_ikj_850_850, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_50", multiply_matrices_ijk_ikj_900_50, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_60", multiply_matrices_ijk_ikj_900_60, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_75", multiply_matrices_ijk_ikj_900_75, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_90", multiply_matrices_ijk_ikj_900_90, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_100", multiply_matrices_ijk_ikj_900_100, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_150", multiply_matrices_ijk_ikj_900_150, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_180", multiply_matrices_ijk_ikj_900_180, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_225", multiply_matrices_ijk_ikj_900_225, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_300", multiply_matrices_ijk_ikj_900_300, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_450", multiply_matrices_ijk_ikj_900_450, measure_invocation);
	measure_invocation_900("IJK_IKJ 900_900", multiply_matrices_ijk_ikj_900_900, measure_invocation);
	measure_invocation_950("IJK_IKJ 950_50", multiply_matrices_ijk_ikj_950_50, measure_invocation);
	measure_invocation_950("IJK_IKJ 950_95", multiply_matrices_ijk_ikj_950_95, measure_invocation);
	measure_invocation_950("IJK_IKJ 950_190", multiply_matrices_ijk_ikj_950_190, measure_invocation);
	measure_invocation_950("IJK_IKJ 950_475", multiply_matrices_ijk_ikj_950_475, measure_invocation);
	measure_invocation_950("IJK_IKJ 950_950", multiply_matrices_ijk_ikj_950_950, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_50", multiply_matrices_ijk_ikj_1000_50, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_100", multiply_matrices_ijk_ikj_1000_100, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_125", multiply_matrices_ijk_ikj_1000_125, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_200", multiply_matrices_ijk_ikj_1000_200, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_250", multiply_matrices_ijk_ikj_1000_250, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_500", multiply_matrices_ijk_ikj_1000_500, measure_invocation);
	measure_invocation_1000("IJK_IKJ 1000_1000", multiply_matrices_ijk_ikj_1000_1000, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_50", multiply_matrices_ijk_ikj_1050_50, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_70", multiply_matrices_ijk_ikj_1050_70, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_75", multiply_matrices_ijk_ikj_1050_75, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_105", multiply_matrices_ijk_ikj_1050_105, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_150", multiply_matrices_ijk_ikj_1050_150, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_175", multiply_matrices_ijk_ikj_1050_175, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_210", multiply_matrices_ijk_ikj_1050_210, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_350", multiply_matrices_ijk_ikj_1050_350, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_525", multiply_matrices_ijk_ikj_1050_525, measure_invocation);
	measure_invocation_1050("IJK_IKJ 1050_1050", multiply_matrices_ijk_ikj_1050_1050, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_50", multiply_matrices_ijk_ikj_1100_50, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_55", multiply_matrices_ijk_ikj_1100_55, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_100", multiply_matrices_ijk_ikj_1100_100, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_110", multiply_matrices_ijk_ikj_1100_110, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_220", multiply_matrices_ijk_ikj_1100_220, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_275", multiply_matrices_ijk_ikj_1100_275, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_550", multiply_matrices_ijk_ikj_1100_550, measure_invocation);
	measure_invocation_1100("IJK_IKJ 1100_1100", multiply_matrices_ijk_ikj_1100_1100, measure_invocation);
	measure_invocation_1150("IJK_IKJ 1150_50", multiply_matrices_ijk_ikj_1150_50, measure_invocation);
	measure_invocation_1150("IJK_IKJ 1150_115", multiply_matrices_ijk_ikj_1150_115, measure_invocation);
	measure_invocation_1150("IJK_IKJ 1150_230", multiply_matrices_ijk_ikj_1150_230, measure_invocation);
	measure_invocation_1150("IJK_IKJ 1150_575", multiply_matrices_ijk_ikj_1150_575, measure_invocation);
	measure_invocation_1150("IJK_IKJ 1150_1150", multiply_matrices_ijk_ikj_1150_1150, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_50", multiply_matrices_ijk_ikj_1200_50, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_60", multiply_matrices_ijk_ikj_1200_60, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_75", multiply_matrices_ijk_ikj_1200_75, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_80", multiply_matrices_ijk_ikj_1200_80, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_100", multiply_matrices_ijk_ikj_1200_100, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_120", multiply_matrices_ijk_ikj_1200_120, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_150", multiply_matrices_ijk_ikj_1200_150, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_200", multiply_matrices_ijk_ikj_1200_200, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_240", multiply_matrices_ijk_ikj_1200_240, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_300", multiply_matrices_ijk_ikj_1200_300, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_400", multiply_matrices_ijk_ikj_1200_400, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_600", multiply_matrices_ijk_ikj_1200_600, measure_invocation);
	measure_invocation_1200("IJK_IKJ 1200_1200", multiply_matrices_ijk_ikj_1200_1200, measure_invocation);
	measure_invocation_1250("IJK_IKJ 1250_50", multiply_matrices_ijk_ikj_1250_50, measure_invocation);
	measure_invocation_1250("IJK_IKJ 1250_125", multiply_matrices_ijk_ikj_1250_125, measure_invocation);
	measure_invocation_1250("IJK_IKJ 1250_250", multiply_matrices_ijk_ikj_1250_250, measure_invocation);
	measure_invocation_1250("IJK_IKJ 1250_625", multiply_matrices_ijk_ikj_1250_625, measure_invocation);
	measure_invocation_1250("IJK_IKJ 1250_1250", multiply_matrices_ijk_ikj_1250_1250, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_50", multiply_matrices_ijk_ikj_1300_50, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_52", multiply_matrices_ijk_ikj_1300_52, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_65", multiply_matrices_ijk_ikj_1300_65, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_100", multiply_matrices_ijk_ikj_1300_100, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_130", multiply_matrices_ijk_ikj_1300_130, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_260", multiply_matrices_ijk_ikj_1300_260, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_325", multiply_matrices_ijk_ikj_1300_325, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_650", multiply_matrices_ijk_ikj_1300_650, measure_invocation);
	measure_invocation_1300("IJK_IKJ 1300_1300", multiply_matrices_ijk_ikj_1300_1300, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_50", multiply_matrices_ijk_ikj_1350_50, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_54", multiply_matrices_ijk_ikj_1350_54, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_75", multiply_matrices_ijk_ikj_1350_75, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_90", multiply_matrices_ijk_ikj_1350_90, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_135", multiply_matrices_ijk_ikj_1350_135, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_150", multiply_matrices_ijk_ikj_1350_150, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_225", multiply_matrices_ijk_ikj_1350_225, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_270", multiply_matrices_ijk_ikj_1350_270, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_450", multiply_matrices_ijk_ikj_1350_450, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_675", multiply_matrices_ijk_ikj_1350_675, measure_invocation);
	measure_invocation_1350("IJK_IKJ 1350_1350", multiply_matrices_ijk_ikj_1350_1350, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_50", multiply_matrices_ijk_ikj_1400_50, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_56", multiply_matrices_ijk_ikj_1400_56, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_70", multiply_matrices_ijk_ikj_1400_70, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_100", multiply_matrices_ijk_ikj_1400_100, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_140", multiply_matrices_ijk_ikj_1400_140, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_175", multiply_matrices_ijk_ikj_1400_175, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_200", multiply_matrices_ijk_ikj_1400_200, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_280", multiply_matrices_ijk_ikj_1400_280, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_350", multiply_matrices_ijk_ikj_1400_350, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_700", multiply_matrices_ijk_ikj_1400_700, measure_invocation);
	measure_invocation_1400("IJK_IKJ 1400_1400", multiply_matrices_ijk_ikj_1400_1400, measure_invocation);
	measure_invocation_1450("IJK_IKJ 1450_50", multiply_matrices_ijk_ikj_1450_50, measure_invocation);
	measure_invocation_1450("IJK_IKJ 1450_58", multiply_matrices_ijk_ikj_1450_58, measure_invocation);
	measure_invocation_1450("IJK_IKJ 1450_145", multiply_matrices_ijk_ikj_1450_145, measure_invocation);
	measure_invocation_1450("IJK_IKJ 1450_290", multiply_matrices_ijk_ikj_1450_290, measure_invocation);
	measure_invocation_1450("IJK_IKJ 1450_725", multiply_matrices_ijk_ikj_1450_725, measure_invocation);
	measure_invocation_1450("IJK_IKJ 1450_1450", multiply_matrices_ijk_ikj_1450_1450, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_50", multiply_matrices_ijk_ikj_1500_50, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_60", multiply_matrices_ijk_ikj_1500_60, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_75", multiply_matrices_ijk_ikj_1500_75, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_100", multiply_matrices_ijk_ikj_1500_100, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_125", multiply_matrices_ijk_ikj_1500_125, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_150", multiply_matrices_ijk_ikj_1500_150, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_250", multiply_matrices_ijk_ikj_1500_250, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_300", multiply_matrices_ijk_ikj_1500_300, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_375", multiply_matrices_ijk_ikj_1500_375, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_500", multiply_matrices_ijk_ikj_1500_500, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_750", multiply_matrices_ijk_ikj_1500_750, measure_invocation);
	measure_invocation_1500("IJK_IKJ 1500_1500", multiply_matrices_ijk_ikj_1500_1500, measure_invocation);
}
