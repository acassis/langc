#include<stdio.h>
#include<conio.h>
main()
 {
   int i,t=0,c=1;
   char a;
   clrscr();
   for(i=0;i<45;i++)
   {
     t+=i;
     printf("\n\t%2d_____CONTA=%2d______TOTAL=%4d",c,i,t);
     c++;
     if(c>=21)
     {
       c=1;
       printf("\n\t\t tecler algo");
       a=getch();
      }
   }
 }