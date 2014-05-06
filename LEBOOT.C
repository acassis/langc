#include <dos.h>
#define DISK  0x13
#include "boot_def.h"
void ajusta_disk(char drv,char cod)
{
   union REGS regs;
   regs.h.ah=0x17;
   regs.h.al=cod;
   regs.h.dl=drv;
   int86(DISK,&regs,&regs);
}
le_setor (unsigned char nsetor,unsigned char trilha,int setor,int face,int drv,int seg,int desloc)
{
    union REGS regs;
    struct SREGS sregs;
    regs.h.ah=0x02;
    regs.h.al=nsetor;
    sregs.es=seg;
    regs.h.ch=trilha;
    regs.h.cl=setor;
    regs.h.dh=face;
    regs.h.dl=drv;
    regs.x.bx=desloc;
    int86x(DISK,&regs,&regs,&sregs);
    return(regs.x.cflag ? regs.h.ah:0);
}
int init_error(char drv)
{
  union REGS regs;
  regs.h.ah=0;
  regs.h.dl=drv;
  int86(DISK,&regs,&regs);
  return(regs.x.cflag ? regs.h.ah: 0);
}
struct boot buff_boot;
void main()
{
   int k;
   unsigned char far *p;
   struct SREGS sregs;
   segread(&sregs);
   sregs.es=sregs.ds;
   if(init_error(1));
      printf("\nErro na controladora");
   ajusta_disk(0,6);
   for(k=0;k<3;k++)
     if(le_setor(1,sregs.es,atoi(&buff_boot),0,1,0,0))
       printf("\nErro na trilha");
     else break;
   clrscr();
   printf("%s",buff_boot.ID_volume);
   getch();
}



