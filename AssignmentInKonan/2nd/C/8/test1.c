#include<stdio.h>

int main(){

    int i, x;
    double ave = 0;
    for (i = 0; i < N; i++) {
        printf("入力%d: ", i+1);
        scanf("%d", &x);
        if (x < 0) {
            break;
        }
        ave += (double)x;
    }
    printf("平均: %f¥n", ave / i);
    return 0;
}