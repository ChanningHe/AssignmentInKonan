#include<stdio.h>

int main(){
    int x[4];
    int max=0,maxi=0;

    for(int i=0; i<4; i++){
        scanf("%d",&x[i]);
        if( x[i] > max ){
            max = x[i];
            maxi = i;
        }
    }
    
    printf("max=%d,i=%d\n",max,maxi);
    return 0;
}