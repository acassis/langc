/*
#define(diretivo) => define uma macro ou uma constante;
As macros e constantes s∆o substituida no programa a cada
vez que ela Ç utilizada no programa, por isso a mesma n∆o
deve ser utilizada com ponto e v°rgula, pois se for utilizada
a v°rgula tambÇm ser† utilizada, causando um erro.
*/
#include<stdio.h>
#include<conio.h>
#define linha 128
#define string "testando uma constante"
#define men "macros"
#define maiusculo(x)( ((x)>='a')&&((x)<='z')?(x)-'a'+'A':(x))
#define soma(r,t)((r)+(t))
void main(void)
{
  char livro[linha];
  char nome[linha];
  char c;
  int f,g;
  clrscr();
  printf("%s ",string);
  printf(men);
  puts("\ndigite um caractere");
  c=getche();
  c=maiusculo(c);
  printf("\n%c",c);
  puts("\ndigite dois numeros");
  scanf("%d%d",&f,&g);
  printf("\n%d",soma(f,g));
}
/*
1) crie uma macro que receba dois numeros e retorne o maior.
2) crie uma macro que receba dois numeros e retorne o menor.
3) crie uma macro que converta um caractere em minusculo.
4) crie uma macro que calcule o cubo de um n£mero.
5) crie uma macro que receba base e altura de um triÉngulo e calcule a †rea
do triÉngulo.
*/


