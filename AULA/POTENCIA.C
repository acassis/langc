#include <math.h>
#include <stdio.h>
void ante(double x);
void main(void)
{
 double x,y;
 puts("digite um numero");
 scanf("%lf",&x);
 puts("digite a potencia");
 scanf("%lf",&y);
 printf("%lf elevado a %lf e %lf",x,y,pow(x,y));
 puts("digite um numero");
 scanf("%lf",&x);
 ante(x);
 }
/*Elabore um programa que receba um numero e calcule a potencia com os seus
antecessores*/
void ante(double x)
{ double l=x-1;
  for(;l>=0;l--)
     printf("\n%lf",pow(x,l));
}