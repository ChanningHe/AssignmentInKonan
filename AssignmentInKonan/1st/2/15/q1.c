#include<stdio.h>

int power(int x,int y);

int main(){
    int x,y;
    
    printf("input x:");
    scanf("%d",&x);
    printf("input y:");
    scanf("%d",&y);

    printf("%d^%d = %d\n",x,y,power(x,y));
    return 0;
}


int power(int x,int y){
    int sum = 1;
    for(int i = 1; i <= y; i++){
        sum*=x;
    }
    return sum;
}