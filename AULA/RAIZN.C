#include <math.h>
#include <stdio.h>
void ante(double x);
void main(void)
{
 double x,y;
 puts("digite um numero");
 scanf("%lf",&x);
 puts("digite o numero da raiz");
 scanf("%lf",&y);
 printf("a raiz quadrada de %lf e %lf",x,pow(x,(1/y)));
 }
