#include <stdio.h>
#include <conio.h>
#define MAI(x) ((((x)>='a')&&((x)<='z') )?(x)-'a'+'A':(x))
main()
{
  char o;
  clrscr();
  o=getche();
  printf("%c",MAI(o));
  getch();
}