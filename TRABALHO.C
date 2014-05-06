#include <stdio.h>
#include <conio.h>
#include<ctype.h>
#include<string.h>
#define TAMANHO 3
#include<stdlib.h>
char menu(void);
void exibe (void);
void insere (void);
void init_list(void);
void maior_menor_media(void);
void maior_menor_final(void);
void ordena_por_media_imprime(void);
struct inform_nota
 {
      char nome[30];
      float nota1, nota2,nota3;
      float media;
 };
typedef struct inform_nota nota_t;
nota_t inf_nota[TAMANHO];

void main (void)
{
  char opcao;
  init_list();
  clrscr();
  for(;;)
  {
     opcao=menu();
     puts("");
     switch(opcao)
     {
       case 'i':
		insere();
		break;
       case 'e':
		exibe();
		break;
       case 'o':
		ordena_por_media_imprime();
		break;
       case 'm':
		maior_menor_media();
		break;
       case 't':
		return;
       case 'a':
		maior_menor_final();
		break;
      }
   }
}
void init_list(void)
{
    int i;
    for(i=0;i<TAMANHO;i++)
      inf_nota[i].nome[0]='\0';
}
char menu(void)
{
   char ch;
   clrscr();
   do
   {
	 printf("Menu\n");
	 printf("(I)nsere\n");
	 printf("(E)xibe\n");
	 printf("(M)aior e menor por exame,media por exame\n");
	 printf ("(O)rdena por nota final e imprime\n");
	 printf("(a)Maior e menor media\n");
	 printf("(T)ermina\n");
	 printf("opcao:");
	 ch=tolower(getch());
	 printf("\n");
   }while(strchr("ieamot",ch)==0);
   return tolower(ch);
}
void exibe(void)
{
   int i;
   clrscr();
   for(i=0;i<TAMANHO;i++)
   {
	  if(inf_nota[i].nome[0]!='\0')
	  {
		  printf("\nnome do %d§ aluno  : %s\n",i+1,inf_nota[i].nome);
		  printf("1§ nota: %5.1f\n",inf_nota[i].nota1);
		  printf("2§ nota: %5.1f\n",inf_nota[i].nota2);
		  printf("3§ nota: %5.1f\n",inf_nota [i].nota3);
		  printf("media..: %5.1f\n",inf_nota[i].media);
		  puts(" pressione qualquer tecla para continuar");
		  getch();
	  }
	  else
	    return;
    }
}
void insere (void)
{
    int i,a;
    float x1, x2,x3;
    clrscr();
    for(i=0;i<TAMANHO;i++)
	   if(inf_nota[i].nome[0]=='\0')
		   break;
    if(i==TAMANHO)
     {
       puts("lista cheia");
	  getch();
	  return;
     }
	  flushall();
	  a=i+1;
	  printf("nome do %d§ aluno:",a);
	  gets( inf_nota[i].nome);
	  printf("1§ nota:");
	  scanf("%f",&x1);
	  inf_nota[i].nota1=x1;
	  printf("2§ nota:");
	  scanf("%f",&x2);
	  inf_nota[i].nota2=x2;
	  printf("3§ nota:");
	  scanf("%f",&x3);
	  inf_nota[i].nota3=x3;
	  inf_nota[i].media=(inf_nota[i].nota1+inf_nota[i].nota2+ inf_nota[i].nota3)/3;
}
void ordena_por_media_imprime()
{
   int i,x;
   nota_t temp;
   clrscr();
   for(x=0;x<TAMANHO-1;x++)
	 for(i=0;i<=TAMANHO-2;i++)
	 {
		 if(inf_nota[i].media<inf_nota[i+1].media)
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
		printf("nome do aluno: %s\n",inf_nota[i].nome);
		printf("media:%5.1f\n",inf_nota[i].media);
		printf("1§ nota :%5.1f\n",inf_nota[i].nota1);
		printf("2§ nota :%5.1f\n",inf_nota[i].nota2);
		printf("3§ nota :%5.1f\n",inf_nota[i].nota3);
		puts("continuar..");
		getch();
	 }
}
void maior_menor_media(void)
{
    int  i,x;
    nota_t tempmaior1,tempmenor1,tempmaior2,tempmenor2,tempmaior3,tempmenor3,tempmedia;
    float maior1=0,maior2=0,maior3=0,menor1=1000;
    float menor2=1000,menor3=1000,media=0;
    clrscr();
    for(i=0;i<TAMANHO;i++)
    {
    if(inf_nota[i].nome[0]=='\0')
      break;
    if(inf_nota[i].nota1>maior1)
    {
	    maior1=inf_nota[i].nota1;
	    tempmaior1=inf_nota[i];
    }
    if(inf_nota[i].nota1<menor1)
    {
	    menor1=inf_nota[i].nota1;
	    tempmenor1=inf_nota[i];
    }
    if(inf_nota[i].nota2>maior2)
    {
	    maior2=inf_nota[i].nota2;
	    tempmaior2=inf_nota[i];
    }
    if(inf_nota[i].nota2<menor2)
    {
	    menor2=inf_nota[i].nota2;
	    tempmenor2=inf_nota[i];
    }
    if(inf_nota[i].nota3>maior3)
    {
	    maior3=inf_nota[i].nota3;
	    tempmaior3=inf_nota[i];
    }
    if(inf_nota[i].nota3<menor3)
    {
	    menor3=inf_nota[i].nota3;
	    tempmenor3=inf_nota[i];
    }
    if(inf_nota[i].media>media)
    {
	    media=inf_nota[i].media;
	    tempmedia=inf_nota[i];
     }
   }
printf("%s maoir 1§ nota=%5.1f \n%s menor 1§ nota=%5.1f",tempmaior1.nome,maior1,tempmenor1.nome,menor1);
printf("\n%s maoir 2§ nota=%5.1f \n%s menor 2§ nota=%5.1f",tempmaior2.nome,maior2,tempmenor2.nome,menor2);
printf("\n%s maoir 3§ nota=%5.1f \n%s menor 3§ nota=%5.1f",tempmaior3.nome,maior3,tempmenor3.nome,menor3);
printf("\n %s maior media=%5.1f",tempmedia.nome,media);
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
	  if(inf_nota[i].media>maior_final)
	  {
		  maior_final=inf_nota[i].media;
		  temp_maior=inf_nota[i];
	  }
	  if(inf_nota[i].media<menor_final)
	  {
	  menor_final=inf_nota[i].media;
	  temp_menor=inf_nota[i];
	  }
 }
 clrscr();
 printf("a maior media pertence a: %s e : %5.1f \n",temp_maior.nome,temp_maior.media);
 printf("a menor media pertence a: %s e : %5.1f \n",temp_menor.nome,temp_menor.media);
 puts("pressione <ENTER> para retornar ao menu");
 getch();
}





