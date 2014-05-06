#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int i, maxx, maxy;
   int poly[6];
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
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
   poly[0] = 20;
   poly[1] = 2;

   poly[2] = 320; /* 2nd */
   poly[3] = 440;

   poly[4] = 640; /* 3rd */
   poly[5] = 2;
   /*
      4th vertex. fillpoly automatically
      closes the polygon.
   poly[6] = 10;
   poly[7] = 200;*/
   setfillstyle(1,1);
   fillpoly(3, poly);
   getch();
   closegraph();
   return 0;
}