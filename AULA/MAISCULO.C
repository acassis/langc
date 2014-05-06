#include <conio.h>
#include <stdio.h>
void maisculo(char *a);
void main(void)
{
 char b[30];
 clrscr();
 puts("entre com string");
 gets(b);
 maisculo(b);
 printf("%s",b);
 getch();
}
void maisculo(char *a)
{
  while(*a)
   if( (*a>='a') && (*a<='z'))
    {
     *a-= 32;
     *a++;
     }
   else
      *a=*a++;

}