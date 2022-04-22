#include<stdio.h>

int main(){
    int n=1;
    int num[101];
    int *nump,*i;
    nump = num;
    i = num;
    while(n<=100){
        printf("%d番目の数字? ",n);
        scanf("%d",nump);
        if(*nump < 0){break;}
        nump++;
        n++;
    }

    printf("\n単語帳\n");
    for(i ; i<nump; i++){
        static int tmp=1;
        printf("%d番目の数字? %d\n",tmp,*i);
        tmp++;
    }

    int numt,x,flag=1;
    while(flag == 1){
        printf("数値?  ");
        scanf("%d",&numt);
        i = num;
        for(i ; i<nump; i++){
            x=*i;
            while(x>10){x/=10;}
            if(x == (numt%10)){
                printf("%d -> %d\n",numt,*i);
                break;
                }
        }

        if(i == nump-1){
            printf("%d -> なし\nYou Win!\n",numt);
            flag == 0;
            break;
        }
    }
    return 0;

}