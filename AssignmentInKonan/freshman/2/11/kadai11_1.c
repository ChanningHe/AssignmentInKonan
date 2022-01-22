#include<stdio.h>
float calc(int *x, int *y);
int cals(int *x, int *y);

int main(){
    int num1,num2,sum;
    float average;
    printf("2つの整数を入力。\n");
    scanf("%d,%d",&num1,&num2);
    sum=cals(&num1,&num2);
    printf("%d + %d = %d\n",num1,num2,sum);
    average=calc(&num1,&num2);
    printf("average = %.2f\n",average);
    printf("average のアドレスは %p です\n",&average);
    return 0;
}

float calc(int *x, int *y){
    return (*x + *y)/2.0;
}

int cals(int *x, int *y){
    return (*x + *y);
}