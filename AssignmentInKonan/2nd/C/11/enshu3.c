
#include <stdio.h>

int main(void)
{
    unsigned char buf[100];
    FILE *fp;
    int i;

    fp = fopen( "data.bin", "rb" );
    fread( buf, sizeof(unsigned char), 20, fp );

    printf("＞ファイル「data.bin」の内容を表示\n ");
    for(i=0;i<20;i++) printf(" %d", buf[i] );
    printf("\n");

    fclose( fp );
    return 0;
}