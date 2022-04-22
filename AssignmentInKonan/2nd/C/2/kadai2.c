#include<stdio.h>

int main(){
    FILE *list;

    list = fopen("list.txt","w");

    printf("処理する人数を入力してください：\n");
    int people_n;//the number of people
    scanf("%d",&people_n);
    printf("各人の点数を入力してください：\n");
    int ans_arrary[11]={0}; // the answer arrary
    int tmp_n;
    for(int i=1; i<=people_n; i++){
        printf("%4d番：",i);
        scanf("%d",&tmp_n);
        ans_arrary[tmp_n/10]++;
    }

    fprintf(list,"分布\n");
    for(int j=10; j>=0; j--){
        if(j == 10 ){
            fprintf(list,"     %2d:",j*10);
        }else{
            fprintf(list,"%2d -  %2d:",j*10,j*10+9);
        }
        for(int v= 0; v<ans_arrary[j]; v++){
            fprintf(list,"*");
        }
        fprintf(list,"\n");
    }
    fclose(list);
    return 0;
}