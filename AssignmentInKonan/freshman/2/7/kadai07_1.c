/*
 12171029 KaShouen
 */

#include<stdio.h>
#define NUM 10

int main(){
    int EngSoc[NUM]={89,90,50,49,100,9,70,69,79,80};
    int cal[11]={0};
    
    for(int i=0;i<NUM;i++){
        printf("%d: %d\n",i,EngSoc[i]);
        cal[EngSoc[i]/10]++;
    }
    printf("分布\n");
    for(int j=0;j<10;j++){
        printf("%d-%d: %d\n",j*10,(j+1)*10-1,cal[j]);
    }

    printf("%d: %d\n",100,cal[10]);
    return 0;
}