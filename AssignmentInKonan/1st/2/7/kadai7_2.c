/*
12171029 KaShouen
 */
#include<stdio.h>
#define arrayN 7 //Line && List
int in2tmp(int line,int list);
int median();
int array_median[arrayN][arrayN]={{1,2,3,4,5,6,7},
                                {1,10,2,3,4,5,7},
                                {1,4,5,3,10,2,3},
                                {1,2,3,4,1,2,3},
                                {1,3,10,2,2,3,1},
                                {1,4,1,1,3,4,2},
                                {1,5,2,3,2,5,1}
                                };
int array_median_anw[arrayN][arrayN];
int array_tmp[9]={0};


int main(){
    printf("input image\n");
    for(int p=0;p<arrayN;p++){
        for(int d=0;d<arrayN;d++){
            array_median_anw[p][d]=array_median[p][d];
            printf("%d ",array_median[p][d]);
        }
        printf("\n");
    }

    for(int i=1;i<arrayN-1;i++){
        for(int j=1;j<arrayN-1;j++){
            in2tmp(i,j);//1次元配列に入れて
            array_median_anw[i][j]=median();//ソートし、中央値を求める
        }
    }

    printf("output image\n");
    for(int p=0;p<arrayN;p++){
        for(int d=0;d<arrayN;d++){
            printf("%d ",array_median_anw[p][d]);
        }
        printf("\n");
    }
    return 0;
}


int in2tmp(int line,int list){
    int n=0;
    for(int u=line-1;u<=line+1;u++){
        for(int v=list-1;v<=list+1;v++){
            array_tmp[n]=array_median[u][v];
            n++;
        }
    }
    return 0;
}


int median(){
    for(int c=0;c<8;c++){
        for(int z=c+1;z<9;z++){
            if(array_tmp[c] < array_tmp[z]){
                array_tmp[z]=array_tmp[c]*array_tmp[z];
                array_tmp[c]=array_tmp[z]/array_tmp[c];
                array_tmp[z]=array_tmp[z]/array_tmp[c];//exchange z && c
            }
        }
    }//sort

    return array_tmp[4];
}