#include<stdio.h>

int main(){
    int num[3];

    for(int i=0; i<3; i++){
        scanf("%d",&num[i]);
        num[i]=num[i]*10;
    }

    for(int j=0; j<3; j++){
        printf("%d\n",num[j]);
    }

    return 0;
}