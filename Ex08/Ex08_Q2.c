#include<stdio.h>

int main(){

  const int cent[]={25,10,5,1};  //cent value
  int num[4];  //コイン数
  int cent_pay[4]={ 0 };
  int price;   //値段
  int amount = 0; //支払った金額
  int count = 0;
  int i;


  printf("Input numbers of each cent(coin).\n-> ");
  for(i = 0; i < 4; i++) scanf("%d",&num[i]);

  printf("Input how many cents should you pay?\n-> ");
  scanf("%d",&price);


  while((count < 4) && (price != 0)){
    if((num[count] <= 0) || (price < cent[count])) count++;
    else{
      price -= cent[count];
      amount  += cent[count];
      num[count]--; //コインの数をひく
      cent_pay[count]++; //使用したコインを数える
    }
  }

  if(price == 0){
    for(i = 0; i < 4; i++){
      printf("[%dcent] %d cent_pay.\n", cent[i], cent_pay[i]);
    }
    printf("Totally, you cent_pay %d coins for %d cents.\n",cent_pay[0] + cent_pay[1] + cent_pay[2] + cent_pay[3], amount);
  }
  else{
    printf("Error: you cannot pay for this value.\n");
  }
  return 0;
}
