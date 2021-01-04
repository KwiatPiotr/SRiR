#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int start, stop, czas;
	long num_steps;
	double step;
	int i, nthreads; double pi, sum;
	double x;
	int ile;
	if (argc >= 2)
	{
		ile = atoi(argv[1]);
	}

	start = clock();  // za start zostanie wstawiony czas w milisekundach od momentu wlaczenia programu
	num_steps = 200000000;
	step = 1.0 / (double)num_steps;
	sum = 0.0;
	omp_set_num_threads(ile);
#pragma omp parallel for private(x) shared(sum)
	for (i = 0; i < num_steps; i++)
	{
		x = (i + 0.5)*step;
#pragma omp critical
		{
			sum += 4.0 / (1.0 + x * x);
		}
	}
	pi = sum * step;
	stop = clock();
	czas = stop - start;
	printf("\ watki   %d   czas %d  ms", ile, czas);

	printf("            pi  %f   \n ", pi);
}