#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

struct ficha {
	char nome[30];
	float n[4];
	struct ficha *proximo;
	};
	struct ficha *primeiro,*atual,*novo;

void say(int l,int c,char *p)
{
  gotoxy(c,l);
  cprintf("%s",p);
}

char menu(void)
{
  char ch;
  clrscr();
  do
   { clrscr();
     say(10,5,"MENU  DE  OPCOES");
     say(11,5,"(I)NSERE");
      say(12,5,"(E)XIBIR");
       say(13,5,"(T)ERMINAR");
      ch=tolower(getch());
    }while(strchr("iet",ch)==0);
    return(ch);
}
void insere(void)
{
  float x[4];
  int i,cont=0;
  clrscr();
  novo=(struct ficha *)malloc(sizeof(struct ficha));
  if(primeiro==(struct ficha*)NULL)
     {
      primeiro=atual=novo;
      cont=1;
      }
  else
     { atual=primeiro;
	  cont=cont+2;
       while(atual->proximo!=NULL)
	{ atual=atual->proximo;
	  cont=cont+1;
	}
       atual->proximo=novo;
       atual=novo;
      }

   for(i=0;i<4;i++)
     {
      if(i==0)
	{say(9,5,"");
	 printf("FICHA N§ %d",cont);
	 say(10+i,5,"ENTRE COM O NOME  DO ALUNO :");
	 gets(atual->nome);
	 }

      say(11+i,5,"ENTRE COM A ");
      cprintf("%1d§ NOTA DO ALUNO : ",i+1);
      cscanf("%f",&x[i]);
      atual->n[i]=x[i];
     }
   atual->proximo=(struct ficha*)NULL;
   return;
}
void exibe(void)
{int i,cont=1;
  clrscr();
  if(primeiro==(struct ficha*)NULL)
  {
    say(24,25,"LITRA VAZIA");
    return;
  }
  atual=primeiro;
  do
   {say(9,5,"FICHA N§ ");
    cprintf("%d",cont);
    say(10,5,"aluno : ");
    printf("%s",atual->nome);
    for(i=0;i<4;i++)
     { say(11+i,5,"");
      cprintf("%d§ nota=%f ",i+1,atual->n[i]);
     }
      say(24,25,"tecle algum");
      getch();
     atual=atual->proximo;
     cont++;
   }while(atual!=(struct ficha*)NULL);
}
void main(void)
{
  char op;
  clrscr();
  for(;;)
  {
    op=menu();
    switch(op)
     {
      case'i':
	 insere();break;
      case 'e':
	 exibe();break;
      case 't':
	 return;
   }
  }
}