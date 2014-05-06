#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
char tela[80][25];
void main(int argc,char *argv[ ])
{
  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_relogio);
  enable();
  #ifdef RESIDENTE
	 keep(0,400);
   gettext(0,0,79,24,tela);
   system("cls");
   #else
	 system("\command");
	 disable();
	 setvect(28,clock_tick);
	 enable();
   #endif
}
void interrupt minha_rotina_de_relogio(void)
{
   if(getch())
     puttext(0,0,79,24,tela);
   clock_tick();
}