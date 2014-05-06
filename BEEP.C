#include<dos.h>
void main()
{
  int i=0;
  while(!kbhit())
  {
   if(i<300)
   {
     outportb(0x61,7);
     delay(3);
     outportb(0x61,0);
   }
   if(i>300 && i<1000)
   {
     outportb(0x61,0);
     delay(2);
   }
   if(i>999)
     i=0;
   i++;
  }
}