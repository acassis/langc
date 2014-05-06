/*
crie uma estrutura que receba o nome e idade de um aluno
passando para uma funcao receber
*/
#include <stdio.h>
#include <conio.h>
struct aluno{
       char nome[30];
       int idade;
       };
void recebe(struct aluno a);
void main(void)
{
  struct aluno a;
  clrscr();
  puts("entre com o nome do aluno e com a idade");
  gets(a.nome);
  scanf("%d",&a.idade);

  recebe(a);
  printf("\n%s tem %d anos\n",a.nome,a.idade);
  getch();
}
void recebe(struct aluno a)
{
  printf("\n%s tem %d anos\n",a.nome,a.idade);
  flushall();
  puts("entre com o nome do aluno e com a idade");
  gets(a.nome);
  scanf("%d",&a.idade);
  printf("\n%s tem %d anos\n",a.nome,a.idade);

}