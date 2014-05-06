#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
/* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   struct arccoordstype arcinfo;
   int midx, midy;
   int stangle = 45, endangle = 270;
   char sstr[80], estr[80];

/* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");

/* read result of initialization */
   errorcode = graphresult();
/* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n",
	     grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
/* terminate with an error code */
      exit(1);
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;

/* draw arc and get coordinates */
   setcolor(2);
   arc(midx, midy, stangle, endangle, 100);
   getarccoords(&arcinfo);

/* convert arc information into strings */
   sprintf(sstr, "*- (%d, %d)",
	   arcinfo.xstart, arcinfo.ystart);
   sprintf(estr, "*- (%d, %d)",
	   arcinfo.xend, arcinfo.yend);

   /* output the arc information */
   outtextxy(arcinfo.xstart,
	     arcinfo.ystart, sstr);
   outtextxy(arcinfo.xend,
	     arcinfo.yend, estr);

   /* clean up */
   getch();
   closegraph();
   return 0;
}
