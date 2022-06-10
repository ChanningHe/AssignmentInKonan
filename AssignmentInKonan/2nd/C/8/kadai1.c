#include<stdio.h>

float codispersion(int *x, int *y);
float adv(int *ary);
float dispersion(int *ary, int n);
void outa(float n1, float n2);

int main(){
    int arrary_x[] = {50, 60, 70, 80, 90};
    int arrary_y[] = {40, 70, 80, 60, 100};
    int arrary_xy[5];
    int adv_x=adv(arrary_x); //x平均値
    int adv_y=adv(arrary_y);       //y平均値



    int dix = dispersion(arrary_x,adv_x); //xの分散
    int diy = dispersion(arrary_y,adv_y); //yの分散

    outa(codispersion(arrary_x,arrary_y),dix);

    return 0;
}

float adv(int *ary){
    int sum=0;
    for(int i=0; i<5; i++){
        sum+=ary[i];
    }
    return sum/5;
}


float dispersion(int *ary, int n){
    int sum=0;
    for(int i=0; i<5; i++){
        ary[i]=ary[i]*ary[i];
        sum+=ary[i];
    }
    return ((sum/5)-n*n);

}

float codispersion(int *x, int *y){
    int xy[5];
    int sum=0;
    for(int i=0; i<5; i++){
        xy[i]=x[i]*y[i];
        sum+=xy[i];
    }
    int aws = (sum/5) - (adv(x)*adv(y));
    return aws;
}

void outa(float n1, float n2){
    printf("a is %.1f\n",n1/n2);
}
//a is 21890.0