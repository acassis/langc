#include <stdlib.h>
#include <stdio.h>

div_t x;
clrscr();
int main(void)
{
   x = div(10,3);
   printf("10 div 3 = %d e resta %d\n", x.quot, x.rem);

   return 0;
}
