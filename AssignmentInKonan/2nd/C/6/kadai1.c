#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int length(char *c);

int main(){
    char str[1000];
    printf("文字列を入力してくだい：　");
    scanf("%s",str);
    //gets(str);
    printf("文字列の長さは%dです。\n",length(str));
    return 0;
}


int length(char *c){
    int len=0;
    while(c[len] != '\0'){
        len++;
    }
    return len;
}
