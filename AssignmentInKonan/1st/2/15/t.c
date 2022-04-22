#include<stdio.h>

int main(){
    char t[]="ab";
    int a = 2;
    t[1] = a + '0';
    printf("%s\n",t);

    return 0;
}