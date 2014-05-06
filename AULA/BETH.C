#include <graphics.h>
#include "grafico.h"
#include "love.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main(void)
{
   int gdriver = DETECT, gmode, errorcode,lin=160,col=320,r=70,li, co,sta,C,L;
   char msg[]="      Eu te amo!!!!!!! ",ma[]="debora!!!!...",m[1];
   int n[16],i,j,l=1;
   n[0]=55;n[1]=115;n[2]=157;n[3]=201;n[4]=240;n[5]=265;n[6]=307;n[7]=335;
   n[8]=383;n[9]=424;n[10]=446;n[11]=468;n[12]=490;n[13]=512;n[14]=534;n[15]=556;
   initgraph(&gdriver,&gmode,"c:\\arquiv~1\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      exit(1);
   }
   setcolor(9);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR, 8);
   for(i=0;ma[i]!='\0';i++){
     for(j=480;j>=60;j--){
       m[0]=ma[i];
       m[1]='\0';
       setcolor(l);
       outtextxy(n[i],j,m);
       delay(1);
       setcolor(0);
       outtextxy(n[i],j,m);}
       setcolor(l);
       outtextxy(n[i],j,m);l++;
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
       if(C==0 && L==0)
	botao(300,200,330,230,1);
       C=1;
       sta=status();
       li=(linmouse()*8);
       co=(colmouse()*8);
       if(!(co>=300 && co<=330 && li>=200 && li<=230)){
	  if(C==1 && L==0)
	     botao(300,200,330,230,0);
	     sta=1;L=1;}
       else
	    if(C==1 && L==1){
	       L=0;C=0;}
      }
      desliga();
      cleardevice();
      setcolor(4);
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
      settextjustify(CENTER_TEXT, CENTER_TEXT);
      outtextxy(270,28, msg);
  while(!(kbhit())){
  for(r=0;r<90;r++){
   setcolor(4);
   cardio(col,lin,r);
   delay(9);
   if(kbhit())
      break;}
  for(;r>-1;r--){
   delay(9);
   setcolor(0);
   cardio(col,lin,r);
   if(kbhit())
      break;}}
   getch();
   closegraph();
   return 0;
}
