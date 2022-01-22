/*
12171029 Ka Shouen
 */

#include<stdio.h>
#include<math.h>



int main(void){
    int num=100;
    int cal=0;
    int Prime=1;

    /*
    do{
        scanf("%d",&num);
    }while( num < 2 || num > 100);
     */

    for(int i = 2; i <= num; i++){
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                Prime = 0;
                break;
            }
        }

        if(Prime == 1){
            cal++;
            printf("%4d",i);
        }

        Prime = 1;

        if(cal == 10){
            printf("\n");
            cal = 0;
        }
    }

    printf("\n");

    return 0;
}