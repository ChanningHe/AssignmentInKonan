#include<stdio.h>

void add(int *px,int *py, int a);

int main(){
    int x,y,a;

    printf("input x:");
    scanf("%d",&x);
    printf("input y:");
    scanf("%d",&y);
    printf("input a:");
    scanf("%d",&a);
    add(&x,&y,a);
    printf("x was changed to %d \n",x);
    printf("x was changed to %d \n",y);
    return 0;
}



void add(int *px,int *py, int a){
    *px+=a;
    *py+=a;
    //printf("%d\n",*px);
    //printf("%d\n",*py);
}