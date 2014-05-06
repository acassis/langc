#include <dos.h>
#include <conio.h>
#include <stdio.h>
#define setmodo 0x00
int colmouse();
int linmouse();
int status(void);
void mouse (void);
void set_modo(void)
{
  union REGS regs;
  regs.h.ah=setmodo;
  regs.h.al=18;
  int86(0x10,& regs,& regs);
}
void main(void)
{
    int lin,col/*,sta*/;
    set_modo();
    mouse();
    while(!kbhit()){
    lin=linmouse();
    col=colmouse();
    /*sta=status();*/
    gotoxy(1,1);
    printf("%3d     %3d",lin,col);}
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