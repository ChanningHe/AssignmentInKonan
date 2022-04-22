#include<stdio.h>
//#include<bits/stdc++.h>

int main(){

    FILE *cal99;
    cal99 = fopen("cal99.txt","w");

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            fprintf(cal99,"%2d ",i*j);

            if(j == 9){fprintf(cal99,"\n");}
        }
    }

    fclose(cal99);
    return 0;
}