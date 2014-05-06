//----------------------------------------------------------------------------
//Programa: Calc.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Simples calculadora
//-----------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
soma (int x, int y)
{
 return x+y;
}
sub (int x, int y)
{
 return x-y;
}
float div (int x, int y)
{
 return x/y;
}
mult (int x, int y)
{
 return x*y;
}
pot (int b, int e)
{
 int i=1, z=b;
 for(i=1;i<e;i++)
     b=(b*z);
     return b;
}
double raiz (double b, double i)
{
 return pow(b,1/i);
}

int fat (int x)
{
   int i=0,f=1;
   for(i=x;i>=1;i--)
	     f=(f*i);
       return f;
}


void main (void)
{
 int n1,n2;
 double n,m;
 char op;
 while(op!=27)
 {
 clrscr();
 puts(" Soma\n sUbtra‡ao\n Divisao \n Multiplica‡ao\n Potencia\n Raiz\n Fatorial\n saIr");
 op=getche();
 switch(op)
{
 case 'S':
    puts("\nEntre com o 1§ numero");
    scanf ("%d",&n1);
    puts("\nEntre com o 2§ numero");
    scanf ("%d",&n2);
    printf("%d+%d=%d",n1,n2,soma(n1,n2));
    break;
 case 'U':
    puts("\nEntre com o 1§ numero");
    scanf ("%d",&n1);
    puts("\nEntre com o 2§ numero");
    scanf ("%d",&n2);
    printf("%d-%d=%d",n1,n2,sub(n1,n2));
    break;
  case 'D':
    puts("\nEntre com Dividendo");
    scanf ("%d",&n1);
    puts("\nEntre com o Divisor");
    scanf ("%d",&n2);
    printf("%d/%d=%d",n1,n2,div(n1,n2));
    break;
  case 'M':
    puts("\nEntre com o Multiplicando");
    scanf ("%d",&n1);
    puts("\nEntre com o Multiplicador");
    scanf ("%d",&n2);
    printf("%d*%d=%d",n1,n2,mult(n1,n2));
    break;
  case 'P':
    puts("\nEntre com a base");
    scanf ("%d",&n1);
    puts("\nEntre com o expoente");
    scanf ("%d",&n2);
    if(n1<0)
       {
	puts("\nNao exite potencia de base negativa");
	break;
       }
    printf("%d Elevado %d = %d",n1,n2,pot(n1,n2));
    break;
  case 'F':
    puts("\nEntre com o numero");
    scanf ("%d",&n1);
    printf("o fatorial de %d= %d",n1,fat(n1));
    break;
  case 'R':
    puts("\nEntre com a base");
    scanf ("%lf",&n);
    puts("\nEntre com o indice");
    scanf ("%lf",&m);
    printf("a %.0lf¦ raiz de %.2lf = %.2lf",m,n,raiz(n,m));
    break;
  case 'I':
    return;
}
op=getch();
}
}