#include <conio.h>
#include <dos.h>
#include <graphics.h>
unsigned char *mem,resp=1;
void interrupt ( *oldhandler)(void);
void interrupt handler(void)
{
   if(resp==1)
    {
     mem = MK_FP(0x000A,0x0);
     resp=0;
    }
   *mem++=255;
   oldhandler();
}

int main(void)
{
      oldhandler = getvect(28);

      setvect(28, handler);

      keep(0, (_SS + (_SP/16) - _psp));
return 0;
}
