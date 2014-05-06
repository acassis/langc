/* soma atraves de argumentos */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc,char *argv[])
{
  float  a,b;
  clrscr();
  if(argc!=4)
     {puts("parametros invalidos");
     exit(1);
     }
  a=atof(argv[1]);
  b=atof(argv[3]);
  if(strcmp(argv[2],"+")!=0)
    {
    puts("argumento para calculo invalido");
    exit(1);
    }
  printf("%.2f + %.2f = %.2f",a,b,a+b);
  getch();
}

