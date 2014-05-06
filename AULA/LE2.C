#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main(int argc,char *argv[])
{
 FILE *fp;
 int ch;
 clrscr();
 if(argc==2)
 {
  fp=fopen(argv[1],"r");
  if(fp==NULL)
   { puts("nao posso abrir arquivo");  exit(1); }
  while((ch=getc(fp))!=EOF)
      printf("%c",ch);
  }
  else puts("numero de argumentos invalidos");
 getch();
 fclose(fp);
}