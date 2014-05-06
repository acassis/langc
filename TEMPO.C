#include <process.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
void main(int argc,char *argv[ ])
{

  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_relogio);
  enable();
  #ifdef RESIDENTE
	 keep(0,400);
  #else
	 system("\command");
	 disable();
	 setvect(28,clock_tick);
	 enable();
   #endif
}

void interrupt minha_rotina_de_relogio(void)
{
   static unsigned int horas,minutos,segundos;
   static unsigned long contador;
   static char hora[]="x\160x\160:\160x\160x\160:\160x\160x\160";
   //static char hora[]="x\32x\32:\32x\32x\32:\32x\32x\32";
   regs.h.ah=0;
   int86(26,&regs,&regs);
   contador = regs.x.cx * 65536L + regs.x.dx;

   horas = contador / 65543L;
   contador = contador % 65543L;

   minutos = contador / 1092;
   contador = contador % 1092;

   segundos = contador / 18;

   hora[0] =horas /10 + '0';
   hora[2] =horas % 10 + '0';

   hora[6] =minutos /10 + '0';
   hora[8] =minutos % 10 + '0';

   hora[12] =segundos /10 + '0';
   hora[14] =segundos % 10 + '0';
   puttext(55,1,62,1,hora);
   clock_tick();
}