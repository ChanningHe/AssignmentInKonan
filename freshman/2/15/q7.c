#include<stdio.h>

int index_char(char *p,char c);

int main(){
    char *word;
    char check;
    printf("input a word: ");
    scanf("%s",word);
    printf("input a character: ");
    scanf("\n%c",&check);
    printf("index of \'%c\': %d\n",check,index_char(word,check));

    return 0;
}


int index_char(char *p,char c){
    int doCatch=0;
    for(int i=0; *(p+i)!=-1; i++){
        if(*(p+i) == c){
            doCatch = 1;
            return (i+1);
        }
    }
    if(doCatch == 0){
        return -1;
    }

}