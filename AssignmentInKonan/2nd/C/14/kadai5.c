#include<stdio.h>
#include<string.h>

void strswap(char **s1, char **s2)
{
    char *tmpc = NULL;
    tmpc = *s1;
    *s1 = *s2;
    *s2 = tmpc;
}

int main(){
    printf("5個の文字列入力してください\n");
    char clist[5][1002];
    for(int i=0; i<5; i++){
        printf("入力された文字列：");
        scanf("%s",clist[i]);
    }
    int isSorted;
    for(int i=0; i<4; i++){
        for(int j=0; j<4-i; j++){
            if( strlen(clist[j]) < strlen(clist[j+1]) ){
                strswap(clist[j], clist[j+1]);
            }
        }
    }

    for(int i=0; i<5; i++){
        printf("文字列：");
        printf("%s\n",clist[i]);
    }

    return 0;
}