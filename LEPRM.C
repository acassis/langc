#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <bios.h>
void interrupt minha_rotina_de_teclado(void);
void interrupt (*clock_tick) (void);
union REGS regs;
char ca='a',ch='A';
int lin,col;
static char hora[]="A\2";
void main()
{
  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_teclado);
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
void interrupt minha_rotina_de_teclado(void)
{
  col=wherex();
  lin=wherey();
  //if(ch>=65)
  //printf("%d",ch);
  gettext(col-1,lin,col-1,lin,hora);
  //fprintf(s,"%c",ch);
  if(hora[0]>=65){
       ch = bioskey(0);
       hora[0]=ch;
       puttext(col-1,lin-1,col-1,lin-1,hora);}
  //fclose(s);
  //s=p;
  clock_tick();
}
