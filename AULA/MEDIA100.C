#include <stdio.h>
#include <conio.h>
/* programa que recebe um numero imprima se e par ou impar*/
float media(void)
{  int i,a,b=0;
   for(i=0;i<=100;i++)
      if(i%2==1)
	{
	  a+=i;
	  b++;
	 }
   return(a/b);
}
main()
{
  clrscr();
  printf("a media dos numeros impares de 0 a 100 e %f",media());
  getch();
}
