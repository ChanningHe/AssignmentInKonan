#include<stdio.h>
#define NUM 10
#include"find_ans_ary.h"
void find_ans_ary(int ary[]);
int main(){
    int ary[NUM]={11,1,32,55,13,21,14,99,24,65};
    find_ans_ary(ary);
    return 0;
}

//find_ans_ary.h
void find_ans_ary(int ary[]){
    int t=0,max=0,min=1000;
    int maxt=0,mint=0;
    while(t<NUM){
        if(ary[t]>ary[maxt]){maxt=t;}
        if(ary[t]<ary[mint]){mint=t;}
        t++;
    }
    printf("result :\nMAX_NUM_IN_ARY:%d\nMIN_NUM_IN_ARY:%d\n",ary[maxt],ary[mint]);
}