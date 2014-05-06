#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int x = 0, y = 0;
   int i;
   char msg[80];
   initgraph(&gdriver, &gmode, "\\arquiv~1\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
      }
	 y = getmaxy() / 2;
	 x = getmaxy() / 2;

   settextjustify(LEFT_TEXT, CENTER_TEXT);
   for (i=1; i<11; i++)
   {
      /* select the text style, direction, and size
      DEFAULT_FONT       8x8 bit-mapped font
      TRIPLEX_FONT       Stroked font
      SMALL_FONT         Stroked font
      SANS_SERIF_FONT    Stroked font
      GOTHIC_FONT        Stroked font   */
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, i);
      sprintf(msg, "Size: %d", i);
      outtextxy(x, y, msg);
      x += textwidth(msg);
      outtextxy(x, y, msg);
      x += textwidth(msg);
   }   getch();
   closegraph();
   return 0;
}

