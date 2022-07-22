#include<stdio.h>
#include<math.h>
int prime(int num);

int main(){
    
    int i,count=0;
    for(i=2;i<=100;i++){
        if(prime(i)==1){
            count++;
        }
    }
    printf("%d¥n",count);

    return 0;
}


int prime(int num){
    for(int i=2; i<sqrt(num); i++){
        if(num % i == 0){return 0;}
    }
    return 1;
}