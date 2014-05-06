#include<stdio.h>
#include<conio.h>
main()
{
 int l,cont=0;
 window(0,0,79,24);
 for(l=0;l<=255;l++)
  {
   printf("\n CHAR= %1c_____DEC= %4d_____OCT= %4o_____HEX= %4x",l,l,l,l);
   cont++;
   if(cont>=21)
   {
     printf("\n         TECLE ALGO PARA CONTINUAR...");
     getch();
     clrscr();
     cont=0;
     window(0,0,79,24);
    }
   }
}