#include<stdio.h>

int main(){
    int a,b;
    int *pa,*pb;
    pa = &a;
    pb = &b;
    *pa = 1;
    *pb = 2;
    //printf("%p %p\n",pa,pb);
    printf("%d\n%d\n",*pa**pb,*pa);
    return 0;
}