
#include <stdio.h>

int main(void)
{
    unsigned char buf[100];
    FILE *fp;
    int i;
    fp = fopen( "data.bin", "rb" );

    FILE *gusu;
    gusu = fopen("gusu.bin","wb");
    FILE *kisu;
    kisu = fopen("kisu.bin","wb");

    
    fread( buf, sizeof(unsigned char), 20, fp );

    for(i=0;i<20;i++){
        if(buf[i]%2==1){
            fwrite(&buf[i],sizeof(unsigned char),10,kisu);
        }if(buf[i]%2==0){
            fwrite(&buf[i],sizeof(unsigned char),10,gusu);
        }
    }

    fclose(fp);
    fclose(kisu);
    fclose(gusu);
    return 0;
}