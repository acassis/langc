/*
		     Argumentos de linha de comando

	Podemos passar informa‡äes para programas em c.
	Fazemos isto utilizando os argumentos de linha de comando.
*/


#include <stdio.h>
#include <conio.h>
void main(int argc,char *argv[])
{
  int i;
  printf("%d argumentos \n",argc);
  for(i=0;i< argc;i++)
      printf("%s\n",argv[i]);
}

