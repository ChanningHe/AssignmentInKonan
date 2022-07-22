/*
12171029 KaShouen
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM 5000


double exp_rand(double m)
{
    double r = (double)rand()/((double)RAND_MAX+1.0); // 0以上1未満の一様乱数
    double x = -m*log(1.0-r); 
    return x;
}

int main(void)
{
    int i,j,n;
    int cnt[15];
    double r;

    srand((unsigned int)time(NULL));

    for(i=0;i<15;i++) cnt[i] = 0;
    for(i=0;i<NUM;i++){
        r = exp_rand(3.0); 
        j = (int)r;
        if(j<15) cnt[j]++;
    }

    for(i=0;i<15;i++){
        n = cnt[i]/50;
        printf("*");
        for(j=0;j<n;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}