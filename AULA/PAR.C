#include <stdio.h>
#include <conio.h>
/* programa que recebe um numero imprima se e par ou impar*/
void par_impar(int x)
{
  if(x%2==0)
     printf("o numero ‚ par");
  else
     printf("o numero ‚ impar");
}
main()
{
  int a;
  clrscr();
  printf("\ndigite um numero");
  scanf("%d",&a);
  par_impar(a);
  getch();
}
