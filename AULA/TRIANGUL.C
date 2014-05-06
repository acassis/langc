#include <stdio.h>
#include <conio.h>
/* triangulo*/
void triangulo(int a,int b,int c)
{
  if((a<b+c) && (b<a+c) && (c<a+b))
      ;
  else
  {
     printf("os valores imformados nao formam um triangulo");
     return;
   }
   if( (a==b) && (b==c) && (c==a) )
       printf("e um triangulo equilatero");
   else if( (a==b) || (b==c) || (c==a))
          printf("e um triangulo is¢celes");
         else
             printf("e um triangulo escaleno");
}
main()
{ int a,b,c;
   clrscr();
  printf("\n\n%dentre com tres valores");
  scanf("%d%d%d",&a,&b,&c);
  triangulo(a,b,c);
  getch();
}