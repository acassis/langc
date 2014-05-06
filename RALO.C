#include <stdio.h>
#include <math.h>
#include<graphics.h>
void main()
{
     int drive=DETECT,modo,p[8];
     float lin=11,col=11,i=0,cl,ln,r=1,cor;
     initgraph(&drive,&modo,"d:\\bc\\bgi");
     setfillstyle( SOLID_FILL, 2 );
     bar(0,0,320,240);
     setfillstyle( SOLID_FILL, 1 );
     bar(320,0,640,240);
     setfillstyle( SOLID_FILL, 4 );
     bar(320,240,640,480);
     setfillstyle( SOLID_FILL, 15 );
     bar(0,240,320,480);

    while(1)
    {
     i+=0.01;
     r+=0.0001;
     cl=cos(i)*r + 320;
     ln=sin(i)*r + 240;
     cor=getpixel(cl, ln);
     cl=cos(i-1)*r + 320;
     ln=sin(i+2)*r + 240;
     putpixel(cl,ln,cor);
     cl=cos(i+2)*r + 320;
     ln=sin(i-1)*r + 240;
     putpixel(cl,ln,cor);
     if(r>230)
       break;
    }
     getch();
     closegraph();
}