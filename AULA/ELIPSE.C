#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   int stangle = 0, endangle = 360;
   int xradius = 100, yradius = 50;

   /* initialize graphics, local variables */
   initgraph(&gdriver,&gmode,"\\arquiv~1\\bc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   /* an error occurred */
   {
      printf("Graphics error: %s\n",
	     grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());

   /* draw ellipse */
   ellipse(midx, midy, stangle, endangle,
	   xradius, yradius);

   /* clean up */
   getch();
   closegraph();
   return 0;
}

