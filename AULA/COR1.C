#include <conio.h>

int main(void)
{
   int i;

   clrscr();
   for (i=0; i<9; i++)
   {
      /* textattr(i + ((i+1) << 4));*/
       textattr(0+((14+1)<<4));
       cprintf("This is a test\r\n");
   }

   return 0;
}

