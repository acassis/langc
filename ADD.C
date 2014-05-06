#include <stdio.h>
void main(int argc,char *argv[])
{
   FILE *f,*s;
   long tam=0,ta=0;
   if ((f=fopen(argv[1],"r+b"))==NULL)
       {
	  f=fopen(argv[1],"wb");
       }
       fseek(f, 0, SEEK_END);
   if ((s=fopen(argv[2],"rb"))==NULL)
       {
	  printf("Arquivo nao pode ser aberto!");
	  exit(1);
       }
  fseek(s, 0, SEEK_END);
  tam=ftell(s);
  fseek(s, 0, SEEK_SET);
  ta=ftell(s);
  while(tam>ta)
  {
     fprintf(f,"%c",getc(s));
     ta=ftell(s);
  }
  fclose(f);
  fclose(s);
}