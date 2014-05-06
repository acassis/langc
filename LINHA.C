#include <conio.h>
#include <dos.h>
#include <graphics.h>
#define ATTR 0x0200
void interrupt ( *oldhandler)(void);
char chant,vez=0;
char a[]="A\7",n[]="N\7",l[]="L\7",t[]="T\7",sp[]=" \7",e[]="E\7",m[]="M\7",o[]="O\7",u[]="U\7",ex[]="!\7",v[]="V\7";
int x,y,xa,ya;
void interrupt handler(void)
{
  char ch;
  ch=inportb(0x60);
  if(ch!=chant && ch!=14)
   {
     char ch[2];
     x = wherex();
     y = wherey();
     if(vez==0 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,a);
	vez=1;
      }
     else if(vez==1 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,l);
	vez=2;
      }
     else if(vez==2 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,a);
	vez=3;
      }
     else if(vez==3 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,n);
	vez=4;
      }
     else if(vez==4 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,sp);
	vez=5;
      }
     else if(vez==5 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,e);
	vez=6;
      }
     else if(vez==6 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,u);
	vez=7;
      }
     else if(vez==7 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,sp);
	vez=8;
      }
     else if(vez==8 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,t);
	vez=9;
      }
     else if(vez==9 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,e);
	vez=10;
      }
     else if(vez==10 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,sp);
	vez=11;
      }
     else if(vez==11 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,a);
	vez=12;
      }
     else if(vez==12 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,m);
	vez=13;
      }
     else if(vez==13 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,o);
	vez=14;
      }
     else if(vez==14 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,ex);
	vez=15;
      }
     else if(vez==15 && xa!=x && ya==y)
      {
	puttext(x-1,y,x-1,y,sp);
	vez=0;
      }
     else if(y!=ya)
	    vez=0;
      xa=x;
      ya=y;
   }
   chant=ch;
   oldhandler();
}

void main(void)
{
      oldhandler = getvect(28);

      setvect(28, handler);

      keep(0, (_SS + (_SP/16) - _psp));
      exit(1);
}
