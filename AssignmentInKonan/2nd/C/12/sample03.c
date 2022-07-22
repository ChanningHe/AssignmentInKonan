/*
    グラフィックを使用するサンプルプログラム （３）

     ・y=sin(2x)のグラフ描画（x:-π～π）

       -πからπまで100等分して、そのｙの値を計算し、
       次に100個の点をつないでグラフを描く
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "xgraph.h"

#define PAI 3.14159265358979

int main( void )
{
  int i,x1,y1,x2,y2;
  double a,x[100],y[100];

  // x, y=sin(2x)の計算
  for(i=0;i<100;i++){
      x[i] = ((double)i/100)*2*PAI - PAI;
      y[i] = sin( 4.0*x[i] );
  }

  xStart( 400, 400, 0 ); // <--- 描画準備

  // 軸の描画
  xColor( 255,255,255 ); // 白色
  xLine(   0,200, 399,200 ); // X軸
  xLine( 200,  0, 200,399 ); // Y軸

  // グラフ描画
  xColor( 255,255,0 ); // 黄色
  a = (double)400/(2*PAI); // 実座標 --> ピクセル単位 の縮尺
  // 100個の点を直線でつないで曲線描画
  for(i=1;i<100;i++){
      x1 = (int)(a*x[i-1]) + 200;
      y1 = -(int)(a*y[i-1]) + 200;
      x2 = (int)(a*x[i]) + 200;
      y2 = -(int)(a*y[i]) + 200;
      xLine( x1,y1, x2,y2 );
  }
  xEnd(); // <--- 描画終了
}




