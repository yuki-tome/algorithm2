/*

name : Yuki Tome
id     : s1270036

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INFTY 99999

int main(){
  int i,j;
  int pay, num;
  int *dp;
  int *coin;

  printf("How much do you pay?\n");
  scanf("%d",&pay);

  dp=(int *)malloc((pay+1)*sizeof(int));

  printf("How many coins do you spend?\n");
  scanf("%d",&num);

  coin=(int *)malloc((num+1)*sizeof(int));

  printf("Which coins do you use?\n");

  coin[0] = 0;
  for(i = 1; i <= num; i++){
    scanf("%d",&coin[i]);
  }

  for(i = 0; i <= pay; i++) {
    dp[i] = INFTY;
  }

  dp[0] = 0;

  for(i = 0; i < num; i++){
    if(coin[i] <= pay) {
      dp[coin[i]] = 1;
    }
  }

  for(i = 1; i <= num; i++){
    for(j = 0; j + coin[i] <= pay; j++){
      dp[j+coin[i]] = fminf(dp[j+coin[i]],dp[j]+1);
    }
  }

  printf("number of coins: %d\n",dp[pay]);
  return 0;
}
