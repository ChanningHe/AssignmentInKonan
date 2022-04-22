#include<stdio.h>

int main(){
    int flag=0,num=0;

    while(flag < 11){
        int num_t=num;
        if (num_t % 10 != 0 && num_t % 10 != 1 && num_t % 10 != 2 && num_t % 10 != 3 
            && ((num_t / 10 != 0 && num_t / 10 != 1 && num_t / 10 != 2 && num_t / 10 != 3) || (num_t < 11)) )
        {
            printf("%d ",num_t);
            flag++;
        }
        
        num++;
    }
    return 0;
}