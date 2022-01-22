#include<stdio.h>

int nunS(char *p, char n，int *pi);

int main(){
    char dic[5][10]={"mikage","kobe","okamoto","rokko","ojikoen"};
    char ch;
    int pi[5]={0};
    printf("input a character: ");
    scanf("%c",&ch);

    for(int i = 0; i < 5; i++){
        printf("%s : %d\n",dic[i],nunS(dic[i],ch));
    }
    return 0;
}



int nunS(char *p, char n){
    int s=0;
    for(int i=0; *(p+i)!= '\0'; i++){
        if(*(p+i) == n){
            s++;
        }
    }
    return s;
}