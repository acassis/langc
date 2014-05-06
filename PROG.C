#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int colmouse();
int linmouse();
int status(void);
void mouse(void);

void main (void)
{
 int lx,cx,lo,co,ct=0,lin,col,sta,confct;
 char n[5];
 clrscr();
 confct=1;
 sta=0;
 mouse();
 gotoxy(12,9);
 puts ("X");
 getch();
 while(sta==0)
	 {
	   lx=linmouse();
	   cx=colmouse();
	   sta=status();
	 }
 while(sta!=0)
     sta=status();
  if(lx==12)
    {
     if(cx==9)
	{gotoxy(20,13);
	puts("brasil tetra");
	gets(n);}
      else
	 confct=0;
     }
}

int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx/8);

  }

int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx/8);
  }
void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
int status(void)
{
     union REGS regs;
     regs.x.ax=3;
     int86(0x33,&regs,&regs);
     return(regs.x.bx);
}