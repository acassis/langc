//----------------------------------------------------------------------------
//Programa: Alanedit.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao:Cria um arquivo executavel que exibi em modo texto o desenho criado
//por voce dentro deste editor.
//-----------------------------------------------------------------------------

#include <graphics.h>
#include <stdio.h>
#include<process.h>
#include<dos.h>
char ch='a';
int mt[80] [25],i=0,j,cor=15;
void desliga (void)
{
      union REGS regs;
      regs.x.ax=2;
      int86(0x33,&regs,&regs);
}

int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx/8);

  }

int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx/8);
  }
void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
int status(void)
{
     union REGS regs;
     regs.x.ax=3;
     int86(0x33,&regs,&regs);
     return(regs.x.bx);
}
void salva(void)
{
   char nome[30];
   FILE *s;
volta:
   puts("Informe um nome ('*.exe' ou '*.com')  p/ salvar esta imagem:");
   gets(nome);
   clrscr();
   if(nome[0]==27)
      return;
   if(nome[0]<65)
     goto volta;
   if ((s=fopen(nome,"wb"))==NULL)
   {  printf("\nArquivo nao pode ser criado.");
      return; }
   fprintf(s,"¸%cÍ%c",0,10);
   for(i=0;i<25;i++)
      for(j=0;j<80;j++)
	    if(mt[j][i]!=0)
	     {
		 fprintf(s,"´¶%c²%cÍ´%c°Û³%c¹%cÍ",i,j,9,mt[j][i],0);
	     }
   fprintf(s,"´%cÍ%c´LÍ!",0,22);
   fclose(s);
}
//----------------------------------------------------------------------------
int main(void)
{
   int gdriver = DETECT,x, gmode,lin,col,sta,stant,ml1[25],ml2[25],mc1[80],mc2[80];
   i=0;j=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   bar(0,0,7,19);
   for(i=0;i<25;i++)
     for(j=0;j<80;j++)
	mt[j] [i]=0;

   i=0;j=0;
   ml2[0]=0;
   for(lin=0;lin<=479;lin+=19,i++)
   {
      line(8,lin,639,lin);
      if(lin<479)
       {
	 ml1[i]=lin;
	 if(i>0)
	   ml2[i-1]=lin;
	}
    }
   ml2[24]=479;
   i=0;
   line(639,0,639,475);
   mc2[0]=0;
   for(col=0;col<=639;col+=8,i++)
   {
     line(col,0,col,475);
     if(col<639)
      {
	mc1[i]=col;
	if(i>0)
	   mc2[i-1]=col;
      }
    }
   mc2[79]=639;
   setcolor(0);
   line(0,0,0,475);
   mouse();
   while(!(kbhit()))
   {
      stant=sta;
      mouse();
      lin=(linmouse()*8);
      col=(colmouse()*7.99999);
      sta=status();
      if(col>=0 && col<=6 && lin>=0 && lin<=19 && stant==0 && (sta==1 || sta==2)){
      if(sta==1)
	 cor++;
      else
	 cor--;
      if(cor==16)
	cor=1;
      if(cor==0)
	cor=15;
      desliga();
      setfillstyle( SOLID_FILL,cor);
      bar(0,0,7,19);}

      for(i=0;lin>ml1[i] ^ lin<ml2[i];i++);

      for(j=0;col>mc1[j] ^ col<mc2[j];j++);

      stant=sta;
      if(lin>=ml1[i] && lin<=ml2[i] && col>=mc1[j] && col<=mc2[j] )
      if(sta==1)
	{
	      desliga();
	      setfillstyle( SOLID_FILL,cor);
	     if(i!=24)
	      bar(mc1[j+1]+2,ml1[i]+2,mc2[j+1]-2,ml2[i]-2);
	     else
	      bar(mc1[j+1]+2,ml1[i]+2,mc2[j+1]-2,ml2[i]-6);
	      mt[j][i]=cor;
	}
      else
	if(sta==2)
	{

	      desliga();
	      setfillstyle( SOLID_FILL,0);
	     if(i!=24)
	      bar(mc1[j+1]+2,ml1[i]+2,mc2[j+1]-2,ml2[i]-2);
	     else
	      bar(mc1[j+1]+2,ml1[i]+2,mc2[j+1]-2,ml2[i]-6);
	     mt[j][i]=0;
	}

   }
   desliga();
   closegraph();
   salva();
   return 0;
}