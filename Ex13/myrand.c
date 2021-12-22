/*

author : Yuki Tome
id     : s1270036

*/

#include <stdio.h>
#include <time.h>

/* Complete Here !! (Macro Definitions)*/
static int next=0;
/* Complete Here !! (Variables Declaration) */
static int x=1;

#define A 48271L
#define M 2147483647L
#define Q (M/A)
#define R (M%A)

int next_rnd2(void);
int my_GetRand(void);
void init_rnd(void);
void my_srand(void);

int data[100];
int data1[30];

/* int main() {
    int getrand, i;

    init_rnd();

    for(i = 0; i < 1000; i++) {
        getrand = my_GetRand()%30;
        printf("%d: %d\n", i + 1, getrand);
        data1[getrand]++;
    }
    for(i=0;i<30;i++) printf("%d ",data1[i]); // sample for listing outputs
    printf("\n");
    return 0;
} */

void init_rnd(void) {
    int i;/* Complete Here !! */
    for(i = 0; i < 55; i++) {
        data[i]=next_rnd2();
    }
}

int my_GetRand(void) { /* Complete Here !!*/
    int i, j, x2;
  i = (next+31) % 55;
  x2 =(data[i]-data[next]);
  if (x2<0) {
    x2 += 2147483647;
    x2 += 1;
  }
  data[next] = x2;
  next = (next+1) % 55;

  return x2;
}

int next_rnd2(void) { /* Complete Here !! (same as rnd2.c) */
    x = A * (x%Q) - R * (x/Q);
    if (x<0){
    x = x+M;
    }
    return x;
}

 
void my_srand(void){
  time_t stamp;
  struct tm *t;
  stamp = (int)time(NULL);
  t = localtime(&stamp);
  x = t->tm_sec; // seed
  init_rnd();
}
