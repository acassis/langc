/*
variaveis globais
*/
#include <stdio.h>
#include <conio.h>
void global(void);
int a,b;
void main(void)
{
  clrscr();
  a=51;b=52;
  printf("\n%d %d",a,b);
  global();
  a=8;b=10;
  printf("\n%d %d",a,b);
  getch();
 }
void global(void)
{
  a=1;b=100;
  printf("\n%d %d",a,b);
}