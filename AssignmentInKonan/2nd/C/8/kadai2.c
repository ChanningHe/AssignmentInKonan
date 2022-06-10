#include<stdio.h>
typedef struct stel
{
    char name[10];
    char tel[20];
}stel;

int main(){
    stel tels[5];
    for(int i=0; i<5; i++){
        printf("Name(%d): ",i+1);
        scanf("%s",tels[i].name);
        printf("Tel(%d): ",i+1);
        scanf("%s",tels[i].tel);
    }
    char tmp[10];
    int flag = 0;
    printf("Search:");
    scanf("%s",tmp);
    for(int i=0; i<5; i++){
        if(tels[i].name == tmp){
            printf("Tel:%s\n",tels[i].tel);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("No data for %s.\n",tmp);
    }
    return 0;
}