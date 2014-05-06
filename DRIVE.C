#include<dos.h>
void main (void)
{
   union REGS regs ;
   struct SREGS sregs;
   regs.h.ah = 0x08;
   regs.h.dl = 0;
   int86x(0x13,&regs,&regs ,&regs);
   clrscr();
   switch(regs.h.bl)
   {
      case 1:
	 printf("\ndrive de 360kb,40 trilhas ,5.25");
	 break;
      case 2:
	 printf("\drive de 1.2kb , 80 trilhas , 5.25");
	 break;
      case 3:
	 printf("\drive de 720kb ,80 trilhas ,5.25");
	 break;
      case 4:
	 printf("\drive de 1.44kb ,80 trilhas ,5.25");
	 break;
     }
     printf("\nn£mero m ximo de trilhas %d",regs.h.ch+1);
     printf("\nn£mero maximo de setores %d",regs.h.cl);
     printf("\nn£mero m ximo de faces %d",regs.h.dh+1);
     printf("\nn£mero de drives instalados %d",regs.h.dl);
     printf("\nTabela B sica de Parƒmetros do drive:");
     printf("\ %x : %x",sregs.es,regs.x.di);
     getch();
}