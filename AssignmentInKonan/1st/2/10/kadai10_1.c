/*
12171029 KaShouen
 */


#include<stdio.h>
#define maxT 5
float drop_dis(float gra,int t);


int main(){
    float gravity = 1.62;
    float velocity[maxT];
    printf("%f m/s^2 で自由落下の落下速度を計算\n", gravity);
    for(int i = 0; i < maxT; i++){
        velocity[i]=drop_dis(gravity,i);
        printf("%d秒後 %.2f m\n", i, velocity[i]);
    }

    return 0;
}

float drop_dis(float gra,int t){
    return gra*t;
}