#include<stdio.h>
#include<math.h>

int main(){
    int num;
    int Fx=1,Fy=0,sum;
    double G_Ratio;
    double Ratio=0;

    G_Ratio=(1+sqrt(5))/2;

    do{
        printf("\n");
        printf("Input num(2<=num<=40)?: ");
        scanf("%d",&num);
        printf("Your input number --> %d\n",num);
    }while(num < 2 || num > 40);

    printf("\n\nGolden Ratio = %.10lf\n\n",G_Ratio);
    printf("start\n\n");
    printf("F(0) = 0\n");
    printf("F(1) = 1\n");

    for(int i=2;i<=num;i++){
        sum=Fx+Fy;
        
        printf("F(%d) : F(%d) + F(%d) -->  %d + %d = %d",i,i-1,i-2,Fx,Fy,sum);

        if(i>2){
            Ratio=(double)Fx/Fy;
            printf("   Ratio: (%d/%d) = %.10lf",Fx,Fy,Ratio);
        }
        printf("\n");
        if(fabs((Ratio-G_Ratio)/G_Ratio) < (1e-10)){break;}

        Fy=Fy+Fx;Fx=Fy-Fx;Fy=Fy-Fx;
        Fx=sum;
    }

    printf("\nend\n\n");
    printf("************ Result ************\n");
    printf("       Ratio --> %.10lf\n",Ratio);
    printf("Golden_Ratio --> %.10lf\n",G_Ratio);
    return 0;
}