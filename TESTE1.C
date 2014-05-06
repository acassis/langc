#include <stdio.h>
#include <conio.h>
void main(void)
{
 float n1,n2;
 char oper,ch='s';
 while(ch=='s'|| ch=='S')
{
 clrscr();
 puts("entre com 1§ n§, operando e o 2§ n§");
 scanf("%f %c %f",&n1,&oper,&n2);
 if(oper=='+')
 printf("%.2f + %.2f = %.2f",n1,n2,n1+n2);
 if(oper=='-')
 printf("%.2f - %.2f = %.2f",n1,n2,n1-n2);
 if(oper=='*')
 printf("%.2f * %.2f = %.2f",n1,n2,n1*n2);
 if(oper=='/')
  {
    if(n2==0)
      puts("erro. divisao por zero");
    else
    printf("%.2f / %.2f = %.2f",n1,n2,n1/n2);
  }
  puts("continuar? (S/N)");
  ch=getch();
}}


