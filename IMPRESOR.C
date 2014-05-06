#include <conio.h>
#include <dos.h>

#define IDO 0x17

void movetoxy(int x)
{
   union REGS regs;
   regs.h.ah = 0;  /* set cursor postion */
   regs.h.al = x;
   regs.x.dx = 0;
   int86(IDO, &regs, &regs);
}
/*80 colunas por 70 linhas*/
int main(void)
{
   int ct=0;
   clrscr();
   while(ct<5600){
   movetoxy(65);
   movetoxy(76);
   movetoxy(65);
   movetoxy(78);
   movetoxy(32);
   delay(1);
   ct++;
   }

   return 0;
}
