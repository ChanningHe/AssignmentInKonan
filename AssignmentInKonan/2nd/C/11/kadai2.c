
#include <stdio.h>

int main(void)
{
    unsigned char buf[100];
    FILE *fp;
    int i;

    char num[99];
    int n1,n2;

    fp = fopen( "data.bin", "rb" );
    fread( buf, sizeof(unsigned char), 20, fp );
    
    printf("＞mとnを入力-->");
    fgets(num,99,stdin);
    sscanf(num,"%d%d",&n1,&n2);

    printf("＞「data.bin」の %d バイト目から %d個表示\n ",n1,n2);
    for(i=n1-1;i<n1+n2-1;i++) printf(" %d", buf[i] );
    printf("\n");

    fclose( fp );
    return 0;
}