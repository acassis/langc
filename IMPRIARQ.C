#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <grafico.h>
int main(int argc,char *argv[])
{
   FILE *stream;
   char nome[12],ch;
   int i=0,j=0;
   strcat(nome,argv[1]);
   clrscr();
   puts("Informe o nome do arquivo a ser impresso:");
   gets(nome);
   stream = fopen(nome, "r+");
   fseek(stream, 0, SEEK_SET);
   ch='x';
   while (ch != EOF)
   {
      ch = fgetc(stream);
     imprime(ch);
     if(ch!=10){
       putch(ch);}
     else{
      j++;
      printf("\n");}
      i++;
   }
   fclose(stream);
   return 0;
}
