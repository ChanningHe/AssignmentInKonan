/*
 12171029 KaShouen
 */


#include<stdio.h>
#include<math.h>

float cal_num(float n,int mode,int de_p);

int main(void)
{
    float num,r;
    int cal_mode,de_places;
    printf("数値? ");
    scanf("%f",&num);
    printf("種類（切り捨て -1, 四捨五入 0, 切り上げ 1）? ");
    scanf("%d",&cal_mode);
    printf("小数第何位まで? ");
    scanf("%d",&de_places);
    r=cal_num(num,cal_mode,de_places);//cal_num(数値,種類，何位);
    printf("%.*f\n",de_places,r);
    return 0;
}


float cal_num(float n,int mode,int de_p){
    float result;
    if(mode == -1){
        result=((int)(n*pow(10,de_p)))/pow(10,de_p);
    }

    if(mode == 0){
        result=((int)(n*pow(10,de_p)+0.5))/pow(10,de_p);
    }

    if(mode == 1){
        result=( ( (int)(n*pow(10,de_p)) ) +1)/pow(10,de_p);
    }

    return result;
}
