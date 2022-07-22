#include <stdio.h>
typedef struct CAR{
    int year;
    double gas;
}CAR;

void p0(CAR *p){
    printf("year:%d\ngas:%.1f\n",p->year,p->gas);
}

void p1(CAR cc){
    printf("year:%d\ngas:%.1f\n",cc.year,cc.gas);
}
void p2(CAR *p){
    printf("year:%d\ngas:%.1f\n",p[0].year,p[0].gas);
    printf("year:%d\ngas:%.1f\n",p[1].year,p[1].gas);
}

int main(void){
    CAR c1[2]={{2021,25.0},{2020,35.0}};
    p0(&c1[0]);
    p1(c1[1]);
    p2(c1);
    return 0;
}