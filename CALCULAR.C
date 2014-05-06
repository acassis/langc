#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include<dos.h>
void main (int argc,char *argv[])
{
   int num1,num2,oper;
   if(argc!=4)
      return;
    num1=atoi (argv[1]);
    oper=*argv[2];
    num2=atoi (argv[3]);
    if(oper=='+')
      printf("%d + %d = %d ",num1,num2,num1+num2);
    if(oper=='-')
      printf("%d - %d = %d ",num1,num2,num1-num2);
    if(oper=='*')
      printf("%d * %d = %d ",num1,num2,num1*num2);
    if(oper=='/')
      printf("%d + %d = %d ",num1,num2,num1/num2);
    getch();
    return;
}