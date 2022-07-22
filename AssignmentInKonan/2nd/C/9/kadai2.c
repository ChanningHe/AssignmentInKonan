#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Pref
{
    char name[100];
    int area;
    double temp;
    struct Pref *next;
}Pref;

void addData(Pref *ppr, Pref *n_data);

int main(){
    Pref pf[10]={{"Kyoto", 4613, 16.3},
                {"Osaka", 1901, 17.3},
                {"Hyogo", 8396, 16.6},
                {"Nara" , 3691, 14.7},
    };
    Pref np1 = {"Wakayama", 4726, 16.4, NULL};
    Pref np2 = {"Shiga", 3767, 14.8, NULL};

    for(int i=0; i<4; i++){
        printf("[%s] S:%d Temp: %f\n",pf[i].name,pf[i].area,pf[i].temp);
    }
    Pref *p = pf;
    p = (Pref*)malloc(sizeof(Pref));

    addData(pf,&np1);
    addData(pf,&np2);
    printf("-- 追加後\n");
    for(int i=0; i<6; i++){
        printf("[%s] S:%d Temp: %f\n",pf[i].name,pf[i].area,pf[i].temp);
    }
    return 0;
}

void addData(Pref *ppr, Pref *n_data){
    //printf("\n%ld\n",sizeof(ppr));
    int n=0;
    while(ppr[n].area){n++;}
    strcpy(ppr[n].name,n_data->name);
    ppr[n].area=n_data->area;
    ppr[n].temp=n_data->temp;

}