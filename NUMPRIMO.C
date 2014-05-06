#include <stdio.h>
#include <conio.h>
void main (void)
{
  int num,i;
  puts("\nInforme um n§:");
  scanf("%d",&num);
  if(num>=0 && num<=3)
     printf("\nNumero Primo!");
  else
     for(i=2;i<num;i++)
	if((num % i)==0)
	  {
	   printf("O n§ %d nao e primo!",num);
	   return;
	  }
  printf("O n§ %d e primo!",num);
}