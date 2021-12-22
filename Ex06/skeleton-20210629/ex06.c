/*

author : Yuki Tome
id     : s1270036

*/
#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

int Warshall(int,int,int);
int Floyd(int,int,int);

int max_max(int,int,int);

void MST(int **D0,int **dn,int n);
int Maggs_Plotkin(int,int,int);


int main(){
  int i,j,k;

  int **Data,n;
  int **d;


  /* input data (size) */
  printf("Input the number of data: ");
  scanf("%d", &n);

  /* Generate arrays (memory allocation)*/
  Data = (int **)malloc(n*sizeof(int *));
  for(i=0;i<n;i++) Data[i] = (int *)malloc(n*sizeof(int));
  d = (int **)malloc(n*sizeof(int *));
  for(i=0;i<n;i++) d[i] = (int *)malloc(n*sizeof(int));

  /* input data (matrix)*/
  printf("Input the Adjacency or Distance matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &Data[i][j]);
      d[i][j] = Data[i][j];
    }
  }

  /* Main routines */
  for(k=0; k<n; k++){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        /* Call main routines */
        //Data[i][j] = Warshall(Data[i][j],Data[i][k],Data[k][j]); // Warshall's Algorithm
        //Data[i][j] = Floyd(Data[i][j],Data[i][k],Data[k][j]);  //Floyd's Algorithm

        if(Data[i][j] == 257){
          printf("i:%d  j:%d  k:%d\n",i,j,k);
        }
        // Maggs Plotkin Algorithm <MSTを得る処理のために、入力データData[][]とは別途d[][]を作成することを勧める>
        d[i][j] = Maggs_Plotkin(d[i][j],d[i][k],d[k][j]);


      }
    }
  }

  /* Output */
  int dmax = -INFTY; int vmax1,vmax2;  //For Problem 2-2
  int dmin = INFTY;  int vmin1,vmin2;


  for(i=0;i<n;i++){

    for(j=0;j<n;j++){
      //printf("%d ",Data[i][j]); // For Warshall's Algortihm

      if(Data[i][j]<INFTY){
        printf("%4d ",Data[i][j]);

        //For Problem 2-2
        if(Data[i][j] > dmax){ 
          dmax = Data[i][j];
          vmax1 = i+1;
          vmax2 = j+1;
        }

        if(Data[i][j] < dmin && Data[i][j]!=0){ 
          dmin = Data[i][j];
          vmin1 = i+1;
          vmin2 = j+1;
        }

      }
      else printf("---- "); 
      //2-2

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
// For Problem 2-1
*/

MST(Data,d,n);  //For Problem 2-3

/* free allocated memory*/
for( i = 0 ; i < n ;i++)  free(Data[i]);
free(Data);

return 0;
}

/* Kernel process of Floyd's & Warshall's Algorithm */

int Warshall(int A_ij,int A_ik,int A_kj){
  /* Arguments A_ij, A_ik, A_kj means A^{k-1}[i][j], A^{k-1}[i][k],A^{k-1}[k][j] at the pseudo code. */
  int Ak_ij; /* A^k[i][j] */

  Ak_ij =  A_ij | (A_ik & A_kj) ;

  return Ak_ij;
}

int Floyd(int D_ij,int D_ik,int D_kj){
  /* Arguments D_ij, D_ik, D_kj means D^{k-1}[i][j], D^{k-1}[i][k],D^{k-1}[k][j] at the pseudo code. */
  int Dk_ij; /* D^k[i][j] */

  Dk_ij = fmin(D_ij , D_ik + D_kj);

  return Dk_ij;
}

int Maggs_Plotkin(int D_ij,int D_ik,int D_kj){
  int Dk_ij;

  Dk_ij = fmin(D_ij , max_max(D_ik,0,D_kj));

  return Dk_ij;
}

int max_max(int x,int y,int z){
  if(fmax(x,y) < z)return z;
  return fmax(x,y);
}


//D0[][] -> 元の2次元配列。つまり隣接行列A
//dn[][] -> アルゴリズムで処理された2次元配列。つまりA^k
//n -> グラフの頂点数|V|
void MST(int **D0,int **dn,int n){
  int i,j;
  int costs=0;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){//A上で辺があったところが、A^kの全域木に採用されているなら重みを加える
      if(D0[i][j]==dn[i][j] && D0[i][j]!=INFTY){ costs += dn[i][j];
        printf("adopted(%d,%d)  cost:%d   (Data: %d  d: %d)\n",i,j,dn[i][j],D0[i][j],dn[i][j]);
      }
    }
  }
  printf("MST total weights:%d\n",costs);
}

