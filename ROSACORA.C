#include<dos.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
void cardio(int col,int lin,int r)
{
   int p[6];
   fillellipse(col-r,lin,r,r);
   fillellipse(col+r,lin,r,r);
   pieslice(col,lin,180,210,2*r);
   pieslice(col,lin,330,360,2*r);
   p[0]=col-(1.75*r);p[1]=0.98*r+lin;
   p[2]=col;p[3]=3.3*r+lin;
   p[4]=col+(1.75*r);p[5]=0.98*r+lin;
   fillpoly(3, p);
   p[2]=col;
   p[3]=lin;
   fillpoly(3, p);
}

void main()
{
    static int r	    = 20;
    static int StartX = 100;
    static int StartY = 50;

    char resp='n',conf=0;
    struct viewporttype vp;
    int gdriver = DETECT, gmode,cor=1,ct=0, x, y, ulx, uly, lrx, lry, size,step;
    float ang1=0,x1=0,y1=0,raio1=100,ang2=0,x2,y2,raio2=10;
    void *Saucer;
    initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
    getviewsettings( &vp );
    setcolor(4);
    setfillstyle( SOLID_FILL,4 );
    cardio(StartX,StartY,10);
    ulx = StartX-(r+1);
    uly = StartY-14;
    lrx = StartX+(r+1);
    lry = StartY+32;
    size = imagesize(ulx, uly, lrx, lry);

    Saucer = malloc( size );
    getimage(ulx, uly, lrx, lry, Saucer);
    putimage(ulx, uly, Saucer, XOR_PUT);

    setcolor(15);
    setfillstyle( SOLID_FILL, 9);
    bar(0,0,639,479);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
    outtextxy(200,50,"Helem!");
    outtextxy(140,300,"Vocˆ ‚ a...");
    setcolor(15);
    delay(2000);
    bar(0,0,639,479);
    delay(200);
  while(!kbhit())
  {
   if(ang1<6.5)
   {
    ang1+=0.0001;
    x1 = cos(ang1) * raio1;
    y1 = sin(ang1) * raio1;
   }
   if(ang1>=6.5 && ang1<=6.6)
   {
     ang1=7.32;
     raio1=90;
   }
   if(ang1>=6.7 && ang1<13.0)
   {
    ang1+=0.7;
    x1 = cos(ang1) * raio1;
    y1 = sin(ang1) * raio1;
   }
    ang2+=0.001;
    x2 = cos(ang2) * raio2;
    y2 = sin(ang2) * raio2;

    if(ang1<6.5)
     putpixel(x2+x1+320,y2+y1+150,15);
   if(ang1>=6.5 && ang1<14.0)
   {
     line(320,150,x1+320,y1+150);
     delay(200);
  }
  if(ang1>13.0 && ang1<13.7)
  {
    resp='s';
    ang1=14.0;
  }
  if(resp=='s')
  {
    setfillstyle( SOLID_FILL, 4);
    floodfill(320, 140, 15);
    delay(200);
    floodfill(330, 140, 15);
    delay(200);
    floodfill(350, 140, 15);
    delay(200);
    floodfill(330, 165, 15);
    delay(200);
    floodfill(330, 170, 15);
    delay(200);
    floodfill(310, 170, 15);
    delay(200);
    floodfill(300, 165, 15);
    delay(200);
    floodfill(300, 140, 15);
    delay(200);
    floodfill(300, 130, 15);
    delay(200);
    setfillstyle( SOLID_FILL, 14);
    fillellipse(320,150,10,10);
    delay(200);
    resp='n';
    raio2=600;
    ang2=2.9;
  }

  if(ang1>13.9 && ang2>2.8 && ct<121)
  {
     ang2+=0.001;
     x2 = cos(ang2) * raio2;
     y2 = sin(ang2) * raio2;

     putpixel(x2+898,y2+350,15);

   if(ang2<3.301)
     putpixel(x2+907,y2+350,15);

     if(ang2>3.311)
	ang2=2.8;
  }
  if(ang1>13.9 && ang2<2.9)
  {
     ct++;
  }
  if(ct>120 && ct<122)
  {
    setfillstyle( SOLID_FILL, 6);
    floodfill(304, 300, 15);
    delay(200);
    setfillstyle( SOLID_FILL, 10);
    fillellipse(330,400,20,10);
    delay(300);
    fillellipse(260,300,40,10);
    delay(1000);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
    outtextxy(420,50,"Da");
    delay(500);
    outtextxy(420,150,"minha");
    delay(500);
    outtextxy(420,260,"VIDA!!!...");
    delay(1000);
    conf=1;
  }
  if(conf==1)
  {
    putimage(x, y, Saucer, XOR_PUT);		     /*  draw image  */
    //delay(15);
    //putimage(x, y, Saucer, OR_PUT);		     /* erase image  */

    x= random(640);
    y= random(480);

  }
  }
  closegraph();
}