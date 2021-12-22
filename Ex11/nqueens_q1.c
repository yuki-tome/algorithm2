/*

  author : Yuki Tome
  id     : s1270036

*/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0
#define N  10

int try(int);

int row[N], col[N], pos[2 * N - 1], neg[2 * N - 1];
int count = 0;

int main() {
    int i, j;

    for(i = 0; i < N; i++) {
        row[i] = -1;
        col[i] = FREE;
    }
    for(i = 0; i < 2 * N - 1; i++) {
        pos[i] = FREE;
        neg[i] = FREE;
    }
     try(0);
     
     printf("The number of solutions is %d.\n",count);

    return 0;
}

int try(int i) {
        int j,k,flag;

        for(j = 0; j < N; j++) {
            if(col[j] == FREE && pos[i + j] == FREE && neg[i - j + N - 1] == FREE) {
                row[i] = j;
                col[j] = NOT_FREE;
                pos[i + j] = NOT_FREE;
                neg[i - j + N - 1] = NOT_FREE;

                if(i >= N - 1){
                    for(k=0,flag=0;k<N;k++) {
                        if(row[k]!=-1) flag++;
                    }
                    if(flag==N) {
                        count++;
                    }
                    row[i]=-1;
                    col[j]=FREE;
                    pos[i+j]=FREE;
                    neg[i-j+N-1]=FREE;
                    try(i+1);
                }
                else {
                    if(try(i + 1) == SUCCESS)
                        return SUCCESS;
                    else {
                        row[i] = -1;
                        col[j] = FREE;
                        pos[i + j] = FREE;
                        neg[i - j + N - 1] = FREE;
                    }
                }
            }
        }
        return FAIL;
    }
