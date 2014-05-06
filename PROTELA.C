#include <dos.h>
#define ATTR 0x0200
void interrupt ( *oldhandler)(void);
char chant,ch;
int u=0,d=0,c=0,m=0,ct=1572;
unsigned int (far *screen)[80];
void interrupt handler(void)
{
   ch=inportb(0x60);
   outport(0x3c0,ct);
   screen = MK_FP(0xB800,0);
   screen[0][76] = m + '0' + ATTR;
   screen[0][77] = c + '0' + ATTR;
   screen[0][78] = d + '0' + ATTR;
   screen[0][79] = u + '0' + ATTR;
   //if(ch!=chant){
   //ct++;
   //u++;  }
   if(u>9){
      u=0;
      d++;}
   if(d>9){
      d=0;
      c++;}
   if(c>9){
      c=0;
      m++;}
   if(m>9){
      m=0;
      ct=0;}
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
