/*
    12171029 KaShouen https://github.com/ChanningHe/AssignmentInKonan
*/
#include <stdio.h>
#include <math.h>

int prime(int in);


int main(void){
    int i;
    for(i=20;i<30;i++){
        printf("%d %d\n",i,prime(i));
    }
    return 0;
}


int prime(int in){
    //int flag = 0;
    for(int i=2; i<=sqrt(in)+1; ++i){
        if(in%i==0)
        {
            return 0;
        }        
    }
    return 1;
}