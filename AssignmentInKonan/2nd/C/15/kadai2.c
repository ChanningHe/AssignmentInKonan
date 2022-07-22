#include<stdio.h>

typedef struct member
{
    char name[10];
    double ht;//m
    double wt;//kg
    double bmi;
}member;

void calc(member *m);

int main(){
    member m_list[3]={
        {"Tanaka", 1.7, 70, 0},
        {"Oka", 1.6, 60, 0},
        {"Hirao", 1.65, 65, 0},
    };

    for(int i=0; i<3; i++){
        calc(&m_list[i]);
        printf("Name:%s Tall:%.1lf Weiht:%.1lf BMI:%.2lf\n",m_list[i].name,m_list[i].ht,m_list[i].wt,m_list[i].bmi);
    }


    return 0;
}


void calc(member *m){
    m->bmi = m->wt/(m->ht*m->ht);
}