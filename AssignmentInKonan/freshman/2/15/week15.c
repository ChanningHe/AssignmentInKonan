/* 
  12171029 KaShouen
  https://github.com/ChanningHe/AssignmentInKonan/blob/main/AssignmentInKonan/freshman/2/15/week15.c
 */

#include<stdio.h>
#define LEN (100)

/* 文字列を圧縮する関数．これを自分で書くこと．この関数内にprintfなど
   の出力を書かないこと */

void compress(char *dna);
int cont_str(char *c);//Calculation the length of string


/* メイン関数．書き換えないこと */

int main(){

  char dna[LEN];

  /* 文字列を入力 */
  scanf("%99s", dna);

  /* 関数呼び出し */
  compress(dna);

  /* 結果表示 */
  printf("%s\n", dna);

  return 0;
}


void compress(char *dna){
  int flag = 0;//処理しているところ
  int strlen = cont_str(dna);//文字列の長さを計算する

  while(flag < strlen){
    int counter = 1, needCompress = 0;
    int flagt = flag;//tmp flag

    while(dna[flagt] == dna[flagt+1]){//連続する同⼀の⽂字の回数を計算する。
      counter++;
      flagt++;
      needCompress = 1;
    }

    if(needCompress == 1){//NeedCompress?
      dna[flag+1] = counter + '0';//連続する回数を書き込む
      
      for(int i = flagt+1; i < strlen; i++){//前に移動する
          dna[i-counter+2]=dna[i];
      }
      strlen=strlen-counter+2;
      dna[strlen]='\0';
      flag++;
    }

    flag++;
  }
  
}


int cont_str(char *c){
    int len=0;
    while(c[len] != '\0'){
        len++;
    }
    return len;
}