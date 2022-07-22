#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NUM 5000
#define PAI    3.14159265358979
double bm_rand( double m, double sig );

int main(){
    int cnt[15]={0};
    int n, tmp;
    double r;

    for(int i=0;i<NUM;i++){
        r = bm_rand(7.5, 1.5); 
        tmp = (int)r;
        if(tmp<15) cnt[tmp]++;
    }

    for(int i=0;i<15;i++){
        n = cnt[i]/50;
        printf("*");
        for(int j=0;j<n;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

double bm_rand( double m, double sig )
{
    static double r1,r2;
    static int flag = 1;
    double ret;

    if( flag ){
        r1 = rand()/((double)RAND_MAX); // 0.0～1.0の一様乱数
        r2 = rand()/((double)RAND_MAX);
        ret = sig*sqrt(-2*log(r1))*cos(2*PAI*r2) + m;
    }else{
        ret = sig*sqrt(-2*log(r1))*sin(2*PAI*r2) + m;
    }
    flag = 1 - flag; // flag=1,0を交互に
    return ret;
}
