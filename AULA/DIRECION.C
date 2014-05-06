#include <stdio.h>
void main(void)
{
  char nome[30];
  puts("entre com nome :");
  fscanf(stdin,"%s",&nome);
  fputs(nome,stdprn);
}