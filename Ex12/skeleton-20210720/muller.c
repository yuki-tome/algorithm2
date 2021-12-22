#include <stdio.h>
#include <time.h>
#include <math.h>

#define N 1000000


extern int my_GetRand(void);
extern void my_srand(void);

double box_muller(double, double);

int main(){
    int i, count[9] = {0};
    static double data[N] = {0};
    static double muller[N] = {0};
    int max=0;

    my_srand();

    for(i=0;i<N;i++){
        data[i] = my_GetRand();
        if(data[i] > max){
            max = data[i];
        }
    }
    for(i=0;i<N;i++){
        data[i] /= max;
        printf("%d: %f\n", i+1, data[i]);
    }

    for(i=1;i<N;i++){
        muller[i] = box_muller(data[i-1], data[i]);
        if(-4 <= muller[i] && muller[i] < -3) count[0]++;
        else if(muller[i] < -2) count[1]++;
        else if(muller[i] < -1) count[2]++;
        else if(muller[i] < 0) count[3]++;
        else if(muller[i] < 1) count[4]++;
        else if(muller[i] < 2) count[5]++;
        else if(muller[i] < 3) count[6]++;
        else if(muller[i] < 4) count[7]++;
    }

    for(i=0;i<8;i++){
        printf("From μ%+dσ to μ%+dσ: %6d ( %6.3f%%)\n", i-4, i-3, count[i], (double)count[i]/N*100);
    }
    return 0;
}

double box_muller(double x1, double x2){
    return sqrt(-2 * log(x1)) * cos(2 * M_PI * x2);
}