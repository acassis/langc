#include <graphics.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode,p[8];
   int xcenter, ycenter, i;
   initgraph(&gdriver,&gmode,"c:\\bc\\bgi");
   xcenter = 320;
   ycenter = 240;
   setfillstyle(1,14);
   fillellipse(320,240,10,10);
   circle(320,240,40);
   setcolor(4);
   setfillstyle(1,4);
   pieslice(320,210,0,180,10);
   p[1]=210;p[0]=310;
   p[7]=230;p[6]=315;
   p[4]=325;p[5]=230;
   p[3]=210;p[2]=330;
   fillpoly(4, p);
   setcolor(1);
   line(310,210,315,230);
   line(325,230,330,210);
   setcolor(4);
   setfillstyle(1,4);
   fillellipse(320,270,10,10);
   p[0]=310;p[1]=270;
   p[7]=250;p[6]=315;
   p[4]=325;p[5]=250;
   p[3]=270;p[2]=330;
   fillpoly(4, p);
   setcolor(1);
   line(310,270,315,250);
   line(325,250,330,270);
   setcolor(4);
   setfillstyle(1,4);
   fillellipse(290,240,10,10);
   fillellipse(350,240,10,10);
   getch();
   closegraph();
   return 0;
}
