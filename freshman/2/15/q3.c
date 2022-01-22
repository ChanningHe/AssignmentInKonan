#include<stdio.h>

void set_zero(int *p, int n);

int main(){
    int num[]={1,2,3,4,5};
    int n=5,tmp;
    int *p=num;

    printf("before:\n");
    for(int i=0; i<n; i++){
        printf("%d ",*(p+i));

    }
    printf("\n");
    set_zero(p,5);
    printf("after:\n");
    for(int i=0; i<n; i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
    return 0;
}



void set_zero(int *p, int n){
    int t=1;
    while(t <= n){
        *p = 0;
        p++;
        t++;
    }

}