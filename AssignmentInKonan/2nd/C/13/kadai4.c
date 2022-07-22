#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100000

int getHand( void );
int getHand2( int g, int c, int p);
int isWin( int me, int com);

int main(void)
{
    char *jk[] = {"グー","チョキ","パー"};
    int cnt[3];
    int i,h;
    int pa,pb;
    srand( (unsigned int)time(NULL) );

    for(i=0;i<3;i++) cnt[i] = 0;
    for(i=0;i<NUM;i++){
        pa = getHand2(5, 4, 1); //A の出目
        pb = getHand2(1, 1, 1); // B の出目
        int result = isWin(pa ,pb);
        if(result == 1){
            cnt[0]++; //a勝ち
        }else if(result == -1){
            cnt[1]++;//b勝ち
        }
    }
    printf("B = (1, 1, 1)\n");
    printf("A勝ち回数:%d\n",cnt[0]);
    printf("B勝ち回数:%d\n",cnt[1]);
    return 0;
}

int getHand( void )
{
    int ret;
    ret = (int)(3.0*(double)rand()/((double)RAND_MAX+1.0))+1;
    return ret;
}


int getHand2( int g, int c, int p ){
    int ret;
    double sum=g+c+p;
    ret = (int)(1.0*sum*(double)rand()/((double)RAND_MAX+1.0))+1;
    if(ret <= g){
        return 1;
    }else if(ret <= (g+c)){
        return 2;
    }else if(ret <= (g+c+p)){
        return 3;
    }

}

int isWin( int me, int com )
{
    if( me==com ) return 0; // あいこ
    if( me==1 ){ // me がグー
        if( com==2 ) return 1; else return -1;
    }else if( me==2 ){  // me がチョキ
        if( com==3 ) return 1; else return -1;
    }else{  // me がパー
        if( com==1 ) return 1; else return -1;
    }
}