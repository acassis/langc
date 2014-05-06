#include <stdio.h>
#include <math.h>
#include<graphics.h>
void main()
{
     int drive=DETECT,modo;
     float lin=11,col=11,i=0,cl,ln;
     char h='s',v='s';
     initgraph(&drive,&modo,"c:\\bc\\bgi");
   while(!kbhit())
   {
     if(h=='s')
	col+=0.016;
     if(h=='d')
	col-=0.016;
     if(v=='s')
	lin+=0.016;
     if(v=='d')
	lin-=0.016;
     if(col>629)
	h='d';
     if(col<11)
	h='s';
     if(lin>469)
	v='d';
     if(lin<11)
	v='s';
     i+=0.002;
     cl=cos(i)*10 + col;
     ln=sin(i)*10 + lin;
     putpixel(cl,ln,15);
  }
     closegraph();
}