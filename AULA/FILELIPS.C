#include <graphics.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode;
   int xcenter, ycenter, i;

   initgraph(&gdriver,&gmode,"\\arquiv~1\\bc\\bgi");
   xcenter = getmaxx() / 2;
   ycenter = getmaxy() / 2;

   for (i=0; i<13; i++)
   {
      setfillstyle(i,WHITE);
      fillellipse(xcenter,ycenter,100,50);
      getch();
   }

   closegraph();
   return 0;
}


