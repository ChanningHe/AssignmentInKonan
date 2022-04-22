/*
    12171029 何 承遠
 */

#include<stdio.h>

void reduction(int *n, int *d);

int main(){
    int num,deno;

    printf("約分する分数を入力。\n分子？ ");
    scanf("%d",&num);
    printf("%p へ置かれました。\n",&num);

    printf("約分する分数を入力。\n分母？ ");
    scanf("%d",&deno);
    printf("%p へ置かれました。\n",&deno);

    printf("%d/%d\n== 約分すると ==\n",num,deno);

    reduction(&num, &deno);
    printf("%d/%d\n",num,deno);

    return 0;
}


void reduction(int *n, int *d){
    int n_t = *n;
    int d_t = *d;
    int t = 0;
    while(1){
        t = d_t % n_t;
        if(t == 0){break;}
        d_t = n_t;
        n_t = t;
    }

    *n/=n_t;
    *d/=n_t;
}