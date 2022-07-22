/*
    グラフィックを使用するサンプルプログラム （２）

     ・点を描画する（指数分布のランダム）

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "xgraph.h"

#define RND ((double)rand()/RAND_MAX)

int main( void )
{
  int i,j,x,y;
  double a,b;

  srand(time(NULL));
  xStart( 400, 400, 0 ); // <--- 描画開始

  // この間に描画関数を記述する
  for(i=0;i<50000;i++){
    a = RND + RND; // 0.0～2.0 の乱数、指数分布
    b = RND + RND;
    x = (int)(a*200);
    y = (int)(b*200);
    // 色の指定
    xColor( rand()%256, rand()%256, rand()%256 );
    xPoint( x, y );
  }

  xEnd(); // <--- 描画終了
}




