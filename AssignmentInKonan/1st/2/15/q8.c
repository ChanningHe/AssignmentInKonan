#include<stdio.h>

int are_indentical(char *str1, char *str2);

int main(){
    char str1[1001],str2[1001];
    printf("input a word: ");
    scanf("%s",str1);

    printf("input another word: ");
    scanf(" %s",str2);

    
    if(are_indentical(str1,str2) == 1){
        printf("identical\n");
    }else{
        printf("different\n");
    }

    return 0;
}


int are_indentical(char *str1, char *str2){
    int check1=1,check2=1;
    for(int i = 0; *(str1+i) != '\0'; i++){
        if(*(str1+i) != *(str2+i)){
            check1 = 0;
        }
    }

    for(int j = 0; *(str2+j) != '\0'; j++){
        if(*(str1+j) != *(str2+j)){
            check2 = 0;
        }
    }

    if(check1 == 1 && check2 == 1){
        return 1;
    }else{
        return 0;
    }
}