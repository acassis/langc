#include <stdio.h>
#include <conio.h>
/* programa que imprime numero fabinacci*/

int fabinacci(int x)
{ int x1,x2,xn;
  x1=1;
  x2=1;
  xn=x1+x2;
  printf("%d %d %d",x1,x2,xn);
  do
  {
    x1=x2;
    x2=xn;
    xn=x1+x2;
    printf(" %d",xn);
  }while(xn <= x);
};
main()
{
  int a;
  printf("\nentre com um numero");
  scanf("%d",&a);
  fabinacci(a);
  getch();

}