/********************************************************


         Graphics Library for X Window (UTF-8)

                               ver. 2.05

                             last update  2022.05.11
                                  update  2003.10.03

********************************************************/

/*   使い方

・画面クリックでマウス座標を取得できる
　- マウスを使う時は、 
　  #define USING_MOUSE を定義して　かつ
　  void xMouseClicked( void ){ の本体を実装すること。　
　- マウスの座標は mouseX, mouseY に格納されている

<< コンパイルの方法 >>

 % gcc Sample.c -lX11 -lm

 パスが通っていない場合は
 % gcc Sample.c -L/usr/X11R6/lib -lX11 -lm


<< ソースファイルにて >>
#define USING_MOUSE <--- マウスを使う場合は定義する 
                         その場合、xMouseClicked()も実装する 
#include "xgraph.h"

int main( void ) 
{
    xStart( 640, 480, 0 ); // <--- 描画開始

    // この間に描画関数を記述する

    xEnd(); // <--- 描画終了
}


<< 関数 >>
unsigned long xRGB( int r, int g, int b )
void xColor( int r, int g, int b )
void xColorHSV( int h, int s, int v )
void xStart( int width, int height, int back )
void xEnd( void )
void xCls( void )
void xText( char *str, int x, int y )
void xCircle( int x, int y, int r )
void xCircleFill( int x, int y, int r )
void xPoint( int x, int y )
void xLine( int x1, int y1, int x2, int y2 )
void xRect( int x1, int y1, int w, int h )
void xRectFill( int x1, int y1, int w, int h )
void xEllipse( int x1, int y1, int x2, int y2 )
void xEllipseFill( int x1, int y1, int x2, int y2 )
void xLines( int n, int x[], int y[] )
void xPolygon( int n, int x[], int y[] )

-------------------------------------------------------
※注意
　Fontがないとのエラーが表示された場合、「xlsfonts」で
　フォント一覧を表示して確認する。

　gFont = XLoadFont( gDisp, "10x20" );

　を変更すること
-------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

Display *gDisp;
Window gWin;
int gScreen, gHeight, gWidth;
Font gFont;
XEvent gEv;
Pixmap gPix;

int mouseX, mouseY;

//  Attributes of GC
XSetWindowAttributes gGcAtt;

// base GC
GC gGc;

#ifdef USING_MOUSE
void xMouseClicked( void ); /* プログラマーが別途が用意すること */
#endif


// Select Color
unsigned long xRGB( int r, int g, int b )
{
    Colormap cmap;
    XColor   col;

    cmap = DefaultColormap( gDisp, 0 );
    col.red   = 256 * r;
    col.green = 256 * g;
    col.blue  = 256 * b;
    XAllocColor( gDisp, cmap, &col );
    return  col.pixel ;
}


void xColor( int r, int g, int b )
{
    XSetForeground( gDisp, gGc, xRGB( r, g, b) );
}

void xColorHSV( double h, double s, double v )
{
    double  r,g,b;
    int hi;
    double f,p,q,t;

    h = fmod( h, 360.0 );
    hi = fmod( floor(h / 60.0), 6.0);
    f = h / 60.0 - hi;
    p = v * (1.0 - s);
    q = v * (1.0 - f * s);
    t = v * (1.0 - (1.0 - f) * s);

    switch( hi )
    {
    case 0:
      r = v; g = t; b = p; break;
    case 1:
      r = q; g = v; b = p; break;
    case 2:
      r = p; g = v; b = t; break;
    case 3:
      r = p; g = q; b = v; break;
    case 4:
      r = t; g = p; b = v; break;
    case 5:
      r = v; g = p; b = q; break;
    default:
      r = g = b = 0.0;
    }
    xColor( (int)(255.0*r), (int)(255.0*g), (int)(255.0*b) );
}


//
// Open window
//
void xStart( int width, int height, int back )
{

    void xRectFill( int x1, int y1, int x2, int y2 );
    int c;

    mouseX = mouseY = 0;

     /* デフォルト色の設定 */
    if( !back ){
      c = 0; /* 背景は黒色 */
    }else{
      c = 255; /* 背景は白色 */
    }

    /* Windowを作成する */
    if( (gDisp = XOpenDisplay(NULL)) == NULL ){
        printf( "Can't open display\n" );
        exit( -1 );
    }
    gScreen = DefaultScreen( gDisp );
    gWin = XCreateSimpleWindow( gDisp, RootWindow( gDisp, 0 ), 100, 100, 
			      width, height, 2, xRGB( 0xff, 0xff, 0xff ), 
				xRGB(    c,    c,    c ) );
 
    XStoreName( gDisp, gWin, "X Window Graphics Library" );

    /* Attributes of GC: Backing Store */
    gGcAtt.backing_store = Always;
    XChangeWindowAttributes( gDisp, gWin, CWBackingStore, &gGcAtt );

    /* MAP NOTIFYING */
    XSelectInput( gDisp, gWin, StructureNotifyMask|ExposureMask|KeyPressMask|ButtonPressMask );
    XMapWindow( gDisp, gWin );
    
    while(1){
        XNextEvent( gDisp, &gEv );
	if( gEv.type == MapNotify ) break;
    }

    /* Base GC */
    gGc = XCreateGC( gDisp, gWin, 0, 0 );
    XCopyGC( gDisp, DefaultGC(gDisp, gScreen), 0, gGc );
    gFont = XLoadFont( gDisp, "10x20" );
    XSetFont( gDisp, gGc, gFont );

    /* Pixmapの作成  //0926 */
    gPix = XCreatePixmap( gDisp, gWin, width, height, DefaultDepth( gDisp, gScreen ));
    
    gHeight = height; gWidth = width;
    xColor(c,c,c);
    xRectFill(0,0,height,width);
    //printf("GraphicWindow上で「Esc」キーを押すと終了します。\n");
    XFlush( gDisp );   

    /* デフォルト色の設定 */
    if( !back ){
       	xColor( 255,255,255 ); /* 描画色は白色 */
    }else{
       	xColor( 0, 0, 0 ); /* 描画色は黒色 */
    }
}

void xEnd( void )
{
    int key;
    //printf("Hit Enter key to end...");
    //getchar(); getchar();
    while(1){
        key = 0;
        XNextEvent( gDisp, &gEv );
        switch( gEv.type ){
          case Expose: /* 画面再描画 */
		    XCopyArea( gDisp, gPix, gWin, gGc, 0, 0, gWidth, gHeight, 0,0 );
            break;
          case KeyPress: /* キーが押された */
            //key = XKeycodeToKeysym( gDisp, gEv.xkey.keycode, 0 );
            break;
          case ButtonPress: /* マウスボタンが押された */
    	    mouseX = gEv.xbutton.x;
    	    mouseY = gEv.xbutton.y;
    	    #ifdef USING_MOUSE
    	        xMouseClicked(); /* プログラマーが別途が用意すること */
            #endif
	    break;
	}
        if( key==0x63 || key==0xFF1B ) break; /* Crtl+C or Esc */
    }

    /* 終了処理 */
    XFreeGC( gDisp, gGc );
    XFreePixmap( gDisp, gPix ); //0926
    XDestroyWindow( gDisp, gWin );
}


//
// Drawing Functions
//

void xCls( void )
{
    XClearWindow( gDisp, gWin );
    XClearWindow( gDisp, gPix );
    XFlush( gDisp );
}

void xText( char *str, int x, int y )
{
    XDrawString( gDisp, gWin, gGc, x, y, str, strlen(str) );
    XDrawString( gDisp, gPix, gGc, x, y, str, strlen(str) );
    XFlush( gDisp );
}

void xCircle( int x, int y, int r )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XDrawArc( gDisp, gWin, gGc, x-r, y-r, 2*r, 2*r, 1, 23040 );
    XDrawArc( gDisp, gPix, gGc, x-r, y-r, 2*r, 2*r, 1, 23040 );
    XFlush( gDisp );
}

void xCircleFill( int x, int y, int r )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XFillArc( gDisp, gWin, gGc, x-r, y-r, 2*r, 2*r, 1, 23040 );
    XFillArc( gDisp, gPix, gGc, x-r, y-r, 2*r, 2*r, 1, 23040 );
    XFlush( gDisp );
}

void xPoint( int x, int y )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XDrawPoint( gDisp, gWin, gGc, x, y );
    XDrawPoint( gDisp, gPix, gGc, x, y );
    XFlush( gDisp );
}

void xLine( int x1, int y1, int x2, int y2 )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XDrawLine( gDisp, gWin, gGc, x1, y1, x2, y2 );
    XDrawLine( gDisp, gPix, gGc, x1, y1, x2, y2 );
    XFlush( gDisp );
}

void xRect( int x1, int y1, int w, int h )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XDrawRectangle( gDisp, gWin, gGc, x1, y1, w, h );
    XDrawRectangle( gDisp, gPix, gGc, x1, y1, w, h );
    XFlush( gDisp );
}

void xRectFill( int x1, int y1, int w, int h )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XFillRectangle( gDisp, gWin, gGc, x1, y1, w, h );  
    XFillRectangle( gDisp, gPix, gGc, x1, y1, w, h );
    XFlush( gDisp );
}

void xEllipse( int x1, int y1, int x2, int y2 )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XDrawArc( gDisp, gWin, gGc, x1, y1, x2-x1, y2-y1, 0, 360*64 );
    XDrawArc( gDisp, gPix, gGc, x1, y1, x2-x1, y2-y1, 0, 360*64 );
    XFlush( gDisp );
}

void xEllipseFill( int x1, int y1, int x2, int y2 )
{
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XFillArc( gDisp, gWin, gGc, x1, y1, x2-x1, y2-y1, 0, 360*64 );
    XFillArc( gDisp, gPix, gGc, x1, y1, x2-x1, y2-y1, 0, 360*64 );
    XFlush( gDisp );
}

void xLines( int n, int x[], int y[] )
{
    XPoint points[100];
    int i;

    if (n > 99) n=99;

    for (i=0; i<n; i++) {
      points[i].x = x[i];
      points[i].y = y[i];
    }
   
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XDrawLines( gDisp, gWin, gGc, points, n, CoordModeOrigin );
    XDrawLines( gDisp, gPix, gGc, points, n, CoordModeOrigin );
    XFlush( gDisp );
}

void xPolygon( int n, int x[], int y[] )
{
    XPoint points[100];
    int i;

    if (n > 99) n=99;

    for (i=0; i<n; i++) {
      points[i].x = x[i];
      points[i].y = y[i];
    }
    XSetLineAttributes( gDisp, gGc, 1, LineSolid, CapRound, JoinRound );
    XFillPolygon( gDisp, gWin, gGc, points, n, 1, CoordModeOrigin );
    XFillPolygon( gDisp, gPix, gGc, points, n, 1, CoordModeOrigin );
    XFlush( gDisp );
}


