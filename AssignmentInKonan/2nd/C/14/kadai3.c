#include<stdio.h>

int main(){
    char t1[]=" Hyper Text Markup Language";
    char t2[]=" as soon as possible";
    char t3[]=" Universal Serial Bus";

    int t=0;
    puts(t1);
    printf(" --> ");
    while(t1[t] != '\0'){
    if(t1[t]==' '){
        printf("%c",t1[t+1]);
    }
    t++;
    }
    printf("\n");

    puts(t2);
    printf(" --> ");
    t=0;
    while(t2[t] != '\0'){
    if(t2[t]==' '){
        printf("%c",t2[t+1]);
    }
    t++;
    }
    printf("\n");

    t=0;
    puts(t3);
    printf(" --> ");
    while(t3[t] != '\0'){
    if(t3[t]==' '){
        printf("%c",t3[t+1]);
    }
    t++;
    }

    printf("\n");
    //fgets(num,99,stdin);
    //sscanf(num,"%d%d",&n1,&n2);

    return 0;
}