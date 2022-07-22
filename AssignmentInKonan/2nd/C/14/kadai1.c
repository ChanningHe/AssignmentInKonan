#include<stdio.h>

struct Zikan{
    int h; //hours
    int m; //mins
    int s; //sces;
}Zikan;

int main(){

    struct Zikan t1 = {1, 30, 15};
    struct Zikan t2 = {3, 51, 47};
    struct Zikan t3 = {2, 18, 21};
    struct Zikan t4 = {1, 47, 58};

    struct Zikan sum;
    int s_up = (t1.s + t2.s + t3.s + t4.s) / 60; 
    sum.s = (t1.s + t2.s + t3.s + t4.s) % 60; // number s advance to m
    int m_up = (t1.m + t2.m + t3.m + t4.m + s_up) / 60;
    sum.m = (t1.m + t2.m + t3.m + t4.m + s_up) % 60;// number m advance to h
    sum.h = t1.h + t2.h + t3.h + t4.h + m_up;

    printf("  %2d時 %2d分 %2d秒\n", t1.h, t1.m, t1.s); 
    printf("  %2d時 %2d分 %2d秒\n", t2.h, t2.m, t2.s); 
    printf("  %2d時 %2d分 %2d秒\n", t3.h, t3.m, t3.s); 
    printf("+)%2d時 %2d分 %2d秒\n", t4.h, t4.m, t4.s); 
    printf("-------------------\n");
    printf("  %2d時 %2d分 %2d秒\n", sum.h, sum.m, sum.s); 

    return 0;
}