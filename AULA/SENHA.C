#include<stdio.h>
#include<conio.h>
#include<string.h>
#define TAMANHO 20
void init(void);
struct dados{
  char n[30],senha[10];
}usuario[TAMANHO];
void main(void)
{
  int i=0,u=0;
  FILE *fp;
  char y,f[30],f1[11];
  clrscr();
  init();
  if((fp=fopen("Senha.ShA","rb"))==NULL)
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
  printf("\nentre com nome  : ");
  gets(f);
  for(u=0;u<TAMANHO;u++)
     if(strcmp(usuario[u].n,f)==0)
       break;
   if(u==TAMANHO)
      {puts("nome nÆo cadastrado");getch();return;}
   printf("entre com senha : ");
   while(i< 10)
	{
	  y=getch();
	  f1[i]=y+1000;
	  if(y=='\r')  break;
	  i++;
	  printf("*");
	 }
	 f1[i+1]='\0';
    /*
    SEEK_SET   Seeks from beginning of file
    SEEK_CUR   Seeks from current position
    SEEK_END   Seeks from end of file
    fseek(fp,30,SEEK_SET);*/
    //printf("%s %s",f,f1);
    if(strcmp(f1,usuario[u].senha)==0)
       printf("\n%s digitou uma senha valida",usuario[u].senha);
    else
	printf("\nnome e senha nÆo confere");
  getch();
  fclose(fp);
}
void init(void)
{ int i;for(i=0;i<TAMANHO;i++) usuario[i].n[0]='\0'; }
