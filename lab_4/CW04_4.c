//Znajdowanie pola kola metoda Monte Carlo 
// wersja sekwencyjna
//polega na zliczaniu punktow spelniajacych r�wnanie x^2+y^2<r^2
// Przyjeto r=1
#include <time.h>
#include <stdio.h>
#include <mpi.h>


int main(int argc, char *argv[]){
	int start, stop, czas;
	int ile;			// liczba punkt�w w jednej osi (lacznie ile*ile punktow)
	int i,j;
	double x,y,d;
	double r2, pi, pisuma;
	double s,s1;		// double ze wzgledu na zakres (mozna uzyc _int64)
	ile=100000;
	
	int thread_count, thread_id, first, last;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &thread_count);
	MPI_Comm_rank(MPI_COMM_WORLD, &thread_id);
	first = thread_id * ile / thread_count;
	last = (thread_id + 1) * ile / thread_count;

	
	d=1.0/(double)ile;
	s1=0;

	MPI_Barrier(MPI_COMM_WORLD);
	start = MPI_Wtime();
	
	for (i = first ; i < last ; i++){
		for (j = 0 ; j < ile ; j++){
			x = d * i;
			y = d * j;
			r2 = x * x + y * y;
			if (r2 < 1){
				s1++;
			}
		}
	}

	s=(double)ile*(double)ile;
	pi=s1/s*4;// s1 dotyczy pola wycinka 1/4 kola o promieniu 1
	MPI_Reduce(&pi, &pisuma, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	stop = MPI_Wtime();

	if(thread_count == 1){
		printf("\n");
	}

	if(thread_id == 0){
		printf("\ns1 %15.12f\n",s1);
		printf("\ns %15.12f\n",s);
		printf("\n pole %15.12f\n",pi);
		//------------
		czas=stop-start;
		printf("\n czas %d  ms \n",czas);
	}
	MPI_Finalize();
}
