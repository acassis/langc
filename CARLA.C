#include <graphics.h>
#include "grafico.h"
#include "c:\bc\bin\let.h"
#include "c:\bc\ling_c\love2.h"
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
int x=1,y=1;
void diagonal(int log)
{
  int dx,dy,x1=466,y1=166,y2=330,x2=530,i,xt,yt;
  float erro=0.0;
  dx=(x2-x1);
  dy=(y2-y1);
 for(i=0;i<=dy;i++)
  {
    if(log==0)
     if(x>=x1 && x<=x1+14 && y<=y1 && y>=y1-15){
      rectangle(x,y,x+1,y);
      break;}
    if(log==1)
     if(x>=x1 && x<=x1+14 && y<=y1 && y>=y1-15){
      rectangle(x,y,x+1,y);}
    y1++;
    erro=erro+(float)dx/(float)dy;
    if(erro>0.5)
    {
      erro=erro-1.0;
      x1++;
     }
   }

}


int main(void)
{
   int gdriver = DETECT, gmode, errorcode,lin=160,col=320,r=70,li, co,sta,C,L,comsg;
   char msg[]="    Eu te curto           !!!",dm[]="D+",ma[]="CARLA!!!!!!!....",m[1],resp='s';
   char h='s',v='s',teste=' ';
   int n[16],i,j,l=1;
   float ct=150,cont;
   n[0]=50;n[1]=100;n[2]=150;n[3]=200;n[4]=250;n[5]=313;n[6]=330;n[7]=347;
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
       for(cont=0;cont<100;cont=cont+0.01);
       setcolor(0);
       outtextxy(n[i]+30,j,m);}
       setcolor(l);
       outtextxy(n[i]+30,j,m);l++;
       if(l==16)
	  l=1;}
   for(i=480;i>=240;i--){
     mouse();
     mousexy(i,320);
     for(cont=0;cont<500;cont=cont+0.01);}
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
	setfillstyle( SOLID_FILL, i );
	cardio(col,lin,r);
	for(cont=0;cont<200;
	    cont=cont+0.05);
       }
       if(i==12)
	 {
	  i=15;
	  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	  settextjustify(CENTER_TEXT, CENTER_TEXT);
	  setcolor(4);
	  outtextxy(comsg,28, dm);
	  delay(1000);
	  comsg+=92;
	 }

       else i=12;
  }
  bar(0,0,640,480);
  while(1)
  {
     ct=ct-0.1;
    if(i==0)
      i=1;
    if(resp=='s'){
     setcolor(1);
     circle(ct+440,(ct*ct)/128+(2*ct)+240,5);
     setcolor(4);
     circle(640-(ct+440),480-((ct*ct)/128+(2*ct)+255),5);

     setcolor(2);
     circle((ct*ct)/128+(2*ct)+320,480-(ct+380),5);
     setcolor(14);
     circle(450-((ct*ct)/128+(2*ct)+140),ct+360,5);}
    if(resp=='n'){
     setcolor(15);
     circle(ct+440,(ct*ct)/128+(2*ct)+240,5);
     setcolor(15);
     circle(640-(ct+440),480-((ct*ct)/128+(2*ct)+255),5);

     setcolor(15);
     circle((ct*ct)/128+(2*ct)+320,480-(ct+380),5);
     setcolor(15);
     circle(450-((ct*ct)/128+(2*ct)+140),ct+360,5);
    }
     if(ct<-240 && resp=='s'){
	setcolor(4);
	setfillstyle( SOLID_FILL,4);
	cardio(320,220,20);
	setcolor(7);
	settextstyle(1, HORIZ_DIR,1);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(324,234,"A & C");
	setcolor(0);
	settextstyle(1, HORIZ_DIR,1);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(320,230,"A & C");
	delay(1000);
	ct=150;
	resp='n';}
     if(ct<-240){
       delay(1000);
       break;}
  }
  while(x!=303 || y!=1)
  {
       ct++;
       if(h=='s')
	  y++;
       if(h==' ')
	  y--;
       if(v=='s')
	  x++;
       if(v==' ')
	  x--;
	if(y>471)
	   h=' ';
	 if(y<2)
	   h='s';
	 if(x>640)
	    v=' ';
	 if(x<2)
	    v='s';
	 setcolor(15);
	 rectangle(x,y,x+1,y);
	 setcolor(1);
	if(x>100 && x<120 && y>150 && y<330 ||
	 x>100 && x<190 && y>150 && y<170 ||
	 x>100 && x<170 && y>230 && y<250 ||
	 x>310 && x<330 && y>150 && y<330 ||
	 x>460 && x<480 && y>150 && y<330 ||
	 x>530 && x<550 && y>150 && y<330 )
	 rectangle(x,y,x+1,y);
	 if(x>=480 && x<=505 && y>=x-328 && y<=x-308)
	   rectangle(x,y,x+1,y);
	 if(x>505 && x<=530 && y>=682-x && y<=702-x)
	   rectangle(x,y,x+1,y);
	 desliga();


      }
  delay(1000);
  for(i=0;i<240;i++)
     {
      setcolor(0);
      setfillstyle( SOLID_FILL,0);
      bar(0,i,640,i);
      bar(0,480-i,640,480-i);
      for(cont=0;cont<100;cont=cont+0.005);
     }
   for(i=0;i<320;i++)
     {
      setfillstyle( SOLID_FILL,0);
      bar(i,240,i,240);
      bar(640-i,240,640-i,240);
      for(cont=0;cont<100;cont=cont+0.05);
     }
   cleardevice();
   delay(200);
   closegraph();
   return 0;
}
