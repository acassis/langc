/* lendo getc
*/
#include <stdio.h>
#include <stdlib.h>
void main(void)
{
 FILE *fp;
 char ch;
 fp=fopen("teste.doc","r");
 if(fp==NULL)
  {
   puts("nao posso abrir arquivo");
   exit(1);
  }
  while(ch=getc(fp)!=EOF)
       printf("%s",ch);
  fclose(fp);
}
