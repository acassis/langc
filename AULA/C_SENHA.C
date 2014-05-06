#include<stdio.h>
#include<conio.h>
#define TAMANHO 20
void init(void);
struct dados{
  char n[30],senha[10];
}usuario[20];
void main(void)
{
  int i=0,u=0;
  FILE *fp;
  char y;
  init();
  if((fp=fopen("Senha.ShA","a+b"))==NULL)
    { puts("arquivo de dados nao pode ser aberto");
      return;
    }
    while( (fread(&usuario,sizeof(usuario),1,fp))==1 )
      {
	if(feof(fp))
	{
	  fcloseall();
	  return;
	  }
      }
 for(u=0;u<TAMANHO;u++)
    if(usuario[u].n[0]=='\0')
       break;
  printf("\nentre com nome : ");
  gets(usuario[u].n);
  printf("entre com senha : ");
   while(i< 10)
	{
	 y=getch();
	 usuario[u].senha[i]=y+1000;
	 if(y=='\r')break;
	 i++;
	 printf("*");
	}
	usuario[u].senha[i+1]='\0';
      //      printf("%s",usuario[j].senha);
      //      getch();

      if((fwrite(&usuario,sizeof(usuario),1,fp))!=1) // grava o arquivo
       {
	 puts("erro na escrita");
	 getch();
	}

  fclose(fp);
}
void init(void)
{ int i;for(i=0;i<TAMANHO;i++) usuario[i].n[0]='\0'; }