#include<stdio.h>
#define NUM 10
void findodd(int ary[], int odd[]);
int oddn=0;

int main(){
    int ary[NUM]={21,16,5,35,8,56,82,26,45,99};
    int oddary[NUM];
    findodd(ary,oddary);
    printf("odd numbers : %d\n",oddn);
    for(int i=0; i<oddn; i++){
        printf("No.%d : %d\n",i,oddary[i]);
    }
    return 0;
}


void findodd(int ary[], int odd[]){
    
    for(int i=0; i<NUM; i++){
        if(ary[i] % 2 == 1){
            odd[oddn]=ary[i];
            oddn++;
        }
    }

}   