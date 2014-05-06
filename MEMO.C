#include <dos.h>
void main()
{
   long char *mem,*temp;
   int  offset=0x0005;
   long seg=0xFFFF;
   char ch;
   clrscr();
   mem = MK_FP(seg,offset);
   temp=mem;
   while(!kbhit())
   {
     if((mem-temp)>=32786)
      {
	 seg++;
	 offset=0x0000;
	 mem = MK_FP(seg,offset);
	 temp=mem;
      }
     printf("%c",*mem++);
     delay(5);
   }
}
