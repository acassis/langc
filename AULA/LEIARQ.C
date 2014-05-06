/* escrita em disco

*/
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
  FILE *fp;
  char ch;
  if(argc!=2)
  {
   puts("numeros de argumentos invalidos");
   exit(1);
  }
  if( (fp=fopen(argv[1],"r")) ==NULL)
  {
   puts("erro arquivo nao pode ser aberto");
   exit(1);
   }
   ch=getc(fp);
   while(ch!=EOF)
   {
     putchar(ch);
     ch=getc(fp);
     if(ferror(fp))
     {
      puts("erro ao ler o arquivo");
      break;
      }
    } // fim while
      fclose(fp);
}
