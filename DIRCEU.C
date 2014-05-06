#include <graphics.h>
#include <grafico.h>
#include <stdio.h>
int main(void)
{
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   setcolor(17);
   outtextxy(320,240,"Dirceu!!");
   getch();
   closegraph();
}
