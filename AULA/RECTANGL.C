#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom;
   initgraph(&gdriver, &gmode, "\\arquiv~1\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   left = getmaxx() / 2 - 50;
   top = getmaxy() / 2 - 50;
   right = getmaxx() / 2 + 50;
   bottom = getmaxy() / 2 + 50;
   setcolor(14);
   rectangle(left,top,right,bottom);
   setcolor(1);
   rectangle(left+5,top+5,right-5,bottom-5);
   setcolor(3);
   rectangle(left+10,top+10,right-10,bottom-10);
   getch();
   closegraph();
   return 0;
}

