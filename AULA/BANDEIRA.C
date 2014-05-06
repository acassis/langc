#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main (void)
{  int gdriver=DETECT, gmode, errorcode,maxx, maxy, i, y;
  initgraph(&gdriver, &gmode, "d:\\bc\\bgi");
  errorcode=graphresult();
  if (errorcode != grOk)
   {printf ("Graphics error: %s\n", grapherrormsg(errorcode));
    printf ("Pressione qualquer tecla para continuar...");
    getch();   exit(1);   }
  cleardevice();
  setfillstyle(SOLID_FILL, 2);
  bar(0,0,640,450);
  setcolor(14);
  for(i=45; i<400; i++)  line(50,210,320,i);
  for(i=45; i<400; i++)  line(580,210,320,i);
  setcolor(1);  setfillstyle(SOLID_FILL,1); sector(320,220,0,360,100,100);
  setcolor(15);
  for(i=0; i<20; i++)  arc(320, i+290, 36, 144, 124);
  circle(340,160,1);
  circle(300,290,1);
  circle(360,210,1);
  circle(350,280,1);
  circle(235,230,1);
  circle(265,265,1);
  putpixel(300,250,15);
  circle(324,252,1);
  circle(327,240,1);
  circle(370,265,1);
  circle(400,250,1);
  circle(390,280,1);
  circle(360,260,1);
  circle(365,290,1);
  circle(375,250,1);
  circle(350,270,1);
  circle(395,265,1);
  circle(385,230,1);
  circle(375,245,1);
  circle(380,255,1);
  circle(370,265,1);
  circle(300,210,1);
  circle(310,220,1);
  setcolor(2);
  outtextxy(230,208,"O");  outtextxy(240,199,"R");
  outtextxy(252,191,"D");  outtextxy(264,184,"E");
  outtextxy(279,179,"M");  outtextxy(296,174,"e");
  outtextxy(316,173,"P");  outtextxy(328,173,"R");
  outtextxy(340,174,"O");  outtextxy(352,177,"G");
  outtextxy(364,181,"R");  outtextxy(374,186,"E");
  outtextxy(383,192,"S");  outtextxy(392,197,"S");
  outtextxy(400,204,"O");
  outtextxy(1,470, "Pressione qualquer tecla para finalizar...");
  getch();   closegraph();}
