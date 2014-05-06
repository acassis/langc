#include <stdio.h>
#include <conio.h>
/* programa que recebe um numero e retorna o fatorial dele */
float fatorial1(float x)
{  float i,f;
   f=x;
   if( (x==0) || (x==1) )
      return(1);
   for(i=x-1;i>1;i--)
       f*=i;
   return(f);
}
float fatorial2(float x)
{  float i,f;
   f=x;
   if( (x==0) || (x==1) )
      return(1);
   i=x-1;
   while(i>1)
   {
       f*=i;
       i--;
   }
   return(f);
}

float fatorial3(float x)
{  float i,f;
   f=x;
   if( (x==0) || (x==1) )
      return(1);
   i=x-1;
   do
   {
       f*=i;
       i--;
   }while(i>1);
   return(f);
}


main()
{
  float a;
  clrscr();
  printf("entre com um numero");
  scanf("%f",&a);
  printf("\no fatorial de %f  e  %f",a,fatorial3(a) );
  getch();
}
