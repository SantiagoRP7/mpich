#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "mpi.h"

int main(){

        int size, rank, dest, source, tag=0;
        int inmsg, outmsg= 8080 ;
        MPI_Init(NULL, NULL);
        MPI_Status Stat;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        if (rank == 0) {
                for (dest=1;dest<size;dest ++ ) {
                        MPI_Send(&outmsg, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
                }
        }else {
        source = 0;
        MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
        printf("DATA :  %d!\n",inmsg);
        }

        MPI_Finalize();

  return(0);
}
