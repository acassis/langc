#include <stdio.h>
#include <conio.h>
void main(int argc,char *argv[])
{
  FILE *out,*in;
  int c;
   if(argc==3)
 {
  in=fopen(argv[1],"r");
  if(in==NULL)
   { puts("nao posso abrir arquivo");  exit(1); }
  out=fopen(argv[2],"w");
    if(out==NULL)
   { puts("nao posso abrir arquivo");  exit(1); }

  while((c=getc(in))!=EOF)
      putc(c,out);
  }
  else puts("numero de argumentos invalidos");
  fcloseall(); //fclose(in); fclose(out);
}