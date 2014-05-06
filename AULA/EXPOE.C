#include <stdio.h>
#include <conio.h>

int  expo(int base, int exp);
void main(void)
{
  int bas,exp;
  clrscr();
  puts("entre com a base e expoente");
  scanf("%d %d",&bas, &exp);
  printf("%d",expo(bas,exp));
  getch();
}

int expo(int base,int expo)
{
  int i,a=1;
  for(i=1;i<=expo;i++)
      a=a*base;

  return(a);
}