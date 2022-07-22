/*
    グラフィックを使用するサンプルプログラム （１）


     ・10x10の○を描画する

 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "xgraph.h"

int main( void )
{
  int i,j,x,y;

  srand(time(NULL));
  xStart( 400, 400, 0 ); // <--- 描画開始

  // この間に描画関数を記述する
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      x = i*40 + 20;
      y = j*40 + 20;
      // 色の指定
      xColor( rand()%256, rand()%256, rand()%256 );
      xCircle( x, y, 18 );
    }
  }
    xEnd(); // <--- 描画終了
}


