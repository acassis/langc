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
   if( (s=fopen("teste.txt", "r"))==NULL)
    {puts("arquivo n∆o pode ser criado");return;}
   while(fgets(msg,80,s))
       printf("%s",msg);
   fclose(s);
}