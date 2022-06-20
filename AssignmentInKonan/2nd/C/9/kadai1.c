/*
12171029 KaShouen
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Pref
{
    char name[100];
    int area;
    double temp;
    struct Pref *next;
}Pref;

double getTempAverage(Pref *ppr);

int main(){
    Pref pf[4]={{"Kyoto", 4613, 16.3, NULL},
                {"Osaka", 1901, 17.3, NULL},
                {"Hyogo", 8396, 16.6, NULL},
                {"Nara" , 3691, 14.7, NULL},
    };
    double advTemp = getTempAverage(pf);
    printf("平均値　= %f\n",advTemp);
    return 0;
}


double getTempAverage(Pref *ppr){
    double sum = 0;
    for(int i=0; i<4; i++){
        sum+=ppr[i].temp;
        //printf("%d\n",sum);
    }
    return sum/4;
}