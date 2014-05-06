/****************************************************************************
lista ligada  (tipo banco de dado)
*****************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void exibe(void);  void insere(void); char menu(void);
void salva(void); void carrega(void); void pesquisa(void);
struct inform_nota
{ char nome[30];
  float nota1,nota2,nota3,nota4,media;
  struct inform_nota *proxima;
};
typedef struct inform_nota nota_t;
nota_t *primeiro,*atual,*novo,*morto,inf_nota;
void main(void)
{char opcao;  clrscr();
 for(;;){ opcao=menu(); puts("");  switch(opcao){
      case 'i': insere();     break; case 'e': exibe();   break;
      case 's': salva();      break; case 'c': carrega(); break;
      case 'p': pesquisa();   break; case 't': return;     } }}
char menu(void)
{ char ch; clrscr();
  do{clrscr();
     printf("Menu de op‡oes\n(I)nsere\n(E)xibe\n(S)alva\n(C)arrega\n");
     printf("(P)pesquisa\n(T)ermina\nsua opcao : ");
     ch=tolower(getche());  printf("\n");
     }while(strchr("ietscp",ch)==0);     return (ch);}
void exibe(void)
{ clrscr();
  if(primeiro==(struct inform_nota*) NULL)
     { puts("lista vazia"); getch(); return;  }
     atual=primeiro;
     do
     { printf("\nnome do aluno  : %s\n",atual->nome);
       printf("1 § nota : %5.1f\n",atual->nota1);
       printf("2 § nota : %5.1f\n",atual->nota2);
       printf("3 § nota : %5.1f\n",atual->nota3);
       printf("4 § nota : %5.1f\n",atual->nota4);
       printf("media    : %5.1f\n\n",atual->media);
       puts("pressione  qualquer tecla p/ continuar");   getch();
      atual=atual->proxima;
      }while(atual!=(struct inform_nota*)NULL);   return;}
void insere(void)
{  float x1,x2,x3,x4;
   novo=(struct inform_nota*)malloc(sizeof(struct inform_nota));
   if(primeiro==(struct inform_nota*) NULL) primeiro=atual=novo;
   else{atual=primeiro;
      while(atual->proxima!=NULL) atual=atual->proxima;
      atual->proxima=novo; atual=novo;}
   printf("nome do aluno n§ :");   flushall(); gets(atual->nome);
   printf("1§nota              : ");  scanf("%f",&x1); atual->nota1=x1;
   printf("2§nota              : ");  scanf("%f",&x2); atual->nota2=x2;
   printf("3§nota              : ");  scanf("%f",&x3); atual->nota3=x3;
   printf("4§nota              : ");  scanf("%f",&x4); atual->nota4=x4;
   atual->media=(atual->nota1+atual->nota2+atual->nota3+atual->nota4)/4;
   atual->proxima=(struct inform_nota*)NULL;
}
void salva(void)
{ FILE *op;  char nome[30];  int i,j;
  puts("digite o nome do arquivo para salvar :");
  flushall(); gets(nome);
  if((op=fopen(nome,"wb"))==NULL)
  { puts("arquivo nao pode ser aberto"); getch(); return; }
  atual=primeiro;  strcpy(inf_nota.nome,atual->nome);
  inf_nota.nota1=atual->nota1;  inf_nota.nota2=atual->nota2;
  inf_nota.nota3=atual->nota3;  inf_nota.nota4=atual->nota4;
  inf_nota.media=atual->media;
  while((fwrite(&inf_nota,sizeof(inf_nota),1,op))==1)
  {if(atual->proxima==NULL) break;
      atual=atual->proxima;
    strcpy(inf_nota.nome,atual->nome);   inf_nota.nota1=atual->nota1;
    inf_nota.nota2=atual->nota2;         inf_nota.nota3=atual->nota3;
    inf_nota.nota4=atual->nota4;         inf_nota.media=atual->media;   }
  fcloseall(); }
void carrega(void)
{ FILE *op;  char nome[30];
  puts("digite o nome do arquivo para salvar :"); flushall();
  gets(nome);   free(primeiro);  free(atual);  free(novo);
  if( (op=fopen(nome,"rb"))==NULL)
  { puts("arquivo nao pode ser aberto"); getch(); return;  }
   novo=(struct inform_nota*)malloc(sizeof(struct inform_nota));
   primeiro=atual=novo;
   while(fread(&inf_nota,sizeof(inf_nota),1,op)==1)
    { strcpy(atual->nome,inf_nota.nome);
      atual->nota1=inf_nota.nota1;    atual->nota2=inf_nota.nota2;
      atual->nota3=inf_nota.nota3;    atual->nota4=inf_nota.nota4;
      atual->media=inf_nota.media;
      novo=(struct inform_nota*)malloc(sizeof(struct inform_nota));
      morto=atual;    atual->proxima=novo;   atual=novo;  }
     atual=morto;     atual->proxima=(struct inform_nota*)NULL;
}
void pesquisa(void)
{ char no[30];  int i=0;  clrscr();  flushall();
  puts("\ndigite o nome a pesquisar");  gets(no);
  if(primeiro==(struct inform_nota*) NULL)
     { puts("lista vazia"); getch(); return;  }
     atual=primeiro;
     do
     {if(strcmp(no,atual->nome)==0)
       {printf("\nnome do aluno  : %s\n",atual->nome);
	printf("1 § nota : %5.1f\n",atual->nota1);
	printf("2 § nota : %5.1f\n",atual->nota2);
	printf("3 § nota : %5.1f\n",atual->nota3);
	printf("4 § nota : %5.1f\n",atual->nota4);
	printf("media    : %5.1f\n\n",atual->media);
	puts("pressione  enter  p/ continuar");        i++;  getch();  }
      atual=atual->proxima;
      }while(atual!=(struct inform_nota*)NULL);
      if(i==0) {puts("\nnome nao encontrado");
      puts("pressione  enter  p/ continuar"); getch();}
      return;
}