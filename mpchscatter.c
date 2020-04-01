#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "mpi.h"

int main(){

        int size, rank, dest, source, tag=0;
        int outmsg[4]={8,0,8,0} ;
        MPI_Init(NULL, NULL);
        MPI_Status Stat;
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        int size_outmsg = sizeof outmsg / sizeof outmsg[0];
        int n = size_outmsg/size;
        int inmsg[n];

        if (rank == 0) {
                for (dest=1;dest<size;dest ++ ) {
                        MPI_Send(&outmsg[dest], n, MPI_INT, dest, tag, MPI_COMM_WORLD);
                }
        }else {
                source = 0;
                MPI_Recv(&inmsg, n, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
               for (int i=0;i<n;i++ ) {
                 printf("DATA :  %d!\n",inmsg[i] );}
        }

        MPI_Finalize();

  return(0);
}
