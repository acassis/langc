#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include<dos.h>
void main(int argc,char *argv[])
{
   int i;
   clrscr();
   printf("Numero de argumentos: %d\n",argc);
   for(i=1;i<argc;i++)
	printf("%s\n",strcat(argv[i]));
   getch();
}


