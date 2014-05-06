#include <stdio.h>
#include <conio.h>
/* programa que imprime dobro de um numero*/

int quadrado(int x)
{
  return(x*2);
};
void main(void)
{
  int c;
  clrscr();
  printf("entre com um numero");
  scanf("%d",&c);
  printf("dobro do numero %d e %d",c, quadrado(c) );
  getch();
}
