/*

author : Yuki Tome
id     : s1270036

*/
#include <stdio.h>
#include <stdlib.h>

/* Complete Here !! (Variables Declaration) */
static int x=1;
# define A 48271L
# define M 2147483647L
# define Q (M/A)
# define R (M%A)

int next_rnd2(void);

int data[100];

int main() {
    int getrand, i;

    for(i = 0; i < 1000; i++) {
        getrand = next_rnd2()%30;
        printf("%d: %d\n", i + 1, getrand);
        data[getrand]++;
    }

    for(i=0;i<30;i++) printf("%d ",data[i]); // sample for listing outputs
    printf("\n");
    return 0;
}

int next_rnd2(void) { 
    /* Complete Here !! */
    x = A * (x%Q) - R * (x/Q);
    if (x<0){
        x = x + M;
    }
    return x;
}