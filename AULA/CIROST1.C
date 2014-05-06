#include <stdio.h>
#include <string.h>
#include <conio.h>
char str1[20]="ciro";
char str2[20];
char str3[20];
// fun‡Æo ler() que utiliza as fun‡äes puts() e gets()
void ler(char str[])
{  puts("Digite um nome para str1 20");   gets(str); }
// fun‡Æo tamanho() que utiliza a fun‡Æo strlen para retornar o tamanho
int tamanho(char str[])
{  int l; l=strlen(str); return l;}
// fun‡Æo strdel() que utiliza strcpy() para eliminar um caractere
void strdel(char str[],int n)
{ strcpy(&str[n],&str[n+1]); }
// programa principal
void main(void)
{ int a1,a2,a3,n=0;
  clrscr();
  ler(str2);
  ler(str3);
  a1=tamanho(str1);
  a2=tamanho(str2);
  a3=tamanho(str3);
  puts("");
  puts(str1);
  printf("\ntamanho de str1 %d:\n",a1);
  puts("");
  puts(str2);
  printf("\ntamanho de str2 %d:\n",a2);
  puts("");
  puts(str3);
  printf("\ntamanho de str3 %d:\n",a3);
  // fun‡Æo strcat() copy uma string no final de outra
  strcat(str3,str2);
  a1=tamanho(str3);
  puts(str3);
  printf("\ntamanho de str3 %d:\n",a1);
  strcat(str2,str3);
  a1=tamanho(str2);
  puts(str2);
  printf("\ntamanho de str2 %d:\n",a1);
  // fun‡Æo strcmp() compara duas string retornando 0 quando iguais
  while(strcmp(str1,str3)!=0)
  {
    n++;
    if(n<=3){
      printf("diferen‡a = %d",strcmp(str1,str3));
      puts("\ndigite sua senha novamente");
      gets(str3);}
    else{
	 puts("tempo esgotado");
	 break;}
    }
    strdel(str1,2);
    a1=tamanho(str1);
    puts(str1);
    printf("\ntamanho str1 %d",a1);
}

