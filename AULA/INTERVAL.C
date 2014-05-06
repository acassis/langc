#include <stdio.h>
#include <conio.h>
/* programa que imprime dois intervalos*/

void intervalo(int x,int y)
{ int temp;
  if(x>y)
    {
     temp=x;
     x=y;
     y=temp;
     }

  while(x<=y)
  {
     printf("\n%d",x);
     x++;
   }
};
void main(void)
{
  int c,d;
  clrscr();
  printf("entre com dois valores");
  scanf("%d%d",&c,&d);
  intervalo(c,d);
  getch();
}
