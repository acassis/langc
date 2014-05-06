#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <grafico.h>
#include "c:\bc\bin\let.h"
void main(void)
{
   int drive=DETECT,modo,col=320,sta,colo=320,ta=20,ct=0,cor=1,liant,coant;
   float lino=0,lini=0,lin=240;
   char pt[13];
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   mousexy(450,col);
   bar(0,0,194,480);
   bar(448,0,640,480);
   mudamouse(_DS,(unsigned) aviao.imag,7,7);
   while(!kbhit())
   {
	 lini+=0.5;
	 if(lini>480){
	   lini=0;
	   cor++;}
	 if(cor>15)
	    cor=1;
	 if(col>199 && col<441)
	  {
		  if(lin<0)
		   lin=440;
		  if(lin==lino+12 && col>colo-ta && col<colo+ta){
		    setcolor(0);
		    setfillstyle(0,1);
		    bar(colo-ta-3,lino-ta-3,colo+ta+3,lino+ta+3);
		    lino=0;}
		  sta=status();
		  if(sta==1 )
		    {
		       lin-=1;
		       setfillstyle(1,0);
		       bar(coant-1,liant-1,coant+1,liant+1);
		       setfillstyle(1,15);
		       bar(col-1,lin-1,col+1,lin+1);
		       setcolor(0);
		       rectangle(col-2,lin-2,col+2,lin+2);
		    }
		   else{
		       setfillstyle(1,0);
		       bar(col-1,lin-1,col+1,lin+1);
		       lin=440;}
		   liant=lin;coant=col;
		   if(col>colo-ta && col<colo+ta && sta==1)
			 ct++;
		   if((!(col>colo-ta && col<colo+ta)) || sta!=1)
		    {

		     lino+=1;
		     if(lino>425 && lino<487 && col>colo-ta-5 && col<colo+ta+5)
			desliga();
		     setcolor(2);
		     circle(colo,lino,ta);
		     setcolor(0);
		     circle(colo,lino,ta-1);
		     circle(colo,lino,ta+1);
		     mouse();
		    }
		  setcolor(cor);
		  line(0,lini,194,lini);
		  setcolor(16-cor);
		  line(448,lini,640,lini);
		  if(lino==0){
		   setcolor(0);
		   outtextxy(220,460,pt);
		   sprintf(pt,"PTS:%d",ct);
		   setcolor(1);
		   outtextxy(220,460,pt);}
		   if(lino>500)
		     lino=0;
		   mouse();
		   col=colmouse()*8;
	  }
	  else
	   {
	      if(col>=440)
	       col=440;
	      if(col<=200)
	       col=200;
	  }
	  mousexy(450,col);
   }
   closegraph();
}