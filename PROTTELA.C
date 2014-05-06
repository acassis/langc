#include <dos.h>
#include <stdlib.h>
#define ATTR 0x0200
void interrupt ( *oldhandler)(void);
char chant,ch,m[5];
int ct=500;
unsigned int (far *screen)[80];
void interrupt handler(void)
{
   ch=inportb(0x60);
   outport(0x3c0,ct);
   screen = MK_FP(0xB800,0);
   screen[0][75] = m[0]  + ATTR;
   screen[0][76] = m[1]  + ATTR;
   screen[0][77] = m[2]  + ATTR;
   screen[0][78] = m[3]  + ATTR;
   screen[0][79] = m[4]  + ATTR;
   itoa(ct,m,10);
   //if(ch!=chant && ch<100)
   //   ct++;
   oldhandler();
   chant=ch;
}

int main(void)
{

      oldhandler = getvect(28);

      setvect(28, handler);

      keep(0, (_SS + (_SP/16) - _psp));
      return 0;
}
