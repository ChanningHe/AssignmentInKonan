#include<stdio.h>
#include<stdlib.h>
typedef struct Pref
{
    char name[100];
    int area;
    double temp;
    struct Pref *next;
}Pref;

void printPref(Pref pf[]);
void printPref2(Pref *ppf);
int main(){
    Pref pf[5]={{"Kyoto", 4613, 16.3},
                {"Osaka", 1901, 17.3},
                {"Hyogo", 8396, 16.6},
                {"Nara" , 3691, 14.7},
    };
    //Pref *p = pf;
    pf[0].next = &(pf[1]);
    pf[1].next = &(pf[2]);
    pf[2].next = &(pf[3]);
    pf[3].next=NULL;
    //p = (Pref*)malloc(sizeof(Pref));
    printPref2(pf);
    //free();
    return 0;
}

void printPref(Pref pf[]){
    for(int i=0; i<4; i++){
        printf("[%s] S:%d Temp: %f\n",pf[i].name,pf[i].area,pf[i].temp);
    }    
}

void printPref2(Pref *ppf){
    int t =4;
    while(1){
        //t++;
        if( !ppf ){break;}
        printf("[%s] S:%d Temp: %f\n",ppf->name,ppf->area,ppf->temp);
        ppf = ppf->next;
    }
}




    /*
    for(int i=0; i<4; i++){
        printf("[%s] S:%d Temp: %f\n",pf[i].name,pf[i].area,pf[i].temp);

    }*/