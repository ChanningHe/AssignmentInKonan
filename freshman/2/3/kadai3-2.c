/*
20211014
12171029 Ka Shouen
*/

#include<stdio.h>
#include<math.h>


int main(void){
    double a,b,c,d,xc,yc,disX;
    // y=ax+b y= cx+d
    printf("a: ");
    scanf("%lf",&a);
    printf("b: ");
    scanf("%lf",&b);
    printf("c: ");
    scanf("%lf",&c);
    printf("d: ");
    scanf("%lf",&d);

    if(a == c || b == d){
        printf("Error!\n");
        return 0;
    }
    //xc ycを求める
    xc=(d-b)/(a-c);
    yc=a*xc+b;

    printf("(xc, yc) = (%lf, %lf)\n",xc,yc);
    //y＝0ーー＞　disX=x1-x2
    disX=fabs((-b/a)-(-d/c));//xは負数可能性あるから、絶対値変数を使う
    printf("S = %lf\n",disX*yc/2);

    return 0;
}