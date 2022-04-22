#include<stdio.h>

int cake_s;
void cake_out(int*p,int ps);
int cake_buy(int buy);

int main()
{
    int pp_s=0;
    int cake[101];
    int *cake_p;

    cake_p=cake;

    printf("ケーキの在庫? ");
    scanf("%d",&cake_s);

    int tmp;
    do{

        pp_s++; 
        printf("%d 番目のお客さんの希望購入数? ",pp_s);
        scanf("%d",&tmp);
        *cake_p = tmp;
        cake_p++;
    }while(tmp > 0);

    cake_out(cake,pp_s);

    return 0;
}    


void cake_out(int*p,int ps){
    for(int i=0; i < ps-1; i++){
        printf("%d番目のお客さん: 希望%d - 購入%d\n",i+1,p[i],cake_buy(p[i]));
    }
}

int cake_buy(int buy){
    cake_s-=buy;
    if(cake_s > 0 ){
        return buy;
    }else{
        cake_s+=buy;
        return cake_s;
    }

}