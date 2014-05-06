/*
crie uma estrutura que receba o nome e idade de um aluno
passando para uma funcao receber
*/
#include <stdio.h>
#include <conio.h>
struct aluno{
       char *nome;
       int idade;
       };
void recebe(void);
struct aluno *a;
void main(void)
{
  char n[30];
  clrscr();
  puts("entre com o nome do aluno e com a idade");
  flushall();
  gets(n);
  a->nome=&n;
  scanf("%d",&a->idade);

  recebe();
  printf("\n%s tem %d anos\n",a->nome,a->idade);
  getch();
}
void recebe()
{
  printf("\n%s tem %d anos\n",(*a).nome,(*a).idade);
  flushall();
  puts("entre com o nome do aluno e com a idade");
  gets(a->nome);
  scanf("%d",&a->idade);
  printf("\n%s tem %d anos\n",(*a).nome,(*a).idade);

}