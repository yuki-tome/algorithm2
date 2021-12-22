#include<stdio.h>
#include<stdlib.h>

int positive_integer(int *i,int n,int s,int add_s);

int *bin;
int cnt;

int main(){
	int *integer;
	int i;
	int num;
	int sum;

	scanf("%d",&num);//n

	cnt=num;
	bin=malloc(num * sizeof(int));
	integer=malloc(num * sizeof(int));

	scanf("%d",&sum); //b

	for(i=0;i<num;i++){
		scanf("%d",&integer[i]);//ai
	}

	if(positive_integer(integer,num,sum,0)==1){

		printf("YES\n");
		for(i=0;i<num;i++){
			if(bin[i]==1){
				printf("%d ",integer[i]);
			}
		}
		printf("\n");
	}

	else{
		printf("NO\n");
	}

	free(integer);

	return 0;
}

int positive_integer(int *integer,int num,int sum,int add_sum)
{

	if(num==0)
	{
		if(sum==add_sum) return 1;
		return 0;
	}

	bin[cnt-num]=0;
	if(positive_integer(integer+1,num-1,sum,add_sum)) return 1;

	bin[cnt-num]=1;
	return(positive_integer(integer+1,num-1,sum,add_sum+ *integer));
}
