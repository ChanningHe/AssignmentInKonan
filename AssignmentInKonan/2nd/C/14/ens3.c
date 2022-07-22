#include<stdio.h>
#define MAXN 10002

int main(){
    char charlist[MAXN];
    int numlist[MAXN];
    scanf("%s",charlist);
    int t=0,n=0;
    printf("文字列を入力してください\n文字列 = ");
    while(charlist[t] != '\0'){
        if(charlist[t] >= '0' && charlist[t] <= '9'){
            numlist[n] = charlist[t] - '0';
            n++;
        }
    t++;
    }

    for(int i=0; i<n; i++){
        printf("%d",numlist[i]);
    }
    printf("\n");

    return 0;
}