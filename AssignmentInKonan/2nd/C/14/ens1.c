#include <stdio.h>
#define NNUM 3 
typedef struct Grade{
    char name[100]; // 名前
    int eigo, sugaku, rika; // 英、数、理 
    double heikin; // 平均点
}Grade;


int main(void)
{

    Grade gradelist[NNUM] = {
                        {"Tanaka", 85, 92, 73, 0}, 
                        {"Suzuki", 78, 81, 100, 0},
                        {"Nakamura", 71, 82, 93, 0},
    };
    Grade bestone;
    // 平均点の計算
    bestone = gradelist[0];
    for(int i=0; i<3; i++){
        gradelist[i].heikin = (gradelist[i].eigo + gradelist[i].sugaku + gradelist[i].rika)/3.0;
        if(gradelist[i].heikin > bestone.heikin){bestone = gradelist[i];}
    }
    /*
    gradelist[0].heikin = (st1.eigo + st1.sugaku + st1.rika)/3.0; 
    st2.heikin = (st2.eigo + st2.sugaku + st2.rika)/3.0; 
    st3.heikin = (st3.eigo + st3.sugaku + st3.rika)/3.0;
    */
    // 平均点の最も高い人を探す 
    
    //if( st2.heikin>top.heikin ) top = st2;
    //if( st3.heikin>top.heikin ) top = st3;

    printf("最も高い人 = %s, 平均点 = %5.2lf\n", bestone.name, bestone.heikin); 
    return 0;
}