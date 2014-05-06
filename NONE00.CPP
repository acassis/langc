#include <graphics.h>
#include <grafico.h>
#include <stdio.h>
#include <conio.h>
#include "let.h"
char escreve(void),ch='a';
int mt[19] [16],i=0,j;
void salva(char cha)
{  FILE *s;
   char nome[30];
   if ((s=fopen("bicho.h","r+"))==NULL)
   {  printf("\nArquivo nao pode ser criado.");
      return; }
   fseek(s, 0, SEEK_SET);
   while (ch != EOF)
   {
      ch = fgetc(s);
   }
   fprintf(s," %d - %c ",cha,cha);
};
void main(void)
{
    char ch=0;
    clrscr();
    while(!kbhit() && ch<256)
     {
      salva(ch);
      ch++;
      }
}