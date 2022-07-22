#include<stdio.h>

int main(){
    char num[100];
    int n1,n2;
    fgets(num,99,stdin);
    sscanf(num,"%d%d",&n1,&n2);
    printf("%d + %d = %d\n",n1,n2,n1+n2);

    return 0;
}