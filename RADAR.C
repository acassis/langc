#include <stdlib.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
typedef struct pos
{
   int x;
   int y;
}pos;

pos a[200];

void vsync( void )
{
  while( inp( 0x3da ) & 8 );   //Espera retra‡o Vertical,
  while( !(inp( 0x3da ) & 8) ); //Para que a tela nÆo pisque.
}

void main()
{
  int drive=DETECT,modo,ra=239,x,y,i,rdm,cor;
  float ang=0;
  initgraph(&drive,&modo,"c:\\bc\\bgi");
  for(;ra>0;ra-=59)
    circle(320,240,ra);
  setcolor(2);
  while(!kbhit())
  {
     ra=239;
     ang+=0.01;
     x = ra * cos(ang) + 320;
     y = ra * sin(ang) + 240;
     ra = random(240);
     a[0].x = ra * cos(ang) + 320;
     a[0].y = ra * sin(ang) + 240;
     for(i=198;i>-1;i--)
     {
	a[i+1].x=a[i].x;
	a[i+1].y=a[i].y;
     }
     setwritemode(1);
     setcolor(2);

     cor = getpixel(a[1].x,a[1].y);
     if(cor==0)
	putpixel(a[1].x,a[1].y,2);
     else
     if(cor==15)
	putpixel(a[1].x,a[1].y,10);

     setlinestyle(0, 2, 3);
     line(320,240,x,y);

     vsync();

     rdm = random(100);
     cor = getpixel(a[100+rdm].x,a[100+rdm].y);
     if(cor==2)
	putpixel(a[100+rdm].x,a[100+rdm].y,0);
     else
     if(cor==10)
	putpixel(a[100+rdm].x,a[100+rdm].y,15);


     cor = getpixel(a[199].x,a[199].y);
     if(cor==2)
	putpixel(a[199].x,a[199].y,0);
     else
     if(cor==10)
	putpixel(a[199].x,a[199].y,15);

     setlinestyle(0, 2, 3);
     line(320,240,x,y);
  }
  closegraph();
}