/*
    12171029 KaShouen https://github.com/ChanningHe/AssignmentInKonan
*/
#include <stdio.h>
#include <math.h>

int prime(int in);

int main(){
    //int flag=0,tmpn[2],t=0;
    for(int i=20; i<40; i++){
        int k;
        for(int j=2; j<sqrt(i)+1; j++){
            if(i % j == 0){
                k=i/j;
                if((prime(k) == 1) && (prime(j) == 1) && (k != j)){
                    printf("%d=%dx%d\n",i,j,k);
                }
            }
        }
    }
    return 0;
}


int prime(int in){
    //int flag = 0;
    if(in == 2){return 1;}
    for(int i=2; i<=sqrt(in)+1; ++i){
        if(in%i==0)
        {
            return 0;
        }        
    }
    return 1;
}

