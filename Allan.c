#include<conio.h>
#include "grafico.h"
#include <graphics.h>
#include<stdio.h>
#include<dos.h>
void let_a();
void let_l();
void let_n();
void imp();
int L,C,lin=0,col=0,cont=0;
void main (void)
{  int li, co,sta,drive=DETECT,modo;
   clrscr();
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   retangulo(280,180,350,250,15);
   botao(300,200,330,230,0);
   mouse();
   li=(linmouse());
   co=(colmouse());
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
       li=(linmouse());
       co=(colmouse());
       if(!(co>=300 && co<=330 && li>=200 && li<=230)){
	  if(C==1 && L==0){
	     desliga();
	     botao(300,200,330,230,0);
	     mouse();}
	     sta=1;L=1;}
       else
	    if(C==1 && L==1){
	       L=0;C=0;}
    }
   set_modo();
   while(!(kbhit()))
       {
       _setcursortype(0);
	 col++;
	 lin++;
	 cont++;
	 if(lin>25)
	   lin=1;
	 if(col>79)
	    col=1;
	 C=-25;L=-2;
	 setcolor(2);
	 let_a();
	 C=6,L=8;
	 let_l();
	 C=9;L=-2;
	 let_a();
	 C=15;L=-2;
	 let_n();
	 if(cont<500){
	    gotoxy(col,lin);
	    printf(" ");
	    delay(.9);}
	 }

}
void let_a(void)
{
   if( col==34+C && lin>13+L && lin<=21+L || col==42+C && lin>13+L && lin<=21+L || col>=34+C && col<=42+C && lin==13+L || col>=34+C && col<=42+C && lin==17+L)
     imp();
}
void let_l(void)
{
  if(lin>=3+L && lin<=11+L &&  col==20+C || col>=20+C && col<=28+C && lin==11+L)
  imp();
}
void let_n()
{
   if(col==46+C && lin>=13+L && lin<=21+L || col==54+C && lin>=13+L && lin<=21+L ||  lin>=14+L &&  lin<=20+L &&   col==lin+37+C+L)
   imp();
}
void imp()
{
    gotoxy(col,lin);
    asm mov ah,9
    asm mov al,219
    asm mov bl,1
    asm mov cx,3
    asm int 10h
}

