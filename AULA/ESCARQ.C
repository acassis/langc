/* escrita em disco
  escarq.c
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
  if( (fp=fopen(argv[1],"w")) ==NULL)
  {
   puts("erro arquivo nao pode ser aberto");
   exit(1);
   }
   while(ch!='$')
   {
     ch=getchar(); //ch=getche();
     if(EOF==putc(ch,fp))
     {
      puts("erro ao escrever no arquivo");
      break;
      }
    } // fim while
      fclose(fp);
}
