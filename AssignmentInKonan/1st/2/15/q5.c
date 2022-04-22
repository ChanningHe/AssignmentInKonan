#include<stdio.h>

void delete(int *p,int n);

int main(){
    int a[]={5,2,7,9,6,-1};
    int *p = a;
    int delN;
    printf("value to delete: ");
    scanf("%d",&delN);

    printf("before:\n");
    for(int i=0; i<5; i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
    delete(p,delN);
    printf("after:\n");
    for(int i=0; *(p+i)!=-1; i++){
        printf("%d ",*(p+i));
    }
    printf("\n");

    
    return 0;
}



void delete(int *p,int n){
    int dodel=0;
    for(int i=0; *(p+i)!=-1; i++){
        if(*(p+i) == n){
            dodel=1;
        }

        if(dodel == 1){
            *(p+i)= *(p+i+1);
        }
    }

}