#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	double step;
	int i, nthreads;
	double pi, sum;
	double x;
	int ile;
	int num_steps;

	num_steps = 20000;
	step = 1.0/(double) num_steps;
	sum=0.0;
	
	int thread_count, thread_id, first, last;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &thread_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &thread_id);
	//MPI_Bcast(&thread_count, 1, MPI_INT, 0, MPI_COMM_WORLD);

	first = thread_id * num_steps / thread_count;
	last = (thread_id + 1) * num_steps / thread_count;

	double subsum = 0.0;
	double total = 0.0;
	double d;
	for (i = first ; i < last ; i++){
		x = (i + 0.5) * step;
		d = 4.0 / (1.0 + x * x);
		subsum += d;
	}
	
	MPI_Reduce(&subsum, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (thread_id == 0){
		//pi = sum * step;
		pi = total ;
		printf(" pi  %f    ",pi);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
}
