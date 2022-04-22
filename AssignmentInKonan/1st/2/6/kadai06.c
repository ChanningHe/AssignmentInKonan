/*
 12171029 KaShouen
 */


#include<stdio.h>

int main(){
    int score[5];
    int s_max=0,s_min=100,sum=0;
    int cal=0;
    
    printf("5人の点数を入力してください。\n");
    for(int i = 0; i < 5; i++){
        printf("%d番: ",i+1);
        scanf("%d",&score[i]);
        sum+=score[i];
        if(score[i] > s_max){s_max = score[i];}
        if(score[i] < s_min){s_min = score[i];}

    }

    printf("合計点：%d\n",sum);
    printf("平均点：%.5f\n",sum/5.0);
    printf("最高点：%d\n",s_max);
    printf("最低点：%d\n",s_min);

    for(int j = 0; j < 5; j++){
        printf("%d番：%d ",j+1,score[j]);
        cal++;
        if(cal == 2){
            printf("\n");
            cal = 0;
        }
    }

    printf("\n");
    return 0;
}