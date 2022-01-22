/*
  12171029 KaShouen
 */
#include<stdio.h>
#include<string.h>
//#include <algorithm>

#define STRING_LEN 100

int main(void){

  /* 変数．変更禁止 */
  char str1[STRING_LEN], str2[STRING_LEN]; /* 入力文字列格納用 */
  int cnt = 0; /* 最長一致文字列の長さ */

  /* 必要であればその他の変数をここで定義して良い */
  int len1=0,len2=0;
  int cnttmp=0,isConti=0;
  char chartmp[STRING_LEN];

  /* 入力．変更禁止 */
  scanf("%s", str1);
  scanf("%s", str2);

  /* 文字列をあらかじめすべて子文字に変換する．
     できれば書いてみよう．*/
  while(str1[len1]!='\0'){
    if(str1[len1] <= 90 && str1[len1] >= 65){str1[len1]+=32;}
    len1++;
  }

  while(str2[len2]!='\0'){
    if(str2[len2] <= 90 && str2[len2] >= 65){str2[len2]+=32;}
    len2++;
  }

  /* 連続して一致する最長の文字数を数える部分．自分で書くこと */
  if(len1 < len2){   //Put longer char_arrary into str1
    strcpy(chartmp,str1);
    strcpy(str1,str2);
    strcpy(str1,chartmp);
    len1=len1+len2;len2=len1-len2;len1=len1-len2;
  }

  for(int i=0;i<len1;i++){
    if( (len1-i) < len2 ){len2--;}
    for(int j=0;j<len2;j++){
      if(str1[i+j] == str2[j]){
        if(isConti == 0){cnttmp = 0;}//Is it continuous
        cnttmp++;
        isConti = 1;
      }else if(str1[i+j] != str2[j]){isConti = 0;}
      if(cnttmp > cnt){cnt = cnttmp;}
    }
    isConti == 0;
  }

  /* 出力．変更禁止 */
  printf("%d\n", cnt);
  
  return 0;
}
