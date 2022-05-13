#include<stdio.h>
#define NUM 8

void moveavg(int indate[], int outdate[], int n);

int main(){
    int in[NUM]={1,1,4,4,5,6,7,8};
    int out[NUM];
    int t=0;
    moveavg(in,out,NUM);
    while(t < NUM){
        printf("%d\n",out[t]);
        t++;
    }
    return 0;
}



void moveavg(int indate[], int outdate[], int n){
    for(int i=1; i<n-1; i++){
        outdate[i]= (indate[i-1]+indate[i]+indate[i+1])/3;
    }
    outdate[0]=indate[0];
    outdate[n-1]=indate[n-1];
}