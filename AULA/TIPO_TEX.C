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
様様様謡様様様様様様謡様様謡様様様様様様様様�
 horiz � LEFT_TEXT   � (0) � left          <
       � CENTER_TEXT � (1) � > center text <
       � RIGHT_TEXT  � (2) � >         right
陳陳陳津陳陳陳陳陳陳津陳陳津陳陳陳陳陳陳陳陳�
 vert  � BOTTOM_TEXT � (0) � from bottom up
       � CENTER_TEXT � (1) � center text
       � TOP_TEXT    � (2) � from top down

settextstyle
Direction of graphics output

  HORIZ_DIR   Left to right
  VERT_DIR    Bottom to top
*/
