#include <stdlib.h>
void main()
{
   unsigned char ch=0;
   int far *key = (int far *)0x00400017;
   int mt[8]={0x00,0x10,0x40,0x50,0x20,0x30,0x60,0x70};
   clrscr();
   while(!kbhit())
   {
      ch++;
      if(ch>7)
	 ch=0;
      *key = mt[ch];
      delay(250);
   }
}