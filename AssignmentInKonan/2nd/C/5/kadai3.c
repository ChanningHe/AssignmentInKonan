#include<stdio.h>
#define NUM 10
void find_ans_ary(int ary[]);
int main(){
    int ary[NUM]={11,1,32,55,13,21,14,99,24,65};
    find_ans_ary(ary);
    return 0;
}


void find_ans_ary(int ary[]){
    int t=0,max=0,min=1000;
    while(t<NUM){
        if(ary[t]>max){max=ary[t];}
        if(ary[t]<min){min=ary[t];}
        t++;
    }
    printf("MAX_NUM_IN_ARY:%d\nMIN_NUM_IN_ARY:%d\n",max,min);
}