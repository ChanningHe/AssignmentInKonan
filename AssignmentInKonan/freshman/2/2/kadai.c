// 12171029 Ka Shouen

#include "stdio.h"


int main(void)
{
    double d, v1, v2, advV;
    printf("目的地までの距離d[km]： ");
    scanf("%lf", &d);
    printf("往路の移動速度v1[km/h]： ") ;
    scanf("%lf", &v1); 
    printf("往路の移動速度v2[km/h]： ");
    scanf("%lf", &v2);
    advV = 2*d/(d/v1 + d/v2);
    printf("%lf\n", advV);
    return 0;
}
