#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int maxx, maxy;
   initgraph(&gdriver,&gmode,"\\arquiv~1\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n",
	     grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   maxx = getmaxx();
   maxy = getmaxy();
   setcolor(getmaxcolor());
   setfillstyle(SOLID_FILL, getmaxcolor());
   getch();
   rectangle(0, 0, 630, 470);   getch();
   setfillstyle(SOLID_FILL, 14);
   floodfill(2, 2, 15);
   circle(maxx / 3, maxy /2, 50);   getch();
   setfillstyle(SOLID_FILL, 4);
   floodfill((maxx / 3)+3,(maxy /2)+3, 15);
   circle(maxx / 2, 20, 100);getch();
   setfillstyle(SOLID_FILL, 5);
   floodfill(maxx / 2+3, 20+3, 15);
   circle(maxx-20, maxy-50, 75);getch();
   setfillstyle(SOLID_FILL, 6);
   floodfill(maxx-20+3, maxy-50+3, 15);
   circle(20, maxy-20, 25);getch();
   setfillstyle(SOLID_FILL, 1);
   floodfill(20+3, maxy-20+3, 15);
   getch();
   closegraph();
   return 0;
}

