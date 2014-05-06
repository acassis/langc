/* escrita com fprintf
*/
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
 FILE *fp;
 char nome[]="c/c++ 1001 dicas";
 float preco=62.10;
 fp=fopen("teste.doc","w");
 if(fp==NULL)
  {
   puts("nao posso abrir arquivo");
   exit(1);
  }
  fprintf(fp,"o livro %s \n",nome);
  fprintf(fp,"custa %.2f\n",preco);
  fclose(fp);
}