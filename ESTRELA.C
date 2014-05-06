#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(void)
{
   int gdriver = DETECT, gmode,p[8],col,lin,x,y,i;
   float ang = 0,alfa=2.51,raio;
   initgraph(&gdriver, &gmode, "d:\\bc\\bgi");
   x = cos(ang) * raio;
   y = sin(ang) * raio;
   setcolor(15);
   for(raio=0;raio<240;raio+=0.5)
    {
     ang = 0.95;
     for(i=0;i<5;i++)
     {
      ang += 2.512;
      col = cos(ang) * raio;
      lin = sin(ang) * raio;
      line(x+320,y+240,col+320,lin+240);
      x=col;
      y=lin;
     }
    }
    setcolor(1);
    outtextxy(253,240,"Vocˆ vai brilhar!");
    delay(1000);

    setfillstyle(1, 9);
    floodfill(2, 2, 15);

    delay(500);

    getch();
}