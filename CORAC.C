#include <graphics.h>
#include "grafico.h"
#include "let.h"
#include "d:\proga\c\love2.h"
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
int main(void)
{
   int gdriver = DETECT, gmode, errorcode,lin=160,col=320,r=70,li, co,sta,C,L,comsg;
   char msg[]="    Eu te curto           !!!",dm[]="D+",ma[]="Rocilene!!!!!...",m[1];
   int n[16],i,j,l=1;
   n[0]=50;n[1]=100;n[2]=142;n[3]=182;n[4]=207;n[5]=232;n[6]=272;n[7]=324;
   n[8]=364;n[9]=381;n[10]=398;n[11]=415;n[12]=432;n[13]=449;n[14]=471;n[15]=493;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      exit(1);
   }
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
   for(i=0;ma[i]!='\0';i++){
     for(j=480;j>=60;j--){
       m[0]=ma[i];
       m[1]='\0';
       setcolor(l);
       outtextxy(n[i]+30,j,m);
       delay(2);
       setcolor(0);
       outtextxy(n[i]+30,j,m);}
       setcolor(l);
       outtextxy(n[i]+30,j,m);l++;
       if(l==16)
	  l=1;}
   mouse();
   for(i=480;i>=240;i--){
     mousexy(i,320);
     delay(10);}
   botao(300,200,330,230,0);
   li=(linmouse()*8);
   co=(colmouse()*8);
   sta=status();
   while(!(co>=300 && co<=330 && li>=200 && li<=230) && sta!=1){
	   sta=status();}
   C=0;
   L=0;
	while(sta==1)
      {
       if(C==0 && L==0){
	desliga();
	botao(300,200,330,230,1);
	mouse();}
       C=1;
       sta=status();
       li=(linmouse()*8);
       co=(colmouse()*8);
       if(!(co>=300 && co<=330 && li>=200 && li<=230)){
	  if(C==1 && L==0){
	     desliga();
	     botao(300,200,330,230,0);
	     mouse();
	     sta=1;L=1;}}
       else
	    if(C==1 && L==1){
	       L=0;C=0;}
      }
  desliga();
  cleardevice();
  bar(0,0,640,480);
  setcolor(4);
  line(0,55,640,55);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  outtextxy(270,28, msg);
  sta=0;
  i=12;
  comsg=380;
  while(sta<6)
  {
   sta++;
   for(r=0;r<=90;r++)
       {
	setcolor(i);
	setfillstyle( SOLID_FILL,12);
	cardio(col,lin,r);
	delay(4);
	if(kbhit())
	   return 0;
       }
    for(;r>=0;r--)
       {
	setcolor(4);
	cardio(col,lin,r);
	floodfill(478,635, 4);
	delay(4);
	setcolor(15);
	cardio(col,lin,r);
	if(kbhit())
	   return 0;
       }
       if(i==12)
	 {
	  i=15;
	  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	  settextjustify(CENTER_TEXT, CENTER_TEXT);
	  setcolor(4);
	  outtextxy(comsg,28, dm);
	  comsg+=92;
	 }

       else i=12;
  }
   flushall();
   for(i=0;i<240;i++)
     {
      setcolor(0);
      setfillstyle( SOLID_FILL,0);
      bar(0,i,640,i);
      bar(0,480-i,640,480-i);
      delay(2);
     }
   for(i=0;i<320;i++)
     {
      setfillstyle( SOLID_FILL,0);
      bar(i,240,i,240);
      bar(640-i,240,640-i,240);
      delay(1);
     }
   cleardevice();
   delay(200);
   closegraph();
   return 0;
}
