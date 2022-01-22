#include <stdio.h>
#include <string.h>

int main()
{
    int cake_s,pp_s=0,get=0;;
    int cake[101],cake_t[101];
    int *cake_p=cake;

    printf("クッキーの総数? ");
    scanf("%d",&cake_s);
    int tmp;
    do{
        pp_s++;
        printf("%d番目の友人の希望個数? ",pp_s);
        scanf("%d",&tmp);
        //if(tmp <= 0){break;}
        *cake_p=tmp;
        cake_p++;

    }while(tmp >= 0);


    memcpy(cake_t,cake,(pp_s-1)*sizeof(int));
    int cake_s_t = cake_s;

    
    while (cake_s_t > 0 && get < pp_s-1){
        for(int j = 0; j < pp_s; j++){
            if(cake[j] > 0){
                cake[j]--;
                cake_s_t--;
            }else if(cake[j] == 0){
                cake[j]--;
                get++;
            }
        }
    }

    /*
    for(int i=0; i<6; i++){
        printf("   %d  \n",cake_t[i]);
    }
    */
    
    printf("\nクッキーの総数:%d\n",cake_s);

    for(int u=0; u < pp_s-1; u++){
        printf("%d 番目の友人: 希望個数:%d - ",u+1,cake_t[u]);
        if(cake[u] == 0){
            printf("貰えた個数:%d\n",cake_t[u]-cake[u]);
        }else{
            printf("貰えた個数:%d\n",cake_t[u]-cake[u]-1);
        }
    }

    /*
        for(int i=0; i<6; i++){
        printf("   %d  \n",cake[i]);
    }*/
    return 0;

}