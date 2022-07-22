#include <stdio.h>
#define NUM 6

typedef struct tagBirth{
    char name[20]; // 名前
    int year,mon,day; // 年,月,日
} Birth;

void showKisuuDay( Birth *d )
{
    for(int i=0; i<NUM; i++){
        if(d[i].day % 2 == 1){
            printf("%s\n",d[i].name);
        }
    }
}
void showUruu( Birth d[] )
{
    for(int i=0; i<NUM; i++){
        if(d[i].year % 400 == 0 || (d[i].year % 100 == 0 && d[i].year % 4 == 0)){
            printf("%s\n",d[i].name);
        }
    }

}


int main(void) {
    Birth data[NUM] = {
        {"okamura",1922,3,12}, 
        {"fujimoto",1900,6,24}, 
        {"harada",2000,11,27}, 
        {"mikami",2002,5,19}, 
        {"yokoyama",2001,2,3}, 
        {"watanabe",2008,12,8},
    };

    printf("<日が奇数の人>\n"); 
    showKisuuDay( data );
    printf("<年がうるう年の人>\n");
    showUruu( data ); 
}