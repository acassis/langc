#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80
#include<graphics.h>
#include<grafico.h>
#include <stdio.h>
#include<dos.h>
#include <math.h>
void main(void)
{
   int gdriver = DETECT, gmode;
   char ch;
   float ang=0,x=0,y=0,raio=200,cor=1,col,lin,colant=0,linant=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   putpixel(320,240,15);
   while(1)
   {
     x = cos(ang) * raio;
     y = sin(ang) * raio;
     x=floor(x);
     y=floor(y);
     putpixel(x+320,y+240,15);
     //delay(1);
     putpixel(x+320,y+240,4);
     ch=inportb(0x60);
     if(ch>=100)
       if(ang>0.5)
	  ang-=0.05;
       if(ang>0.5)
	  ang+=0.05;
     if(ch=77)
	ang+=0.5;
     if(ch=75)
	ang-=0.5;
     ch=0;
     }
}


