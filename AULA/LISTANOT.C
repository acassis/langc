/*
****************************************************************************
lista ligada
****************************************************************************
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void exibe(void);  void insere(void); char menu(void);
struct inform_nota
{ char nome[30];
  float nota1,nota2,nota3,nota4,media;
  struct inform_nota *proxima;
};
typedef struct inform_nota nota_t;
nota_t *primeiro,*atual,*novo,inf_nota;
void main(void)
{
 char opcao;  clrscr();
 for(;;)
  { opcao=menu(); puts("");
    switch(opcao){
	   case 'i': insere();  break;
	   case 'e': exibe();   break;
	   case 't':  return;
		}
   }
}
char menu(void)
{ char ch; clrscr();
  do{
     printf("Menu de op‡oes\n(I)nsere\n(E)xibe\n(T)ermina\nsua opcao : ");
     ch=tolower(getche());  printf("\n");
     }while(strchr("iet",ch)==0);
     return (ch);
}
void exibe(void)
{ clrscr();
  if(primeiro==(struct inform_nota*) NULL)
     {
      puts("lista vazia"); getch(); return;
     }
     atual=primeiro;
     do
     {
      printf("\nnome do aluno  : %s\n",atual->nome);
      printf("1 § nota : %5.1f\n",atual->nota1);
      printf("2 § nota : %5.1f\n",atual->nota2);
      printf("3 § nota : %5.1f\n",atual->nota3);
      printf("4 § nota : %5.1f\n",atual->nota4);
      printf("media    : %5.1f\n\n",atual->media);
      puts("pressione  qualquer tecla p/ continuar");
      getch();
      atual=atual->proxima;
      }while(atual!=(struct inform_nota*)NULL);
 return;
}
void insere(void)
{  float x1,x2,x3,x4;
   novo=(struct inform_nota*)malloc(sizeof(struct inform_nota));
   if(primeiro==(struct inform_nota*) NULL)
     primeiro=atual=novo;
   else
   {
      atual=primeiro;
      while(atual->proxima!=NULL)
	  atual=atual->proxima;// pega final da lista
      atual->proxima=novo;
      atual=novo;
   }
   printf("nome do aluno n§ :");   flushall(); gets(atual->nome);
   printf("1§nota              : ");  scanf("%f",&x1); atual->nota1=x1;
   printf("2§nota              : ");  scanf("%f",&x2); atual->nota2=x2;
   printf("3§nota              : ");  scanf("%f",&x3); atual->nota3=x3;
   printf("4§nota              : ");  scanf("%f",&x4); atual->nota4=x4;
   atual->media=(atual->nota1+atual->nota2+atual->nota3+atual->nota4)/4;
   atual->proxima=(struct inform_nota*)NULL;
}
