#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search(char *str);
int main(){
    char str[1000];
    printf("文字列を入力してくだい：　");
    scanf("%s",str);
    printf("%sの中にはaが%d個あります。\n",str,search(str));
    return 0;
}


int search(char *str){
    int len=0,counta=0;
    while(str[len] != '\0'){
        if(str[len] == 'a'){counta++;}
        len++;
    }
    return counta;
}


