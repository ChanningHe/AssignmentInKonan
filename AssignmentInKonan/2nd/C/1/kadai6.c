#include<stdio.h>

int main(){
    int x[4];
    int min=999,mini=0;

    for(int i=0; i<4; i++){
        scanf("%d",&x[i]);
        if( x[i] < min ){
            min = x[i];
            mini = i;
        }
    }
    
    printf("mmin=%d,i=%d\n",min,mini);
    return 0;
}