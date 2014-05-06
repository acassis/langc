#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main(int argc,char *argv[])
{
 FILE *entrada,*saida;
 char ch;
 if(argc!=3)
 {
   puts("Erro de parametros");
   getch();
   exit(1);
  }
  if((entrada=fopen(argv[1],"rb"))==NULL)
  {
   printf("Erro ao abrir arquivo %s",argv[1]);
   getch();
   exit(1);
   }
  if((saida=fopen(argv[2],"wb"))==NULL)
  {
   printf("Erro ao abrir arquivo %s",argv[1]);
   getch();
   exit(1);
   }
   /* isto copia arquivo  */
   while(!feof(entrada))
   {
     ch=getc(entrada);
     if(ferror(entrada))
      { printf("erro ao ler o arquivo");
	getch();
	break;
       }
     putc(ch,saida);
     if(ferror(saida))
     {
	printf("erro ao ler o arquivo");
	getch();
	break;
      }
   }//fim de while
   fclose(entrada);
   fclose(saida);
}//fim de main