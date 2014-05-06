#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
char *fname[] = { "DEFAULT_FONT",
		  "TRIPLEX_FONT",
		  "SMALL_FONT",
		  "SANS_SERIF_FONT",
		  "GOTHIC_FONT"
		};
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int style, midx, midy;
   int size = 1;
   initgraph(&gdriver,&gmode,"c:\\arquiv~1\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   for (style=DEFAULT_FONT; style<=GOTHIC_FONT; style++)
   {  cleardevice();
      if (style == TRIPLEX_FONT)
	 size = 4;
      settextstyle(style, HORIZ_DIR, size);
      outtextxy(midx, midy, fname[style]);
      getch();
   }
   closegraph();
   return 0;
}
/*
settextjustify
 Param   Name          Val   How justified
อออออออุอออออออออออออุอออออุอออออออออออออออออ
 horiz ณ LEFT_TEXT   ณ (0) ณ left          <
       ณ CENTER_TEXT ณ (1) ณ > center text <
       ณ RIGHT_TEXT  ณ (2) ณ >         right
ฤฤฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤลฤฤฤฤฤลฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ
 vert  ณ BOTTOM_TEXT ณ (0) ณ from bottom up
       ณ CENTER_TEXT ณ (1) ณ center text
       ณ TOP_TEXT    ณ (2) ณ from top down

settextstyle
Direction of graphics output

  HORIZ_DIR   Left to right
  VERT_DIR    Bottom to top
*/
