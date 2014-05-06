#include <stdlib.h>
#include<math.h>
void main()
{
  int col,lin,ct = 2,cnt=1;
  unsigned char far *tela;
  tela =  (unsigned char far *)0xA0000000;
//  asm mov ax,0x4f02
//  asm mov bx,0x101
  asm mov ax,19
  asm int 10h
  while(!kbhit())
  {
     for(lin=0;lin<200;lin++)
       for(col=0;col<320;col++)
       {
	  //*(tela + 320*lin + col) = cos((col-160)/(lin+1)) * (lin+ct);

	  *(tela + 320*lin + col) = cos((col-160.12)/(lin+1)) * (lin+ct);
       }
       if(cnt==0)
	  ct ++;
       else
	  ct --;
       if(ct>2)
	  cnt = 1;
       if(ct<-500)
	  cnt = 0;
  }
  asm mov ax,03
  asm int 10h
}