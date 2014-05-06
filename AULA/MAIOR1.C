#include <stdio.h>
#include <conio.h>
#define MAX(x,y) (((x)>=(y))?(x):(y))
main()
{
  int o,n;
  clrscr();
  scanf("%d%d",&o,&n);
  printf("%d",MAX(o,n));
  getch();
}