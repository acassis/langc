/*
O  OPERADOR OR (|) BIT-A-BIT

	combinar bit.
*/

#include <stdio.h>
void main(void)
{
  unsigned int a,b,c;
  while(1)
  {  printf("\ndigite dois n£meros hexa (ff ou menor): ");
     scanf("%x",&a);
     scanf("%x",&b);
     c=a | b;
     printf("%x  %x =%x",a,b,c);
    }
}


