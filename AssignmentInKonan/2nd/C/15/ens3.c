#include<stdio.h>

typedef struct number{
    int n;
    struct number *next;
}number;

int main(){
    int n;
    number *num;
    printf("Input Number:");
    scanf("%d",&n);
    for(int i=1; i<n; i++){
        //num=(number)malloc(sizeof(number));
        num->n=i;
        //p->next =
        num=num->next;
    }
    num->next = NULL;
    for(int i=0; i<n; i++){
        printf("%d \n",num[i].n);
        //num=num->next;
    }

}