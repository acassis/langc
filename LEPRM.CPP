#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
void interrupt minha_rotina_de_teclado(void);
void interrupt (*clock_tick) (void);
union REGS regs;
char ca='a',ch;
int lin,col;
static char hora[]="A\2";
//FILE *s,*p;
void main()
{
  //s=fopen("Guarda.esp","r+");
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
  gettext(col-1,lin,col-1,lin,hora);
  streambuf* sbumpc();
  //fprintf(s,"%c",ch);
  printf("%c",ch);
  puttext(col-1,lin-1,col-1,lin-1,hora);
  //fclose(s);
  //s=p;
  //freopen("Guarda.esp","r+",s);
  clock_tick();
}
