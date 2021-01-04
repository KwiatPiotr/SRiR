#include <mpi.h>
#include <time.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    int rang, procesus;
    double start, end, max_end = 0;
	MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rang);
    MPI_Comm_size(MPI_COMM_WORLD, &procesus);
    MPI_Barrier(MPI_COMM_WORLD);
    start = MPI_Wtime();
    printf("Starting time of process n. %d %f\n",rang, start);
    if(rang==0){
        //Master work
    }else{
        //slaves work
    }
    MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();
    printf("Ending time of process %d %f\n",rang, end);
	 printf("Execution time of process %d %f\n\n\n",rang, end-start);
    MPI_Finalize(); 
    return 0;
}