/*
crie uma estrutura que receba o nome e idade de um aluno
*/
#include <stdio.h>
#include <conio.h>
struct aluno{
       char nome[30];
       int idade;
       };
void main(void)
{
  struct aluno a;
  puts("entre com o nome do aluno e com a idade");
  gets(a.nome);
  scanf("%d",&a.idade);
  printf("\n%s tem %d anos\n",a.nome,a.idade);
  getch();
}