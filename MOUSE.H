#include <dos.h>
main()
{
 /*set_modo(6);*/
 { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
}
