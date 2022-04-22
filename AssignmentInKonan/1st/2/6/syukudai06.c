/*
 12171029   KaShouen
 */
#include<stdio.h>

//int IsBlue(int a_line,int a_list)；

int main(void){

    int pass_NUM[4][3]={{1,1,1},{1,0,1},{1,0,0},{0,1,1}};
    int array_NUM[9][21]={0};
    int line=0;    

    for(int i=0;i<20;i++){
        scanf("%1d",&array_NUM[0][i]);
        //array_NUM[0][i] = getchar();
    }
    printf("\n");

    while(line<9){
        for(int j=1;j<19;j++){
            for(int u=0;u<4;u++){
                if(pass_NUM[u][0]==array_NUM[line][j-1] 
                    && pass_NUM[u][1]==array_NUM[line][j]
                    && pass_NUM[u][2]==array_NUM[line][j+1])
                    {            
                    array_NUM[line+1][j]=1;
                    break;
                }
            }
        }
        
        for(int v=0;v<20;v++){
            printf("%d",array_NUM[line][v]);
        }
        printf("\n");

        line++;     
    }
    return 0;
}

/*
int IsBlue(int a_line,int a_list){

    for(int u=0;u<4;u++){
        if(pass_NUM[u][0]==array_NUM[a_line][a_list-1] 
            && pass_NUM[u][1]==array_NUM[a_line][a_list]
            && pass_NUM[u][2]==array_NUM[a_line][a_list+1]){
                return 1;
            }
    }

    return 0;
}
*/