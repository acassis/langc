#include<graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
void main(void)
{
  char h='s',v='s';
  int drive=DETECT,modo,cor,ct=0;
  int lin=1,col=1,x,y,acel=230;
  initgraph(&drive,&modo,"d:\\bc\\bgi");
  while((kbhit())){
       ct++;
       if(h=='s')
	  lin++;
       if(h==' ')
	  lin--;
       if(v=='s')
	  col++;
       if(v==' ')
	  col--;
	if(lin>471)
	   h=' ';
	 if(lin<2)
	   h='s';
	 if(col>640)
	    v=' ';
	 if(col<2)
	    v='s';
	 if(col==2 && lin==460){
	    cleardevice();
	    col=1;
	    lin=1;
	    h='s';
	    v='s';}
	 if(col%10==0)
	  cor=(char)(ct%51);
	 setcolor(cor);
	 circle(col,lin,20);
	 /*delay(2);*/
      }
}