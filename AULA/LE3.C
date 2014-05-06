#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main(int argc,char *argv[])
{
 FILE *fp;
 char ch;
 if(argc!=2)
 {
   puts("numero de argumentos invalidos");
   exit(1);
 }
  if((fp=fopen(argv[1],"r"))==NULL)
   { puts("nao posso abrir arquivo");  exit(1);
   }
   ch=getc(fp);
  while(ch!=EOF)
      {putchar(ch);
       ch=getc(fp);
       if(feof(fp))
       { puts("erro ao ler o arquivo");
	 break;
	}
      } // fim do while
 fclose(fp);
}