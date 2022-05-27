#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct size
{
    float tops;
    float bottoms;
    float h;
};


void trapezoid_v(struct size s1, struct size s2);

int main(){
    struct size s1;
    struct size s2;
    printf("No.1の上底、下底、高さを入力してください：\n");
    scanf("%f%f%f",&s1.tops,&s1.bottoms,&s1.h);
    printf("No.2の上底、下底、高さを入力してください：\n");
    scanf("%f%f%f",&s2.tops,&s2.bottoms,&s2.h);

    trapezoid_v(s1,s2);
    return 0;
}


void trapezoid_v(struct size s1, struct size s2){
    float v=abs((s1.tops+s1.bottoms)*s1.h/2-(s2.tops+s2.bottoms)*s2.h/2);
    printf("面積の差：%.1f\n",v);
}