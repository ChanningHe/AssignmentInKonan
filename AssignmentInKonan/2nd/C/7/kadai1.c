#include<stdio.h>
struct studentdata
{
    char name[10];
    float height;
    float weight;
};


int main(){
    struct studentdata stu1 = {"Taro",65.0,180.0};
    struct studentdata stu2 = {"Jiro",55.0,160.0};
    printf("%s weight:%.1fKg height:%.1fcm\n",stu1.name,stu1.weight,stu1.height);
    printf("%s weight:%.1fKg height:%.1fcm\n",stu2.name,stu2.weight,stu2.height);
    printf("Weight-average: %.1f\n",(stu1.weight+stu2.weight)/2);
    printf("Height-average: %.1f\n",(stu1.height+stu2.height)/2);
    return 0;
}