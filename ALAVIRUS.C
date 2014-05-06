#include<dir.h>
#include<stdio.h>
void main(int argc,char *argv[])
{
   FILE *f;
   long tam=0;
   if ((f=fopen(argv[0],"r+"))==NULL)
       {
	  printf("Arquivo nao pode ser aberto!");
	  exit(1);
       }
  fseek(f, 0, SEEK_END);
  tam=ftell(f);
  fprintf(f,"0");
  printf("Esta e' a %d¦ vez que voce executa este programa.",tam-12002);
  fclose(f);
  exit(1);
}
