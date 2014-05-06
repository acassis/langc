#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<dos.h>
void main(int argc,char *argv[])
{
   FILE *s,*f;
   long ct=0;
   int ch;
  if(argc < 3)
  {
    printf("\nConverte um arquivo qualquer(<64Kb) em um arquivo hexadecimal!");
    printf("\nHEXA  [Arquivo a ser convertivo]  [Arquivo hexadecimal a ser criado]");
    return;
  }
  clrscr();
  if ((s=fopen(argv[1],"rb"))==NULL)
    {
      printf("\nArquivo nao pode ser aberto.");
      return;
    }
  if ((f=fopen(argv[2],"wt"))==NULL)
    {
      printf("\nArquivo nao pode ser criado.");
      return;
    }
  fprintf(f,"matriz[64000]={");

  while((ch=fgetc(s))!=EOF)
    {
      if(ct>0x535)
       {
	fprintf(f,"% 3d,",ch);
	if(((ct-535)%320)==0)
	  fprintf(f,"\n",ch);
       }
      ct++;
    }
    puts("\nArquivo criado com sucesso!");
    getch();
    clrscr();
    exit(1);
}