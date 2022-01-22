#include<stdio.h>
int cont_str(char *c);

int main(){
    char *week[7]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    char k[100]= "hello";
    //k = "hello";
    int day = cont_str(k);

    //printf("日を入力してください\n");    
    //scanf("%d",&day);

    printf("%d\n",day);

    return 0;
}



int cont_str(char *c){
    int len=0;
    while(c[len] != '\0'){
        len++;
    }
    return len;
}