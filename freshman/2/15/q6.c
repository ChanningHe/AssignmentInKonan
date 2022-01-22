#include<stdio.h>

void nullify(char *p);

int main(){
    char str[]= "test";
    printf("before: \n str = \"%s\"\n",str);
    nullify(str);
    printf("after: \n str = \"%s\"\n",str);
    return 0;
}



void nullify(char *p){
    *p = '\0';
}