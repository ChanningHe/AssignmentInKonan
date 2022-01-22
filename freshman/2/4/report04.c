/*
 12171029 KaShouen
 */

#include<stdio.h>

int main(){
    int num;
    int Fx=1,Fy=0,sum;
    do{
        printf("\n");
        printf("Input num(2<=num<=20)?: ");
        scanf("%d",&num);
        printf("Your input number --> %d\n",num);
    }while(num < 2 || num > 20);

    printf("F(0) = 0\n");
    printf("F(1) = 1\n");

    for(int i=2;i<=num;i++){
        sum=Fx+Fy;
        printf("F(%d) : F(%d) + F(%d) -->  %d + %d = %d\n",i,i-1,i-2,Fx,Fy,sum);
        Fy=Fy+Fx;Fx=Fy-Fx;Fy=Fy-Fx;
        Fx=sum;
    }

    return 0;
}