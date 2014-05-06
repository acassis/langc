#include<graphics.h>
#include<grafico.h>
#include <stdio.h>
#include<dos.h>
#include <math.h>
void main(void)
{
   int gdriver = DETECT, gmode;
   float ang=0,x=0,y=0,raio=200,cor=1,col,lin,colant=0,linant=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   mouse();
   putpixel(320,240,15);
   while(!kbhit())
   {
     //ang+=0.007;
     col=colmouse();
     lin=linmouse();
     x = cos(ang) * raio;
     y = sin(ang) * raio;
     x=floor(x);
     y=floor(y);
     if(x==0)
	x=1;
     if(col==320){
	if(colant>320)
	    col=318;
	else
	    col=322;}
     if(((lin-240)/(col-320))>(y/x))
	 ang+=0.007;
     if(((lin-240)/(col-320))<(y/x))
	 ang-=0.007;
     if(col>320){
      putpixel(x+320, y+240,15);
     delay(1);
     putpixel(x+320, y+240,4);}
     if(col<320){
       putpixel(320-x, 240-y,15);
     delay(1);
     putpixel(320-x, 240-y,4);}
     colant=col;
     linant=lin;
   }
   closegraph();
}