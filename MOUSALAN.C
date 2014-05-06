#include <graphics.h>
#include <grafico.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define PIXEL_COUNT 1000
#define DELAY_TIME  100  /* in milliseconds */

int i, x, y, color, maxx, maxy, maxcolor, seed;

void diagonal()
{
  int dx,dy,x1=466,y1=166,y2=330,x2=530,i,xt,yt;
  float erro=0.0;
  dx=(x2-x1);
  dy=(y2-y1);
 for(i=0;i<=dy;i++)
  {
    if(x>=x1 && x<=x1+14 && y<=y1 && y>=y1-15){
      rectangle(x,y,x+1,y);
      break;}
    y1++;
    erro=erro+(float)dx/(float)dy;
    if(erro>0.5)
    {
      erro=erro-1.0;
      x1++;
     }
   }

}

int main(void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   maxx=getmaxx()+1;
   maxy=getmaxy()+1;
   maxcolor = getmaxcolor() + 1;
   mouse();
   while (!kbhit())
   {
	 x = colmouse();
	 y = linmouse();
	 /*color = random(16);
	 if(color==0 || color==15)
	    color=2;*/
	 setcolor(color);
	 if(x<220)
	    setcolor(1);
	 if(x>220 && x<320)
	    setcolor(2);
	 if(x>320 && x<450)
	    setcolor(4);
	 if(x>450)
	    setcolor(9);
	 if(x>100 && x<120 && y>150 && y<330 ||
	 x>100 && x<190 && y>150 && y<170 ||
	 x>170 && x<190 && y>150 && y<330 ||
	 x>100 && x<190 && y>240 && y<260 ||
	 x>220 && x<240 && y>150 && y<330 ||
	 x>220 && x<310 && y>310 && y<330 ||
	 x>340 && x<360 && y>150 && y<330 ||
	 x>340 && x<430 && y>150 && y<170 ||
	 x>410 && x<430 && y>150 && y<330 ||
	 x>340 && x<430 && y>240 && y<260 ||
	 x>460 && x<480 && y>150 && y<330 ||
	 x>530 && x<550 && y>150 && y<330 )
	 rectangle(x,y,x+1,y);
	 if(x>=465 && x<=530 )
	    diagonal();

   }

   /* clean up */
   getch();
   closegraph();
   return 0;
}