/*
 12171029 KaShouen
 */
#include<stdio.h>
#define PI 3.14

float cal_V(float r,float h);

int main(void)
{
    float r,h;
    printf("円錐の体積を計算します。\n");

    do{
        printf("半径?[m]\n");
        scanf("%f",&r);
    }while(r <= 0);

    do{
        printf("高さ?[m]\n");
        scanf("%f",&h);
    }while(h <= 0);

    //v=cal_V(r,h);
    printf("体積は %.1f [m^3] です。\n",cal_V(r,h));
    return 0;
}



float cal_V(float r,float h)
{
    float v;
    v=PI*r*r*h/3;
    return v;
}