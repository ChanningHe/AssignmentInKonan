/*
 12171029 KaShouen
 */

#include<stdio.h>
#include<string.h>
float RI(int tall, int weight);
char *IsFat(float RI_t);

int main(){
    int tall,weight;

    do{
        printf("身長 [cm] ? ");
        scanf("%d",&tall);
    }while(tall <= 0);

    do{
        printf("体重 [kg] ? ");
        scanf("%d",&weight);
    }while(weight <= 0);

    printf("身長 = %d [cm]\n体重 = %d [kg]\n",tall,weight);
    float RI_out=RI(tall,weight);
    printf("RI = %.1f ",RI_out);
    /*
    if(RI_out < 115){
        printf("(やせ方)\n");
    }else if(RI_out >= 115 && RI_out <= 145){
        printf("(標準型)\n");
    }else if(RI_out > 145){
        printf("(肥満型)\n");
    }
    */

    printf("(%sです)\n", IsFat(RI_out));
    return 0;
}

float RI(int tall, int weight){
    float tall_t=tall/100.0;
    return (weight*10)/tall_t/tall_t/tall_t;
}

char *IsFat(float RI_t){
    static char Fat_str[10];
    if(RI_t < 115){
        strcpy(Fat_str,"やせ");
    }else if(RI_t >= 115 && RI_t <= 145){
        strcpy(Fat_str,"標準");
    }else if(RI_t > 145){
        strcpy(Fat_str,"肥満");
    }

    return Fat_str;
}
