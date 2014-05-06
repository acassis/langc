#include<graphics.h>
#include <grafico.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
int y=3,x=3,acel=230,cont=1;
void alan();
void diagonal();
int cor=1;
int main(void)
{
  char h='s',v='s',teste=' ';
  int drive=DETECT,modo,cor=1;
  long int ct=0;
  initgraph(&drive,&modo,"d:\\bc\\bgi");
  mouse();
  while(!kbhit()){
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
	 //x=colmouse()*8;
	 //y=linmouse()*8;
	if(x==303 && y==1){
	     x=0;y=0;
	     h='s';
	     v='s';}
	if(ct==320000){
	    cor++;
	    ct=0;
	    cont= random(16);
	    if(cor%2==0)
	     cont++;}
	 putpixel(x,y,15-cont);
	 setcolor(cor+16);
	 alan();
	 //mouse();
	 if(h==' ')
	   mousexy(y,x);
	 else
	   if(h=='s')
	     mousexy(y+2,x+2);
      }
      closegraph();
}
void alan()
{
	 if(x>100 && x<120 && y>150 && y<330 ||
	 x>100 && x<190 && y>150 && y<170 ||
	 x>170 && x<190 && y>150 && y<330 ||
	 x>100 && x<190 && y>240 && y<260 ||
	 x>220 && x<240 && y>150 && y<330 ||
	 x>220 && x<310 && y>310 && y<330 ||
	 x>340 && x<360 && y>150 && y<330 ||
	 x>340 && x<430 && y>150 && y<170 ||
	 x>410 && x<430 && y>150 && y<330 ||
	 x>340 && x<430 && y>240 && y<260 ||
	 x>460 && x<480 && y>150 && y<330 ||
	 x>530 && x<550 && y>150 && y<330 )
	 rectangle(x,y,x+1,y);
	 if(x>=465 && x<=530 )
	    diagonal();
	 desliga();

}
void diagonal()
{
  int dx,dy,x1=466,y1=166,y2=330,x2=530,i,xt,yt;
  float erro=0.0;
  dx=(x2-x1);
  dy=(y2-y1);
 for(i=0;i<=dy;i++)
  {
    if(x>=x1 && x<=x1+14 && y<=y1 && y>=y1-15){
      rectangle(x,y,x+1,y);
      break;}
    y1++;
    erro=erro+(float)dx/(float)dy;
    if(erro>0.5)
    {
      erro=erro-1.0;
      x1++;
     }
   }

}