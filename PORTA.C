#include <stdio.h>
#include <dos.h>

int main(void)
{
   clrscr();
   outportb(0x70, 64);
   outportb(0x71, 64);
   return 0;
}
