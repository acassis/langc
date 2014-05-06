#include <stdio.h>
void main(void)
{
  unsigned int a,b;
  while(b!=0)
  {
     printf("\ndigite n£mero:");
     scanf("%x",&a);
     printf("\ndigite n§ de deslocamento a direita : ");
     scanf("%x",&b);
     printf("%x",a>>b);
    }
}


