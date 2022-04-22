#include<stdio.h>

int main(){
    int x[4];
    int sum=0;

    for(int i=0; i<4; i++){
        scanf("%d",&x[i]);
        sum+=x[i];
    }
    
    printf("%d\n",sum);
    return 0;
}