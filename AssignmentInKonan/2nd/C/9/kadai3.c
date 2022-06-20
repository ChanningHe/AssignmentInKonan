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

void deleteData(Pref *ppr, char *pname);

int main(){
    Pref pf[10]={{"Kyoto", 4613, 16.3},
                {"Osaka", 1901, 17.3},
                {"Hyogo", 8396, 16.6},
                {"Nara" , 3691, 14.7},
    };

    for(int i=0; i<4; i++){
        printf("[%s] S:%d Temp: %f\n",pf[i].name,pf[i].area,pf[i].temp);
    }
    Pref *p = pf;
    p = (Pref*)malloc(sizeof(Pref));

    printf("delete target? -->\n");
    char pname[100];
    scanf("%s",pname);

    deleteData(pf,pname);

    for(int i=0; i<3; i++){
        printf("[%s] S:%d Temp: %f\n",pf[i].name,pf[i].area,pf[i].temp);

    }
    return 0;
}


void deleteData(Pref *ppr, char *pname){
    int flag=0;
    while(flag<4){
        if(strcmp(ppr[flag].name,pname)==0){
            break;
        }
        flag++;
    }
    //printf("%d\n",flag);
    if(flag!=3){
        for(int i=flag; i<3; i++){
            strcpy(ppr[i].name,ppr[i+1].name);
            ppr[i].area=ppr[i+1].area;
            ppr[i].temp=ppr[i+1].temp;
        }
    }
}