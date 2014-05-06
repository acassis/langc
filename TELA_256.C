#include <stdlib.h>
#include<math.h>
void main()
{
  long cont=0;
  int ct = 2,cnt=1;
  unsigned char far *tela;
  tela =  (unsigned char far *)0xA0000000;
  asm mov ax,0x4f02
  asm mov bx,0x101
  asm int 10h
  while(!kbhit())
  {
     *(tela + cont) = 1;
     cont++;
//     delay(1);
  }
  asm mov ax,03
  asm int 10h
}