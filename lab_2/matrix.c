#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define CHUNKSIZE   10
#define N       100


int main (int argc, char *argv[]) {
	if (argc != 5){
		printf("usage:\n\tn, m, p -> matrix size\n\tnthreads -> number of threads used by program\n");
		return -1;
	}

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	int p = atoi(argv[3]);
	int threads_count = atoi(argv[4]);
	int tid, i, j, k;
	double time1, time2;
	
	static double A[5000][5000];
	static double B[5000][5000];
	static double C[5000][5000];

	omp_set_num_threads(threads_count);

	for ( i = 0 ; i < n ; i++ ){
		for ( j = 0 ; j < m ; j++ ){
			A[i][j] = (double)(i + j);
		}
	}
	
	for ( i = 0 ; i < m ; i++ ){
		for ( j = 0 ; j < p ; j++ ){
			B[i][j] = (double)(i * j);
		}
	}

	for ( i = 0 ; i < n ; i++ ){
		for ( j = 0 ; j < p ; j++ ){
			C[i][j] = 0;
		}
	}

	/*
	for (int i = 0 ; i < m ; i++ ){
		for ( int j = 0 ; j < p ; j++ ){
			printf("%f ", C[i][j]);
		}
		printf("\n");
	}
	*/
	
	time1 = omp_get_wtime();
	#pragma omp parallel shared(A, B, C, n, m, p, threads_count) private(i, j, tid)
	{
		tid = omp_get_thread_num();
		if (tid == 0){
			threads_count = omp_get_num_threads();
			//printf("Number of threads = %d\n", threads_count);
		}

		#pragma omp for schedule(static)
		for ( i = 0 ; i < n ; i++ ){
			for ( j = 0 ; j < m ; j++ ){
				for ( k = 0 ; k < p ; k++ ){
					C[i][j] += (A[i][k] * B[k][j]);
				}
			}
		}
	}  
	time2 = omp_get_wtime();
	printf("%f\n", (time2-time1));
	/*
	for (int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < m ; j++ ){
			printf("%f ", C[i][j]);
		}
		printf("\n");
	}
	*/
}
