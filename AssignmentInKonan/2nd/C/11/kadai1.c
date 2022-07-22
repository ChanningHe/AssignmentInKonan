/*
12171029 KaShouen
*/

#include<stdio.h>
#include<string.h>
int main(){
    char num[100];
    char mark;
    int n1,n2;
    printf("＞計算式を入力-->");
    fgets(num,99,stdin);
    sscanf(num,"%d%c%d",&n1,&mark,&n2);
    //printf("%d %d",n1,n2);
    if(mark == '+'){
        printf("%d + %d = %d\n",n1,n2,n1+n2);
    }else if(mark == '-'){
        printf("%d - %d = %d\n",n1,n2,n1-n2);
    }else if(mark == '/'){
        printf("%d / %d = %d\n",n1,n2,n1/n2);
    }else if(mark == '*'){
        printf("%d * %d = %d\n",n1,n2,n1*n2);
    }

    return 0;
}