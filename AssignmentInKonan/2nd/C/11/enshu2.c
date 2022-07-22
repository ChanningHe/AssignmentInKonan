#include<stdio.h>
#include<string.h>
int main(){
    FILE *fp;
    fp = fopen("data.bin","wb");
    unsigned char a[10];//={50,51,52,53,54,55,56,57,58,59};
    unsigned char b[10];//={50,51,52,53,54,55,56,57,58,59};

    int t1=50,t2=100;
    for(int i=0; i<10; i++){
        a[i]=50+i;
        b[i]=i+100;
        printf("%c %c\n",a[i],b[i]);
    }

    fwrite(a,sizeof(unsigned char),10,fp);
    fwrite(b,sizeof(unsigned char),10,fp);
    fclose(fp);
    return 0;
}


