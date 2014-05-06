#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <alloc.h>
#include <process.h>
#include<graphics.h>
void main(void)
{
  static int r	    = 20;
  static int StartX = 100;
  static int StartY = 50;

  struct viewporttype vp;
  int gdriver = DETECT, gmode,PauseTime, x, y, ulx, uly, lrx, lry, size, i, width, height, step,step2,x2,y2;
  void *disco;

  initgraph(&gdriver, &gmode, "c:\\bc\\bgi");

  getviewsettings( &vp );

  fillellipse(StartX, StartY, r, (r/3)+2);
  ellipse(StartX, StartY-4, 190, 357, r, r/3);
  line(StartX+7, StartY-6, StartX+10, StartY-12);
  circle(StartX+10, StartY-12, 2);
  line(StartX-7, StartY-6, StartX-10, StartY-12);
  circle(StartX-10, StartY-12, 2);
  setcolor(1);
  outtextxy(85,45,"Alan");


  /* Le a imagem do disco */
  ulx = StartX-(r+1);
  uly = StartY-14;
  lrx = StartX+(r+1);
  lry = StartY+32;
  width = lrx - ulx + 1;
  height = lry - uly + 1;
  size = imagesize(ulx, uly, lrx, lry);

  disco = malloc( size );
  getimage(ulx, uly, lrx, lry, disco);
  putimage(ulx, uly, disco, XOR_PUT);

  for ( i=0 ; i<1000; ++i )
    putpixel(random(640), random(480), random(15)+1);
  x = 640 / 2;
  y = 480 / 2;
  PauseTime = 50;

  /* enquanto nao teclar nada*/
  while ( !kbhit() ) {

    /* mostra os discos */
    putimage(x, y, disco, XOR_PUT);
    putimage(x2, y2, disco, XOR_PUT);
    delay(PauseTime);
    /* apaga os discos */
    putimage(x, y, disco, XOR_PUT);
    putimage(x2, y2, disco, XOR_PUT);

    /* Move os discos */

    step = random( 2*r );
    if ((step/2) % 2 != 0 )
      step = -1 * step;
    x = x + step;
    step = random( r );
    if ((step/2) % 2 != 0 )
      step = -1 * step;
    y = y + step;

    if (vp.left + x + width - 1 > vp.right)
      x = vp.right-vp.left-width + 1;
    else
      if (x < 0)
	x = 0;
    if (vp.top + y + height - 1 > vp.bottom)
      y = vp.bottom-vp.top-height + 1;
    else
      if (y < 0)
	y = 0;
    step2 = random( 2*r );
    if ((step/2) % 2 != 0 )
      step2 = -1 * step2;
    x2 = x2 + step2;
    step2 = random( r );
    if ((step2/2) % 2 != 0 )
      step2 = -1 * step2;
    y2 = y2 + step2;

    if (vp.left + x2 + width - 1 > vp.right)
      x2 = vp.right-vp.left-width + 1;
    else
      if (x2 < 0)
	x2 = 0;
    if (vp.top + y2 + height - 1 > vp.bottom)
      y2 = vp.bottom-vp.top-height + 1;
    else
      if (y2 < 0)
	y2 = 0;

  }
  free( disco );
  getch();
}
