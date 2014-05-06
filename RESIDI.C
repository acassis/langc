#include <dos.h>
#include <stdio.h>
#include <graphics.h>
void interrupt ( *oldhandler)(void);
int i=0;
void interrupt handler(void)
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
