#include <graphics.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
   FILE *stream;
   char string[] = "This is a test";
   char ch ,num[4];
   int i;
   unsigned str[32];
   stream = fopen("let.c", "r+");
   fseek(stream, 0, SEEK_SET);
   do
   {
      ch = fgetc(stream);
      if(ch==','


   } while (ch != EOF);

   void mudamouse(unsigned segimag,unsigned offimag,unsigned lin,unsigned col)
   {
     union REGS regs;
     struct SREGS sregs;
     regs.x.ax=0x09;
     regs.x.bx=7;
     regs.x.cx=7;
     sregs.es=_DS;
     regs.x.dx=offimag;
     int86x(0x33,&regs,&regs,&sregs);
   }
   fclose(stream);
   return 0;
}
