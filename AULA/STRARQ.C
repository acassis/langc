/* recebe string da linha de comando e escreve em lixo.doc
strarq.c
*/
#include <stdio.h>
#include <conio.h>
void main(int argc,char *argv[])
{
 FILE *fp;
 int ch;
 if(argc!=2)
   {puts("numero de parametros invalidos");
   return;}
 if((fp=fopen("lixo.doc","w"))==NULL)
  {puts("arquivo nao pode ser aberto");
  return;}
 while(ch=*argv[1]++)
      putc(ch,fp);
 fcloseall();
}
