/****************************************************************************
fgets.c
*/
#include <string.h>
#include <stdio.h>
int main(void)
{
   FILE *s;
   char msg[81];
    /* abre arquivo p/ leitura e escrita */
   if( (s=fopen("teste.txt", "w"))==NULL)
    {puts("arquivo nÆo pode ser criado");return;}
   while(strlen(gets(msg))>0)
       { fputs(msg,s);fputs("\n",s);}
   fclose(s);
}