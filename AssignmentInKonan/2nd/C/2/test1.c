#include<stdio.h>
#include<string.h>
int main(){
    char str1[999];
    printf("文字列を入力してください:");

    scanf("%s",str1);

    int sum_a = 0,t=0;

    while(str1[t] != '\0'){
        if(str1[t] == 'a'){ str1[t] = 'b';}
        t++;
    }
    printf("%sの中にaは%d個あります。\n",str1,sum_a);


    return 0;
}