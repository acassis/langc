#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include "\aula\aula\tela.ch"
#include "\aula\aula\fontes.h"
#define TAMANHO 200
char menu(void);
void exibe(void);
void insere(void);
void init_list(void);
void maior_menor_media(void);
void maior_menor_final(void);
void ordena_por_media_imprime(void);
void pesquisa_por_nome(void);
void salvar(void);
void carregar(void);
void registro(void);
void index_caracter(void);
struct inform_nota
{
	char nome[30];
	float nota1,nota2,nota3;
	float media;
};

typedef struct inform_nota nota_t;
nota_t inf_nota[TAMANHO];




void main(void)
{
	char opcao;
	clrscr();
	letras(5,10,"Controle");
	letras(11,30,"de");
	letras(17,20,"Notas");
	delay(5000);
	init_list();
	clrscr();
	for(;;)
	{
		opcao=menu();
		//savescreen(1,1,25,80);
		puts("");
		switch(opcao)
		{
		 case 'i':
			 clrscr();
			 insere();
			 break;
		case 'e':
			 clrscr();
			 exibe();
			 break;

		case 'o':
			 clrscr();
			 ordena_por_media_imprime();
			 break;
		case 'l':
			 clrscr();
			 index_caracter();
			 break;

		case 'm':
			 clrscr();
			 maior_menor_media();
			 break;
		case 'a':
			 clrscr();
			 maior_menor_final();
			 break;
		case 's':
			 clrscr();
			 salvar();
			 break;
		case 'c':
			 clrscr();
			 carregar();
			 break;
		case 'r':
			 clrscr();
			 registro();
			 break;
		case 'p':
			 clrscr();
			 pesquisa_por_nome();
			 break;
		case 't':
			 return;
		}
		//restorescreen(1,1,25,80);
	}
}







void init_list(void)
{
	int i;
	for(i=0;i<TAMANHO;i++)inf_nota[i].nome[0]='\0';
}






char menu(void)
{
	char ch;
	do
	{
	printf("Menu de op�oes\n");
	printf("(I)nsere\n");
	printf("(E)xibe\n");
	printf("(M)aior e menor nota por exame,media por exame\n");
	printf("(O)rdena por nota final e imprime\n");
	printf("(l)ordena por nome\n");
	printf("(p)pesquisa por nome\n");
	printf("(a) Maior e menor media\n");
	printf("(S) salvar\n");
	printf("(C) carregar\n");
	printf("(R) registro\n");
	printf("(T)ermina\n");
	printf("sua opcao : ");
	ch=tolower(getche());
	printf("\n");
	}while(strchr("iemaotslcrp",ch)==0);
	return (ch);
}







void exibe(void)
{
	int i;
	clrscr();
	for(i=0;i<TAMANHO;i++)
	{
		if(inf_nota[i].nome[0] != '\0')
			{
			 printf("\nnome do aluno n� %d : %s\n",i+1,inf_nota[i].nome);
			 printf("1 � nota : %5.1f\n",inf_nota[i].nota1);
			 printf("2 � nota : %5.1f\n",inf_nota[i].nota2);
			 printf("3 � nota : %5.1f\n",inf_nota[i].nota3);
			 printf("media    : %5.1f\n\n",inf_nota[i].media);
			 puts("pressione  qualquer tecla p/ continuar");
			 getch();
		}
		else
			 return;
}
}





void insere(void)
{
	int i,a;
	float x1,x2,x3;
	clrscr();
	for(i=0;i<TAMANHO;i++)
		 if(inf_nota[i].nome[0]=='\0')break;

		 if(i==TAMANHO)
			 {puts("lista cheia");
			  getch();
				return;
				}


	a=i+1;
	printf("nome do aluno n� %d :",a);
	flushall();
	gets(inf_nota[i].nome);
	printf("1�nota              : ");
	scanf("%f",&x1);
	inf_nota[i].nota1=x1;
	printf("2�nota              : ");
	scanf("%f", &x2);
	inf_nota[i].nota2=x2;
	printf("3�nota              : ");
	scanf("%f", &x3);
	inf_nota[i].nota3=x3;
	inf_nota[i].media=(inf_nota[i].nota1+inf_nota[i].nota2+inf_nota[i].nota3)/3;
}







void ordena_por_media_imprime()
{
	int i,x;
	nota_t temp;
	clrscr();
	for(x=0;x<TAMANHO-1;x++)
	   for(i=0;i<=TAMANHO-2;i++)
	   {
	     if(inf_nota[i].media <inf_nota[i+1].media)
	      {
		temp=inf_nota[i];
		inf_nota[i]=inf_nota[i+1];
		inf_nota[i+1]=temp;
	     }
					}
		for(i=0;i<TAMANHO;i++)
				if(inf_nota[i].nome[0]!='\0')
					{
					clrscr();
					printf("\nnome do aluno : %s",inf_nota[i].nome);
					printf("\nmedia         : %5.1f",inf_nota[i].media);
					printf("\n1� nota        :%5.1f",inf_nota[i].nota1);
					printf("\n2� nota        :%5.1f",inf_nota[i].nota2);
					printf("\n3� nota        :%5.1f",inf_nota[i].nota3);
					puts("\npressione  qualquer tecla p/ continuar");
					getch();
					}
					puts("\npressione  <ENTER> p/ voltar ao menu  ");
					getch();
}










void maior_menor_media(void)
{
	int i,x;
	nota_t tempmaior1,tempmenor1,tempmaior2;
	nota_t tempmenor2,tempmaior3,tempmenor3,tempmedia;
	float maior1=0,maior2=0,maior3=0,menor1=1000;
	float menor2=1000,menor3=1000;
	float media=0;
	clrscr();
	for(i=0;i<TAMANHO;i++)
		 {
		 if(inf_nota[i].nome[0]=='\0')
				 break;


		 if(inf_nota[i].nota1 > maior1)
					 {
						 maior1 = inf_nota[i].nota1;
						 tempmaior1 = inf_nota[i];
					 }


			if(inf_nota[i].nota1 < menor1)
				 {
					 menor1 = inf_nota[i].nota1;
					 tempmenor1 = inf_nota[i];

					}
		 if(inf_nota[i].nota2 > maior2)
					 {
						 maior2 = inf_nota[i].nota2;
						 tempmaior2 = inf_nota[i];
					 }


			if(inf_nota[i].nota2 < menor2)
				 {
					 menor2 = inf_nota[i].nota2;
					 tempmenor2 = inf_nota[i];

					}
		 if(inf_nota[i].nota3 > maior3)
					 {
						 maior3 = inf_nota[i].nota3;
						 tempmaior3 = inf_nota[i];
					 }


			if(inf_nota[i].nota3 < menor3)
				 {
					 menor3 = inf_nota[i].nota3;
					 tempmenor3 = inf_nota[i];

					}




			if(inf_nota[i].media > media)
				 {
					 media = inf_nota[i].media;
					 tempmedia = inf_nota[i];

					}



}
printf("%s teve maior 1� nota=%5.1f \n %s teve menor 1� nota=%5.1f",tempmaior1.nome,maior1,tempmenor1.nome,menor1);
printf("\n%s teve maior 2� nota=%5.1f \n %s teve menor 2� nota=%5.1f",tempmaior2.nome,maior2,tempmenor2.nome,menor2);
printf("\n%s teve maior 3� nota=%5.1f \n %s teve menor 3� nota=%5.1f",tempmaior3.nome,maior3,tempmenor3.nome,menor3);
printf("\n%s teve maior media=%5.1f",tempmedia.nome,media);
getch();

}





void maior_menor_final()
{
	int i;
	float maior_final=0,menor_final=100;
	nota_t temp_maior,temp_menor;
	for(i=0;i<TAMANHO;i++)
		 {
			 if(inf_nota[i].nome[0]=='\0')
	  break;
			 if(inf_nota[i].media > maior_final)
					{
					maior_final=inf_nota[i].media;
					temp_maior=inf_nota[i];
					}

			 if(inf_nota[i].media < menor_final)
					{
					 menor_final=inf_nota[i].media;
					 temp_menor=inf_nota[i];
					}
			 }

			 clrscr();



			 printf("a maior media pertence a : %s e : %5.1f\n",temp_maior.nome,temp_maior.media);
			 printf("a menor media pertence a : %s e : %5.1f\n",temp_menor.nome,temp_menor.media);
			 puts("\npressione <ENTER> p/ voltar ao menu");
			 getch();
}
void salvar(void)
{
  FILE *op;
  char nome[30];
  int i,j;
  puts("digite o nome do arquivo para salvar :");
  flushall();
  gets(nome);
  if( (op=fopen(nome,"wb"))==NULL)
  {
    puts("arquivo nao pode ser aberto");
    getch();
    return;

  }
 if((fwrite(&inf_nota,sizeof(inf_nota),1,op))!=1) // grava o arquivo
       {
	 puts("erro na escrita");
	 getch();
	}

 fcloseall();
}

void carregar(void)
{
  FILE *op;
  char nome[30];
  int i,e;
  puts("digite o nome para restaurar :");
  flushall();
  gets(nome);
  if( (op=fopen(nome,"rb"))==NULL)
  {
    puts("arquivo nao pode ser aberto");
    getch();
    return;

  }
  init_list();
     while( (fread(&inf_nota,sizeof(inf_nota),1,op))==1 )
      {
	if(feof(op))
	{
	  fcloseall();
	  return;
	  }
      }
}
void index_caracter(void)
{
  nota_t temp;
  int i,j;
  for(j=0;j<TAMANHO;j++)
    for(i=0;i<TAMANHO;i++)
       if(strcmp(inf_nota[i].nome,inf_nota[i+1].nome)>0)
       {
	 temp=inf_nota[i];
	 inf_nota[i]=inf_nota[i+1];
	 inf_nota[i+1]=temp;
	}
}
void registro(void)
{
   int i;
   puts("informe o numero do registro :");
   scanf("%d",&i);
   printf("%s \n1� nota=%5.1f\n2� nota=%5.1f\n3� nota=%5.1f\nmedia=%5.1f"\
   ,inf_nota[i-1].nome,inf_nota[i-1].nota1,inf_nota[i-1].nota2,inf_nota[i-1].nota3,inf_nota[i-1].media);
   getch();
}


void pesquisa_por_nome(void)
{
  char nome[30];
  int i;
  printf("\nDigite o nome a pequisar");
  flushall();
  gets(nome);
  for(i=0;i<TAMANHO;i++)
  {
   if((stst(inf_nota[i].nome,nome))==1)
    {
     printf("\nnome do aluno n� %d : %s\n",i+1,inf_nota[i].nome);
     printf("1 � nota : %5.1f\n",inf_nota[i].nota1);
     printf("2 � nota : %5.1f\n",inf_nota[i].nota2);
     printf("3 � nota : %5.1f\n",inf_nota[i].nota3);
     printf("media    : %5.1f\n\n",inf_nota[i].media);
     puts("pressione  qualquer tecla p/ continuar");
     getch();
    }
 }

}



