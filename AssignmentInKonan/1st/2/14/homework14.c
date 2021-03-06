/*
 12171029 KaShouen
 */
#include<stdio.h>
#include <assert.h>

//void ReChar(char *dic, char *wd_f, char *wd_r);
//char dic_final[102];

void FindFlag(char *dic_1, char *wd_f_1);//書き換えのところを見つかる
int cont_str(char *c);//文字列の長さを計算する
char *cat_str(char *dest,const char *src);//src をdestの後ろに連結する
int flagL,flagR,IsFind = 0;

int main(void){
    char dictionary[102];
    char word_f[102],word_r[102];//find & replace
    
    printf("長い文字列(空白を含まない)を入力してください: ");
    scanf("%101s",dictionary);
    printf("置換元の単語を入力してください: ");
    scanf("%101s",word_f);
    printf("置換先の単語を入力してください: ");
    scanf("%101s",word_r);

    printf("元の文字列：%s\n",dictionary);
    printf("%s を %s に置換\n",word_f,word_r);

    FindFlag(dictionary,word_f);
    //ReChar(dictionary,word_f,word_r);

    if (IsFind == 0){
        printf("置換後の文字列:%s\n",dictionary);
        return 0;
    }

    printf("置換後の文字列:");
    for(int i = 0; i < flagL; i++){
        printf("%c",dictionary[i]);
    } 
    
    printf("%s",word_r);

    for(int j = flagR; j < cont_str(dictionary); j++){
        printf("%c",dictionary[j]);
    } 

    printf("\n");

    return 0;
}



void FindFlag(char *dic_1, char *wd_f_1){
    int IsConti = 1;
    int diclen=cont_str(dic_1);
    int wdlen=cont_str(wd_f_1);

    for(int i = 0; i < (diclen-wdlen)+1; i++){
        for(int j = 0; j < wdlen; j++){
            if(IsConti == 0){break;}

            if(*(dic_1+i+j) == *(wd_f_1+j)){
                IsConti = 1;
            }else{
                IsConti = 0;
            }
        }
        //printf("a\n");
        if(IsConti == 1){
            flagL = i;
            flagR = i+wdlen;
            IsFind = 1;
            break;
        }else{
            IsConti = 1;
        }
    }
}


int cont_str(char *c){
    int len=0;
    while(c[len] != '\0'){
        len++;
    }
    return len;
}


char *cat_str(char *dest,const char *src)
{
	char *strDest=dest;
	assert(dest!=NULL && src!=NULL); 

	while(*dest !='\0')                   
	{
		dest++;
	}
	while((*dest++=*src++)!='\0');
    return strDest;
}


/*
void ReChar(char *dic, char *wd_f, char *wd_r){
    FindFlag(dic,wd_f);

    if (IsFind == 0){
        printf("置換後の文字列:%s\n",dic);
        return ;
    }

    printf("置換後の文字列:");
    for(int i = 0; i < flagL; i++){
        printf("%c",dic[i]);
    } 
    
    //cat_str(dic_final,wd_r);

    printf("%s",wd_r);
    //flag=cont_str(dic_final)+1;
    //printf("a");
    for(int j = flagR; j < cont_str(dic); j++){
        printf("%c",dic[j]);
    } 

    printf("\n");

}*/
