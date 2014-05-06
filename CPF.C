//----------------------------------------------------------------------------
//Programa: Cpf.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Testa numero de cpf!
//-----------------------------------------------------------------------------
#include <conio.h>
#include <dos.h>
#include<stdlib.h>
div_t x;
char ch,cpf[11],cpf_tmp[11];
void main()
{
  int i,y,col=17,acum=0;
  clrscr();
  printf("Informe seu CPF:         -  .");
  gotoxy(col,1);
  for(i=0;i<11;)
  {
    ch=getch();
    if(ch>='0' && ch<='9')
    {
       gotoxy(col,1);
       printf("%c",ch);
       col++;
       if(col==26)
       {
	  gotoxy(++col,1);
       }
    }
    else
	 continue;
    cpf[i]=ch;
    i++;
  }
  cpf[11]='\0';
//----------------------------------------------------------------------------
  for(i=0;i<9;i++)
  {
     acum=acum+( (cpf[i]-48)*(10-i) );
  }
  x = div(acum,11);
  if(x.rem>1)
     acum = 11 - (x.rem);
  else
     acum=0;
  strcpy(cpf_tmp,cpf);
  cpf_tmp[9]=acum+48;
  cpf_tmp[10]='\0';
//----------------------------------------------------------------------------
  acum=0;
  for(i=0;i<10;i++)
  {
     acum=acum+( (cpf_tmp[i]-48)*(11-i) );
  }
  x = div(acum,11);
  if(x.rem>1)
     acum = 11 - (x.rem);
  else
     acum=0;
  cpf_tmp[10]=acum+48;
  cpf_tmp[11]='\0';
//----------------------------------------------------------------------------
  for(i=0;i<11;i++)
     if(cpf[i]!=cpf_tmp[i])
     {
	  printf("\nSeu CPF esta incorreto!");
	  break;
     }
  if(i==11)
     printf("\nSeu CPF esta correto!");
  getch();
}