#include<stdio.h>
void cal(int *n1,int *n2);
int main(){
    int n1,n2;
    printf("二つ整数：");
    scanf("%d\n%d",&n1,&n2);
    cal(&n1,&n2);
    return 0;
}



void cal(int *n1,int *n2){
    printf("n1-n2=%d\n",*n1-*n2);
    printf("n1+n2=%d\n",*n1+*n2);
}