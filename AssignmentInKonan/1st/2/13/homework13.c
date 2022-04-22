/*
    12171029 Ka Shouen
 */
#include<stdio.h>
#include<math.h>

int CostCal(int time, int dis, int t);
int CostTotal = 0;
int CsmerCost[102];
int CsmerData[102][2];
void out(int c);

int main()
{
    int time = 1,dis = 1,CsmerS = 0;
    int *CsmerData_p;
    CsmerData_p = CsmerData_p;
    
    while(dis > 0 && time > 0){
        printf("%d番目の客：乗車時間と距離?",CsmerS+1);
        scanf("%d %d",&time,&dis);
        CsmerData[CsmerS][0]=time;
        CsmerData[CsmerS][1]=dis;
        CsmerS++;
    };

    for(int i = 0; i < CsmerS-1; i++){
        CostCal(CsmerData[i][0],CsmerData[i][1],i);
        out(i);
    }

    printf("合計売上げ：%d\n",CostTotal);
    
    return 0;
}


int CostCal(int time, int dis, int t){

    if(dis <= 1000){
        CsmerCost[t]=650;
    }else{
        CsmerCost[t]=650+ ((dis-1000-1)/250+1)*100;
    }

    if((time > 22 && time <= 24) || (time >= 0 && time < 5)){
        CsmerCost[t]*=1.2;
    }

    CostTotal+=CsmerCost[t];

    return 0;
}


void out(int c){
    printf("%d番目の客：乗車時間%d時 / 乗車距離 %dm ＝ 料金 %d円\n",
            c+1,CsmerData[c][0],CsmerData[c][1],CsmerCost[c]);
}