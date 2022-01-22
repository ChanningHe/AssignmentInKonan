#include<stdio.h>

void reverse(int *p, int n);

int main(){
    int num[]={1,2,3,4,5};
    int n=5,tmp;
    int *p=num;

    printf("before:\n");
    for(int i=0; i<5; i++){
        printf("%d ",*(p+i));

    }
    printf("\n");
    
    reverse(p,5);
    
    printf("after:\n");
    for(int i=0; i<5; i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
    return 0;
}



void reverse(int *p, int n){
    int tmp[101];
    int *q=tmp;
    for(int j=n-1; j >= 0; j--){
        tmp[n-1-j]=*(p+j);
    }
    for(int v = 0; v < n; v++){
        *(p+v)=tmp[v];
    }
}