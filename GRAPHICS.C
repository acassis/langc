#include <dos.h>
#include <conio.h>
#include <stdio.h>
#define setmodo 0x00
void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x10,&regs,&regs);
  }
int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x10,&regs,&regs);
   return (regs.x.cx/8);

  }

int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x10,&regs,&regs);
   return (regs.x.dx/8);
  }
void set_modo(void)
{
  union REGS regs;
  regs.h.ah=setmodo;
  regs.h.al=18;
  int86(0x10,& regs,& regs);
}
void main(void)
{
  int lin,col;
  flushall();
  clrscr();
  set_modo();
  mouse();
  lin=linmouse();
  col=colmouse();
  gotoxy(1,1);
  printf("%3d   %3d",lin,col);
  getch();
}