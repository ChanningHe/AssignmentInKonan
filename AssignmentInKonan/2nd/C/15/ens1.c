#include<stdio.h>

int main(){
    int stuNum, count=0;
    printf("ָ学籍番号を入力してください：");
    scanf("%d",&stuNum);
    stuNum%=100;
    for(int i=0; i<=100000; i++){
        if(i%113 == stuNum){count++;}
    }
    printf("Count:%d\n",count);

    return 0;
}