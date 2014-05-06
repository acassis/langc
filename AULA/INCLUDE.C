/*
#include "nome do arquivo"
include arquivos de cabe‡alho.
*/
#include <stdio.h>
#include <conio.h>
#include "funcao.h"
void main(void)
{
  char c;
  cor(2,LIGHTMAGENTA ,0);
  limpa(9,9,15,50);
  borda(9,9,15,50);
  posc(10,11);
  printf("digite uma letra ");
  c=getche();
  printf(" %c",c);
}