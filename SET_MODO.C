#define setmodo 0x33
#include<dos.h>
void set_modo(void)
{
  union REGS regs;
  regs.h.ah=4;
  regs.h.al=1;
  int86(0x10,& regs,& regs);
}
void main (void)
{
  set_modo();
  exit();
}