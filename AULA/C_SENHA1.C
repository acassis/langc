#include<stdio.h>
#include<conio.h>
void carrega(void);
void salva(void);
struct dados{
  char nome[30],senha[10];
  struct dados *proxima;
}*primeiro,*atual,*novo,*morto,real;
void main(void)
{
  int i=0;
  FILE *fp;
  char y;
  carrega();
  atual->proxima=novo;
  atual=novo
  printf("\nentre com nome : ");
  gets(atual->nome);
  printf("entre com senha : ");
   while(i< 10)
	{
	 y=getch();
	 atual->senha[i]=y+1000;
	 if(y=='\r')break;
	 i++;
	 printf("*");
	}
	atual->senha[i+1]='\0';
      salva();
}
void salva(void)
{ FILE *op; int i,j;
  if((op=fopen("acess.wil","wb"))==NULL)
  { puts("arquivo nao pode ser aberto"); getch(); return; }
  atual=primeiro;  strcpy(real.nome,atual->nome);
  strcpy(real.senha,atual->senha);
  while((fwrite(&real,sizeof(real),1,op))==1)
  {if(atual->proxima==NULL) break;
    atual=atual->proxima;
    strcpy(real.nome,atual->nome);strcpy(real.senha);  }
  fcloseall(); }
void carrega(void)
{ FILE *op;
  free(primeiro);  free(atual);  free(novo);
  if((op=fopen("acess.wil","rb"))==NULL)
  {  novo=(struct dados*)malloc(sizeof(struct dados));
     primeiro=atual=novo;
     return;  }
  if( (op=fopen("acess.wil","a+b"))==NULL)
  { puts("arquivo nao pode ser aberto"); getch(); return;  }
   fseek(op,0,SEEK_SET);
   novo=(struct dados*)malloc(sizeof(struct dados));
   primeiro=atual=novo;
   while(fread(&real,sizeof(real),1,op)==1)
    { strcpy(atual->nome,real.nome);
      strcpy(atual->senha,real.senha);
      novo=(struct dados*)malloc(sizeof(struct dados));
      morto=atual;    atual->proxima=novo;   atual=novo;  }
     atual=morto;     atual->proxima=(struct inform_nota*)NULL;
     fcloseall();
}

