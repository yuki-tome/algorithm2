/*

author : Yuki Tome
id     : s1270036

*/


#include <stdio.h>
#include <stdlib.h>

int try(int, int);
int n, b;
int *mass;
int count = 0;


int main() {


  int i, j;

  scanf("%d %d",&n, &b);

  a = (int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d",&mass[i]);
  }

  try(0, 0);

  printf("Total is %d\n",count);

  return 0;
}



int try(int i, int number) {

  if(i>=n) {
    if(number==b) {
    count++;
  }
} else if(i==0) {
    try(1, number+mass[i]);
  } else {
    try(i+1, number+mass[i]);
    try(i+1, number-mass[i]);
  }
  return 0;

}
