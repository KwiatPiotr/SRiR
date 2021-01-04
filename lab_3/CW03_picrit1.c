//https://github.com/thaink/OpenMP_Exercises/blob/master/5_pi_smp_critical.c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


static long num_steps = 1000000000;
double step;

int main(int argc, char *argv[])
{
	int ile;
	double pi, sum = 0.0, t1, t2;
	step = 1.0 / (double)num_steps;
	if (argc >= 2)
	{
		ile = atoi(argv[1]);
	}


	t1 = omp_get_wtime();
	omp_set_num_threads(ile);
#pragma omp parallel
	{
		int i, id, nthrds; double x, s = 0.0;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		for (i = id; i < num_steps; i = i + nthrds) {
			x = (i + 0.5)*step;
			s = s + 4.0 / (1.0 + x * x);
		}
#pragma omp critical
		sum += s;
	}
	pi = sum * step;
	t2 = omp_get_wtime();
	printf("%d   Watki   ", ile);
	printf("finished in %f milisecond    ", (t2 - t1) * 1000);
	printf("pi: %f \n", pi);
	
}