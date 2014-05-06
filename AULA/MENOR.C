#include <stdio.h>
#include <conio.h>
/* programa que recebe dois inteiros retorna o menor*/
int menor(int x,int y)
{
  return(x<y)?x:y;
  }
main()
{
  int a,b;
  clrscr();
  printf("\ndigite dois numeros");
  scanf("%d%d",&a,&b);
  printf("%d",menor(a,b));
  getch();
}
