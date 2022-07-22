/*
    グラフィックを使用するサンプルプログラム（４）

            アニメーション(描画☆を描く)

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "xgraph.h"

#define PAI      3.14159265358979
#define RAD(x)   ((x)/180.0*PAI)
#define RND(x)   (((double)rand()/RAND_MAX)*(x))
#define STAR_NUM  50

// ☆データを保持する構造体
typedef struct tagSTAR
{
  double x,y;  // 描画位置
  double dir_angle;  // 進行方向の角度
  double angle;      // 自転角度
  double rot_speed;  // 回転の速さ
  double speed;      // 移動スピード
  double radius;     // 半径
  double h;         // 描画色(色相、0～360)
  double xx[6],yy[6];
} STAR, *PSTAR;

void DrawStar( PSTAR st );
void MoveStar( PSTAR st );
void xEnd2( PSTAR st );

int main( void )
{
  STAR star[STAR_NUM];
  int i;

  srand((unsigned long)time(NULL));

  // ☆の初期化
  for(i=0;i<STAR_NUM;i++){
    star[i].x = RND(400.0); star[i].y = RND(400.0);
    star[i].angle = RND(2.0*PAI);
    star[i].rot_speed = RND(0.04)+0.0025;
    if( rand()%2 ) star[i].rot_speed *= -1.0;
    star[i].dir_angle = RND(2.0*PAI);
    star[i].speed = RND(1.0) + 0.05;
    star[i].radius = 32;
    star[i].h = ((double)i/STAR_NUM)*360.0;
    star[i].xx[0] = -9999.0;
  }

  xStart( 400, 400, 0 ); // <--- 描画準備

  // アニメーションのループ
  xEnd2( star );

}

/*****************************************************
  ☆を一つ描画する
******************************************************/
void DrawStar( PSTAR st )
{
  double a,px[6],py[6];
  int i,x1,y1,x2,y2;

  for(i=0;i<5;i++){
    a = 2.0*PAI/5.0*i*2.0 + st->angle;
    px[i] = st->radius * cos( a ) + st->x;
    py[i] = st->radius * sin( a ) + st->y;
  }
  px[5] = px[0]; py[5] = py[0];

  if( st->xx[0]> -100.0 ){
    xColor( 0,0,0 );
    for(i=0;i<5;i++) xLine( (int)st->xx[i],(int)st->yy[i],(int)st->xx[i+1],(int)st->yy[i+1] );
  }
  xColorHSV( st->h, 1.0, 1.0 );
  for(i=0;i<5;i++){
    xLine( (int)px[i],(int)py[i], (int)px[i+1],(int)py[i+1] );
    st->xx[i] = px[i]; st->yy[i] = py[i];
  }
  st->xx[5] = px[5]; st->yy[5] = py[5];
}

/*****************************************************
  ☆を動かす
******************************************************/
void MoveStar( PSTAR st )
{
  double dx,dy;

  // 位置を移動
  dx = st->speed*cos( st->dir_angle );
  dy = st->speed*sin( st->dir_angle );
  st->x += dx;  st->y += dy;
  if( st->x > 400.0 ){
    st->x -= dx; st->dir_angle = RND(PAI);
  }
  if( st->x < 0.0 ){
    st->x -= dx; st->dir_angle = RND(PAI) + PAI;
  }
  if( st->y > 400.0 ){
    st->y -= dy; st->dir_angle = RND(PAI) + PAI/2;
  }
  if( st->y < 0.0 ){
    st->y -= dy; st->dir_angle = RND(PAI) - PAI/2;
  }

  // 回転
  st->angle += st->rot_speed;
  if( st->angle > 2.0*PAI ) st->angle -= 2.0*PAI;
  if( st->angle < 0.0 ) st->angle += 2.0*PAI;

}

/*****************************************************
  アニメーション用に変更したもの
******************************************************/
void xEnd2( PSTAR st )
{
    int key;
    int i;

    while(1){
        key = 0;
	for(i=0;i<STAR_NUM;i++){
	  MoveStar( st+i );
	  DrawStar( st+i );
	}
	XCopyArea( gDisp, gPix, gWin, gGc, 0, 0, gWidth, gHeight, 0,0 );
        XNextEvent( gDisp, &gEv);
        switch( gEv.type ){
          case Expose: /* 画面再描画 */
            XCopyArea( gDisp, gPix, gWin, gGc, 0, 0, gWidth, gHeight, 0,0 );
            break;
          case KeyPress: /* キーが押された */
            key = XKeycodeToKeysym( gDisp, gEv.xkey.keycode, 0 );
            break;
        }
        if( key==0x63 || key==0xFF1B ) break; /* Crtl+C or Esc */
    }
 
    /* 終了処理 */
    XFreeGC( gDisp, gGc );
    XFreePixmap( gDisp, gPix );
    XDestroyWindow( gDisp, gWin );
}
