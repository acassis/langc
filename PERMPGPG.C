#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
struct aonde
{
  char tela[8];
  int pcol,plin;
} a[10];
int lin=-10,col=-10;
char h='s',v='s',guarda[4];
void pingpong(void)
{
       if(h=='s')
	  lin+=1;
       if(h==' ')
	  lin-=1;
       if(v=='s')
	  col+=1;
       if(v==' ')
	  col-=1;
	if(lin>26)
	   h=' ';
	 if(lin<0)
	   h='s';
	 if(col>76)
	    v=' ';
	 if(col<2)
	    v='s';
}
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
   int i,j;
   char tela[4];
   static unsigned int horas,minutos,segundos;
   static unsigned long contador;
   /*static char hora[]="x\32x\32:\32x\32x\32:\32x\32x\32";*/
   static char hora[]="A\2L\2A\2N\2";
   regs.h.ah=0;
   int86(26,&regs,&regs);
   pingpong();
   gettext(col,lin,col+3,lin,tela);
   puttext(col,lin,col+3,lin,hora);
   delay(25);
   puttext(col,lin,col+3,lin,tela);
   clock_tick();
}
