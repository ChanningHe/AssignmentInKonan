#include <stdio.h>



// 1文字を交換する関数 
void cswap(char *s1, char *s2, int l)
{
    char tmpc;
    tmpc = s1[l]; s1[l]=s2[l]; s2[l]=tmpc;
}


int main(void) {
    char str1[100],str2[100];
    printf("文字列を入力してください(3文字以上)¥\n"); 
    scanf("%s",str1);
    scanf("%s",str2);
    printf("入力された文字列1 = %s\n", str1); 
    printf("入力された文字列2 = %s\n", str2);
    cswap(str1, str2, 0); // 1文字目を入れ替える 
    cswap(str1, str2, 1); // 2文字目を入れ替える 
    cswap(str1, str2, 2); // 3文字目を入れ替える 
    printf("文字列1 = %s\n", str1); 
    printf("文字列2 = %s\n", str2);
    printf("¥n");
    return 0; 
}