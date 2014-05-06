#include <dos.h>
#include <graphics.h>
#define ATTR 0x0200
void interrupt ( *oldhandler)(void);
char chant,tek,tekant;
int i=0,l=0,cont=0;
char mtz[80][25];
extern unsigned _heaplen = 1024;
extern unsigned _stklen  = 512;
unsigned int (far *screen)[80];
void interrupt handler(void)
{
   outportb(0x3C0,cont);
   cont++;
   oldhandler();
}

int main(void)
{
      //int drive=DETECT,modo;

      //initgraph(&drive,&modo,"c:\\bc\\bgi");

      oldhandler = getvect(28);

      setvect(28, handler);

      keep(0, (_SS + (_SP/16) - _psp));
return 0;
}
