/*

author : your name
id     : your id

*/


#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int Floyd(int, int, int);

int main() {
    int i, j, k;

    int **Data, n;
    int **d;

    /* input data (size) */
    printf("Input the number of data: ");
    scanf("%d", &n);

    /* Generate arrays (memory allocation)*/
    Data = (int **)malloc(n * sizeof(int *));
    d = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++) {
        Data[i] = (int *)malloc(n * sizeof(int));
        d[i] = (int *)malloc(n * sizeof(int));
    }

    // 初期化
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            d[i][j] = INFTY;
        }
    }
    /* input data (matrix)*/
    printf("Input the Adjacency or Distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &Data[i][j]);
        }
    }

    /* Main routines */
    /* [ Complete Here!! ( 3-level nested loop) ] */
       for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                /* [ Complete Here!! ( 3-level nested loop) ] */
                /* Call main routines */
                Data[i][j] = Floyd(Data[i][j], Data[i][k], Data[k][j]); // Floyd's Algorithm
            }
        }
    }
    // end 3-level nested loop

    /* Output */
  int dmax = -INFTY; int vmax1,vmax2;  //For Problem 2-B
  int dmin = INFTY;  int vmin1,vmin2;


  for(i=0;i<n;i++){

    //printf("%3d: ",i+1);

    for(j=0;j<n;j++){

      //printf("%d ",Data[i][j]); // For Warshall's Algortihm


      if(Data[i][j]<INFTY){
        printf("%4d ",Data[i][j]);


        if(Data[i][j] > dmax){ //For Problem 2-B
          dmax = Data[i][j];
          vmax1 = i+1;
          vmax2 = j+1;
        }

        if(Data[i][j] < dmin && Data[i][j]!=0){ //For Problem 2-B
          dmin = Data[i][j];
          vmin1 = i+1;
          vmin2 = j+1;
        }

      }
      else printf("---- "); // For Floyd's Algorithm

    }
    printf("\n");
  } // For test




  printf("\n Max Distance: %d  e=(%d,%d)\n" , dmax,vmax1,vmax2);
  printf("\n Min Distance: %d  e=(%d,%d)\n" , dmin,vmin1,vmin2);


  /*
  puts("Unreachable v:");
  for(i=0; i<n; i++){
  for(j=0; j<n; j++){
  if(Data[j][i]!=0)break;
}

if( j == n ){
printf("%d\n",i+1);
}
}
// For Problem 2-A
*/


MST_view(Data,d,n);  //For Problem 2-C






    /* free allocated memory*/
    for(i = 0; i < n; i++) {
        free(Data[i]);
        free(d[i]);
    }
    free(Data);
    free(d);

    return 0;
}

int Floyd(int D_ij, int D_ik, int D_kj) {
    /* Arguments D_ij, D_ik, D_kj means D^{k-1}[i][j], D^{k-1}[i][k],D^{k-1}[k][j] at the pseudo code. */
    int Dk_ij; /* D^k[i][j] */

    Dk_ij = min(D_ij , D_ik + D_kj);/* [ Complete Here!! ] */;

    return Dk_ij;
}
