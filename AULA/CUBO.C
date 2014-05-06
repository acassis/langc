#include <stdio.h>
#include <conio.h>
/* programa que calcula o volume de um cubo */

float cubo(float a,float b, float c)
{
  return(a*b*c);
};
main()
{
  float a,b,c;
  printf("\nentre com trˆs numeros");
  scanf("%f%f%f",&a,&b,&c);
  printf("o volume do cubo ‚ %f",cubo(a,b,c));
  getch();

}