#include<stdio.h>
#include<math.h>

struct coordinate
{
    float x;
    float y;
};

int main(){
    struct coordinate cdt1 = {10,20};
    struct coordinate cdt2 = {15,35};
    float dis=sqrt((pow(cdt1.x-cdt2.x,2)+pow(cdt1.y-cdt2.y,2)));
    printf("%.2f\n",dis);
    return 0;
}