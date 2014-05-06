#include <conio.h>
#include <stdio.h>
#include <dos.h>
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
void main (void)
{
  set_modo();
}