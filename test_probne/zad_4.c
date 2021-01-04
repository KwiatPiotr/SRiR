#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
	int MAX;
	int i;
	int incr;
	int A[100];
	MAX = 100;
	incr = 5;

	#pragma omp parallel for firstprivate(incr)
	for ( i = 0 ; i < MAX ; i++ ){
		if (i % 2 == 0) incr ++;
		A[i] = incr;
	}

	for ( i = 0 ; i < MAX ; i++){
		printf("%d", A[1]);
	}

	return 0;
}

