#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i, j;
	double start, stop, czas,suma;
	static double x[10000][10000];
	suma = 0;
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 10000; j++)
			x[i][j] = i + j;
	start = omp_get_wtime();
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 10000; j++)
			suma = suma + x[i][j];
	stop = omp_get_wtime();
	czas = stop - start;
	printf(" %f     czas  %f\n ", suma, czas);
	suma = 0;
	start = omp_get_wtime();
	for (i = 0; i < 10000; i++)
		for (j = 0; j < 10000; j++)
			suma = suma + x[j][i];
	stop = omp_get_wtime();
	czas = stop - start;
	printf(" %f     czas  %f \n", suma, czas);

}	
