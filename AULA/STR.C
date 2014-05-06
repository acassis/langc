#include <conio.h>
#include <stdio.h>
int str(char *a,char *b);
void main(void)
{
 char b[30],a[30];
 puts("entre com duas strings");
 gets(a);
 gets(b);
 if(str(a,b)==0)
   puts("string iguais");
 else
   puts("string diferentes");
 getch();
}
int str(char*a,char *b)
{
  while(*a || *b)
    if(*a++==*b++);
    else
       return 1;
  return 0;
}