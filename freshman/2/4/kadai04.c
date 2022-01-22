#include<stdio.h>

int main(void){
    double score=-1;
    
    do{
        printf("input score ( 0 <= score <=100 ): ");
        scanf("%lf",&score);
        printf("your input number ==> %.0f\n",score);
    }while(score < 0 || score > 100);

    //printf("your input number ==> %.0f\n",score);
    if(score >=60){
            
            printf("goukaku\n");
        }else if(score<60){
            printf("fugoukaku\n");
    }
}