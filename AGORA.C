#include <graphics.h>
#include <stdio.h>
#include <dos.h>

void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }

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
struct imagem rosa = { {
0xffff,0xf3cf,0xedb7,0xce73,
0xbf7d,0xbf7d,0xde7b,0xe1b7,
0xed87,0xde7b,0xbefd,0xbefd,
0xce73,0xedb7,0xf3cf,0xffff,

0x0000,0x0c30,0x1248,0x318c,
0x4082,0x4082,0x2184,0x1e48,
0x1278,0x2184,0x4102,0x4102,
0x318c,0x1248,0x0c30,0x0000},7,7};


int main(void)
{
   int gdriver = DETECT, gmode,lin=40,col=16,sta,stant,ml1[16],ml2[16],mc1[16],mc2[16];
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   mudamouse(_DS,(unsigned) rosa.imag,7,7);
   mouse();
   getch();
   closegraph();
}