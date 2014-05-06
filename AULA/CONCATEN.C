#include <conio.h>
#include <stdio.h>
/*
*****************************************************************************
copia uma string para outra
*/
void strcopy(char *a,char *b)
{
   while(*a)
     *b++=*a++;

  *b='\0';
}
/*
*****************************************************************************
concatenda duas strings
*/
void strconcatena(char *a,char *b)
{
  while(*a)
      a++;
  while(*b)
       *a++=*b++;

   *a='\0';
}
/*
*****************************************************************************
*/

void main(void)
{
 char c[30],d[30];
 puts("\nentre com string");
 gets(c);
 gets(d);
 strconcatena(c,d);
 printf("%s",c);
 getch();
}
