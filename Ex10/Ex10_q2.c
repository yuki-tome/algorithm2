 #include<stdio.h>
#include<stdlib.h>

int product(int *value, int number, int sum, int sum2);
int *bin;
int count;
int number2;

int main(){
	int *value;
	int number,i;
	int sum;

	scanf("%d", &number); //整数の個数
	scanf("%d", &sum); //合計

	bin = malloc(number * sizeof(int));
	
	count = number;
	
	value = malloc(number * sizeof(int));
	for(i=0; i<number; i++){
		scanf("%d", &value[i]);
	}

	if(product(value+number, number, sum,0) == 1) {
		printf("YES\n");
		for(i=0;i<number;i++){
			if(bin[i]==1){
				printf("%d ",value[i]);
			}
		}
	}
	else {
		printf("NO\n");
	}
	free(value);

	return 0;
}

int product(int *value, int number, int sum, int sum2)
{
	if(number == 0){
		if(sum2 == sum) return 1;
		return 0;
	}

	bin[number]=0;
	if(product(value-1,number-1,sum,sum2)) return 1;
	bin[number]=1;
	return (product(value-1,number-1,sum,sum2+*value));
}
