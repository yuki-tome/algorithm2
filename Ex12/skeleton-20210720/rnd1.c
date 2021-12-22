/*

author : Yuki Tome
id     : s1270036

*/

#include <stdio.h>
#include <stdlib.h>

/* Complete Here !! (Variables Declaration) */
int x = 53402397;

int next_rnd1(void);

int data[100];

int main() {
    int getrand, i;

    for(i = 0; i < 1000; i++) {
        getrand = next_rnd1()%30;
        printf("%d: %d\n", i + 1, getrand);
        data[getrand]++;
    }

    for(i=0;i<30;i++) printf("%d ",data[i]); // sample for listing outputs
    printf("\n");
    return 0;
}

int next_rnd1(void) {
     /* Complete Here !!*/
    x = (x * 65539 + 125654);

    if( x < 0 ){
        x += 2147483647;
        x += 1;
    }

    return x;

}
