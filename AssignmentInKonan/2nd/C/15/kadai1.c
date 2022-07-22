
#include<stdio.h>

int main(){
    int n=131, count=0;
    int a=n%7, b=n%11, c=n%13;

    for(int i=0; i<=20000; i++){
        if(i%7==a || i%11==b|| i%13==c){count++;}
    }
    printf("Count:%d\n",count);

    return 0;
}