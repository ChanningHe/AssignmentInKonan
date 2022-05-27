#include<stdio.h>
#include <stdlib.h>

#pragma pack(2) /* alignmentを2バイトにする */
#define INFILE "test.bmp"

typedef struct BITMAPFILEHEADER {
unsigned short bfType; /* ファイルタイプ、必ず"BM" */
unsigned int bfSize; /* ファイルサイズ */ //TARGET
unsigned short bfReserved1; /* リザーブ */
unsigned short bfReserved2; /* リサーブ */
unsigned int bfOffBits; /* 先頭から画像情報までのオフセット */
} BITMAPFILEHEADER;

typedef struct BITMAPINFOHEADER {
unsigned int biSize; /* この構造体のサイズ */
unsigned int biWidth; /* 画像の幅 */ //TARGET
unsigned int biHeight; /* 画像の高さ */
unsigned short biPlanes; /* 画像の枚数、通常1 */
unsigned short biBitCount; /* 一色のビット数 */
unsigned int biCompression; /* 圧縮形式 */
unsigned int biSizeImage; /* 画像領域のサイズ */
unsigned int biXPelsPerMeter; /* 画像の横方向解像度情報 */
unsigned int biYPelsPerMeter; /* 画像の縦方向解像度情報*/
unsigned int biClrUsed; /* カラーパレットのうち実際に使っている色の個数 */
unsigned int biClrImportant; /* カラーパレットのうち重要な色の数 */
} BITMAPINFOHEADER;

int main(){
    FILE *bitfile = fopen("test.bmp",r);
    if(fp == NULL) { 
        printf("ファイルをオープンできませんでした。¥n");
        return 1;
    }
    struct BITMAPFILEHEADER bfh;
    struct BITMAPINFOHEADER bih;

    fget(bfh.bfType,2,bitfile);
    fget(bfh.bfSize,4,bitfile);
    fget(bfh.bfReserved1,2,bitfile);
    fget(bfh.bfReserved2,2,bitfile);
    fget(bfh.bfOffBits,4,bitfile);
    fget(bih.biSize,4,bitfile);
    fget(bih.biWidth,4,bitfile);

    printf("画像の幅：%d\n",bfh.bfSize);
    printf("ファイルサイズ：%d\n",bih.biWidth);
    
    fclose(bitfile);

    return 0;
}