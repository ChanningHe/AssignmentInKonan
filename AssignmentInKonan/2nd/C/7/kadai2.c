#include<stdio.h>

struct product
{
    char name[10];
    int price;
    int sum;
};

int main(){
    struct product p_pencil = {"pencil",50,0};
    struct product p_note = {"note",100,0};
    printf("Note 売上の個数を入力してください: \n");
    scanf("%d",&p_note.sum);
    printf("Pencile 売上の個数を入力してください: \n");
    scanf("%d",&p_pencil.sum);

    printf("Note 売上の金额 : %d\n",p_note.price*p_note.sum);
    printf("Pencil 売上の金额 : %d\n",p_pencil.price*p_pencil.sum);
    return 0;
}