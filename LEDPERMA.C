#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
unsigned char ch=0;
int far *key = (int far *)0x00400017;
int mt[8]={0x00,0x10,0x40,0x50,0x20,0x30,0x60,0x70},cont=0;
//---------------------------------------------------------------------------
void main(int argc,char *argv[ ])
{
  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_relogio);
  enable();

  #ifdef RESIDENTE
	 keep(0,(_SS + (_SP/16) - _psp));
  #else
	system("\command");
	disable();
	setvect(28,clock_tick);
	enable();
  #endif
}

void interrupt minha_rotina_de_relogio(void)
{
   cont++;
   if((cont%5)==0)
   {
      ch++;
      if(ch>7)
	 ch=0;

      if(ch==0)
	 *key = (*key^mt[7]);
      else
	if(ch==1)
	 *key = (*key|mt[1]);
	else
	 if(ch>1)
	 {
	   *key = (*key^mt[ch-1]);
	   *key = (*key|mt[ch]);
	 }
   }
}