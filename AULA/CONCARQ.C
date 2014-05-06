/*
***************************************************************************
concatena dois arquivos
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main(int argc,char *argv[])
{ int ch;
  FILE *ent,*said;
  if(argc==3)
  {
   if((ent=fopen(argv[1],"r"))==NULL)
    { puts("arquivo nao pode ser aberto");
     exit(1);}
   if( (said=fopen(argv[2],"a"))==NULL)
   {
      puts("arquivo nao pode ser aberto");
      exit(1);}
  while((ch=getc(ent))!=EOF)
       putc(ch,said);
  fcloseall();
  }
}