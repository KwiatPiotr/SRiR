//#include <omp.h>
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	int numprocs, rank, namelen;
	int iam = 0, np = 1;
    char name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &namelen);
	{
    //np = omp_get_num_threads();
    //iam = omp_get_thread_num();
    printf("Hello from thread %d out of %d from process %d out of %d on %s\n",
           iam, np, rank, numprocs, name);
	}

	MPI_Finalize();
}

