#include<dos.h>
#define imprponto 0x0c
void imprpt(int linha,int coluna,unsigned char cor)
{
  union REGS regs;
  regs.h.ah=imprponto;
  regs.x.dx=linha;
  regs.x.cx=coluna;
  regs.h.al=cor;
  regs.h.bh=0;
  int86(0x10,&regs,&regs);
}
#define maxlin 480
#define maxcol 640
#define setmodo 0x00
void set_modo(void)
{
  union REGS regs;
  regs.h.ah=setmodo;
  regs.h.al=18;
  int86(0x10,& regs,& regs);
}

void main (void)
{
 int linha,coluna;
 char cor;
 set_modo();
 while (!kbhit())
  {
   linha=rand() % maxlin;
   coluna=rand() % maxcol;
   cor=(char) ((linha*coluna));
   imprpt(linha,coluna,cor);
  }
}