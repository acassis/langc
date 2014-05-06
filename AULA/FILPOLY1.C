#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int i, maxx, maxy;
   int poly[8];
   initgraph(&gdriver, &gmode, "\\arquiv~1\\bc\\bgi");
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
   poly[1] = maxy / 2;

   poly[2] = maxx - 20;
   poly[3] = 20;
   poly[4] = maxx - 50;
   poly[5] = maxy - 20;
   poly[6] = maxx / 2;
   poly[7] = maxy / 2;

   for (i=EMPTY_FILL; i<USER_FILL; i++)
   {
      setfillstyle(i, getmaxcolor());
      fillpoly(4, poly);
      getch();
   }
   closegraph();
   return 0;
}

