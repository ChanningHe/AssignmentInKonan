#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
    int r;

    srand((unsigned)time(NULL));
    r = rand() % 41 +10;
    while(r/10 == r%10){
        r = rand() % 41 +10;
    }

    int input_n,flag=0,hit,blow;
    //printf("入力:");
    //scanf("%d",x);

    while(1){
        hit=0,blow=0;
        printf("入力:");
        scanf("%d",&input_n);
        //n1=input_n/10;
        //n2=input_n%10;

        if(input_n/10 == r/10){
            hit++;
        }else if(input_n/10 == r%10){
            blow++;
        }

        if(input_n%10 == r%10){
            hit++;
        }else if(input_n%10== r/10){
            blow++;
        }

        printf("ヒット：%d，ブロー：%d\n",hit,blow);
        if(hit >= 2){
            break;
        }

    }



    return 0;
}