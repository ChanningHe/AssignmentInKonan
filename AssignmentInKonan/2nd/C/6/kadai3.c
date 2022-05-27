#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void turn2up(char *str);

void turn2low(char *str);

int main(){
    char str[1000];
    printf("文字列を入力してくだい：　");
    scanf("%s",str);
    turn2up(str);
    printf("大文字にすると%sです\n",str);
    turn2low(str);
    printf("小文字にすると%sです\n",str);
    return 0;
}


void turn2up(char *str){
    int len=0;
    while(str[len] != '\0'){
        str[len]=toupper(str[len]);
        len++;
    }
}

void turn2low(char *str){
    int len=0;
    while(str[len] != '\0'){
        str[len]=tolower(str[len]);
        len++;
    }
}

