#include <stdio.h>
#include <dir.h>
int main(void)
{
   char *p;

   clrscr();
   p = searchpath("win.com");
   printf("O caminho �: %s\n", p);
   getch();
   return 0;
}
