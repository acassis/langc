/* escrita em disco
  escarq.c
*/
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
  FILE *fp;
  int ch,i=0;
  char n[100];
  if(argc!=2)
  {
   puts("numeros de argumentos invalidos");
   exit(1);
  }
  if( (fp=fopen("lixo.doc","w")) ==NULL)
  {
   puts("erro arquivo nao pode ser aberto");
   exit(1);
   }
   strcpy(argv[1],n);
   while( (ch!=n[i++])!=0)
     putc(ch,fp);
   fcloseall();
}
