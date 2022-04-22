#include<stdio.h>

int main(){
    FILE *Pyramid;
    Pyramid = fopen("./stage.txt","r");
    int n;
    fscanf(Pyramid,"%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=0; j<n-i; j++){
            printf(" ");
        }
        for(int v=0; v<(i*2-1); v++){
            printf("%d",i);
        }
        printf("\n");
    }
    fclose(Pyramid);

    return 0;
}