#include<stdio.h>
#include<string.h>
int main(){
    char str1[999];
    printf("文字列を入力してください:");

    scanf("%s",str1);

    int slen = strlen(str1);

    printf("%sの文字列の長さは%dです。\n",str1,slen);


    return 0;
}