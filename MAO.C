#define esc 0x01b
#include<dos.h>
#include<graphics.h>
#include<grafico.h>
/*void mudamouse(unsigned segimag,unsigned offimag,unsigned lin,unsigned col)
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
struct imagem{
  unsigned imag[32];
  int lin,col;
  };
struct imagem mao=
{
  {
  0xf3ff,0xedff,0xedff,0xedff,
  0xedff,0xec49,0xedb6,0x8db6,
  0x6db6,0x6ffe,0x6ffe,0x7ffe,
  0x7ffe,0x7ffe,0x7ffe,0x8001,

  0x0c00,0x1200,0x1200,0x1200,
  0x1200,0x13b6,0x1249,0x7249,
  0x9249,0x9001,0x9001,0x8001,
  0x8001,0x8001,0x8001,0x7ffe
  },0,4
};*/
void main (void)
{
  int x,gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      exit(1);
   }
   mudamouse(_DS,(unsigned) mao2.imag,mao2.lin,mao2.col);
   mouse();
   while(getch()!=esc);

}

