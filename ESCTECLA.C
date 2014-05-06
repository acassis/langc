#include <dos.h>
#define INTR 0x1C

unsigned char ch;
unsigned char far *tela;
void interrupt ( *oldhandler)(void);

void interrupt handler(void)
{
   tela = (unsigned char far *)0xb8000000;
   ch = inportb(0x60);
   if(ch==75)
    {

       //*tela = 65;
       asm mov AH,0x11;
       asm mov AL,0x00;
       asm mov BH,0x00;
       asm mov BL,0x09;
       asm mov CX,0x41;
       asm mov DX,0x40;
       asm int 0x10;
    }
   oldhandler();
}

int main(void)
{
oldhandler = getvect(INTR);
setvect(INTR, handler);
keep(0, (_SS + (_SP/16) - _psp));
return 0;
}

