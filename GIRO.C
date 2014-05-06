#include<graphics.h>
#include<dos.h>
#include <math.h>
void main(void)
{
   int gdriver = DETECT, gmode;
   float ang=0,x=0,y=0,raio=200,cor=1;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   while(!kbhit())
   {
     ang+=0.007;
     x = cos(ang) * raio;
     y = sin(ang) * raio;
     setcolor(15);
     outtextxy(x+320, y+240, "ALAN");
     delay(1);
     setcolor(4);
     outtextxy(x+320, y+240, "ALAN");
   }
   closegraph();
}