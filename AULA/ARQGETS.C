/****************************************************************************
arqgets.c
*/
#include <string.h>
#include <stdio.h>
int main(void)
{
   FILE *stream;
   char string[] = "Isto e um teste";
   char msg[20];
    /* abre arquivo p/ leitura e escreita */
   stream = fopen("teste.FIL", "w+");
    /* grava a string no arquivo
   fwrite(string que sera gravada, tamanho da string,quantidade,ponteiro do arquivo)
    */
   fwrite(string, strlen(string), 1, stream);
    /* seek to the start of the file
   int fseek(FILE *stream, quantidade em byte que ira andar,de onde deslocar );
   0 - come‡o do arquivo            - ou-SEEK_SET
   1 - posi‡Æo corrente do ponteiro -ou- SEEK_CUR
   2 - fim do arquivo               -ou- SEEK_END

   retorna posicao do ponteiro no arquivo*/
   fseek(stream, 0, SEEK_SET);
    /* le uma string para o arquivo
   fgets(string onde ira guardar a leitura, tamanho da string,ponteiro do arquivo);
   */
   fgets(msg, strlen(string)+1, stream);
    /* imprime a string que foi lida pela fun‡Æo gets */
   printf("%s", msg);
    fclose(stream);
   return 0;
}