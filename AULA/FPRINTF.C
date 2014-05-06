/*
*****************************************************************************
gravando dados com fprintf e lendo com scanf
stdin   - teclado
stdout  - tela
stdprn  - impressora
FILE *p - arquivo
*/
#include <stdio.h>
int main(void)
{
   FILE *stream;
   int i = 100;
   char c = 'C';
   float f = 1.234;

   /* abre arquivo para escrita e leitura */
   stream = fopen("DUMMY.FIL", "wb");

   /* grava variaveis de dados no arquivo */
   fprintf(stream, "%d %c %f", i, c, f);

   /* fecha o arquivo */
   fclose(stream);
}