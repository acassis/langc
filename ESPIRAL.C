#include<dos.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
void main()
{
    int gdriver = DETECT, gmode,cor=1;
    float ang=0,x=0,y=0,raio=200;
    initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
  while(!kbhit())
  {
    ang +=0.001;
    x = cos(ang) * raio;
    y = sin(ang) * raio;
    raio -=0.01;
    putpixel(x+320,y+240,cor);
    cor++;
    if(cor>15)
       cor=1;
    if(raio<0)
    {
      cleardevice();
      raio=200;
    }
  }
}