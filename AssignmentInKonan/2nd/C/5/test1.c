#include<stdio.h>
void calarrary(int ary[]);
int main(){
    int ary[5];
    calarrary(ary);

    for(int i=0; i<5; i++){
        printf("No.%d : %d\n",i,ary[i]);
    }
    return 0;
}


void calarrary(int ary[]){
    for(int i=0; i<5; i++){
        ary[i]= 3*i*i-2*i-1;
    }

}

