#include <graphics.h>
#include <stdio.h>
#include <dos.h>
void mudamouse(unsigned segimag,unsigned offimag,unsigned lin,unsigned col)
{
  union REGS regs;
  struct SREGS sregs;
  regs.x.ax=0x09;
  regs.x.bx=col;
  regs.x.cx=lin;
  sregs.es=segimag;
  regs.x.dx=offimag;
  int86x(0x33,&regs,&regs,&sregs);
}
struct imagem
{
  unsigned imag[32];
  int lin,col;
};
#include "let.h"
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

char escreve(void),ch='a';
int mt[19] [16],i=0,j;
void salva(void)
{  FILE *s;
   char nome[30];
   printf("\nDigite o nome do cursor:");
   flushall();
   gets(nome);
   if(nome[0]>=65){
   if ((s=fopen("bicho.h","r+"))==NULL)
   {  printf("\nArquivo nao pode ser criado.");
      return; }
   fseek(s, 0, SEEK_SET);
   while (ch != EOF)
   {
      ch = fgetc(s);
   }
   fprintf(s,"\n %s [16][19]={\n",nome);
   for(i=0;i<16;i++){
    fprintf(s,"{");
      for(j=0;j<19;j++){
	     if(j!=18)
	     fprintf(s,"%1d,",mt[j][i]);
	     else
	     fprintf(s,"%1d},\n",mt[j][i]);}
   }
   fprintf(s,"\n};");
   fclose(s); }
}
int main(void)
{
   int gdriver = DETECT,x, gmode,lin,col,sta,stant,ml1[16],ml2[16],mc1[19],mc2[19];
   for(i=0;i<16;i++)
     for(j=0;j<19;j++)
	mt[j] [i]=0;
   i=0;j=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   ml2[0]=65;
   for(lin=40;lin<=440;lin+=25,i++){
      line(95,lin,570,lin);
      if(lin<440){
	 ml1[i]=lin;
	 if(i>0)
	   ml2[i-1]=ml1[i];}}
   ml2[15]=440;
   i=0;
   for(col=95;col<=570;col=col+25,i++){
     line(col,40,col,440);
     if(col<570){
	mc1[i]=col;
	if(i>0)
	   mc2[i-1]=mc1[i];}}
   mc2[18]=570;
   mouse();
   while(!(kbhit())){
	stant=sta;
	lin=(linmouse()*8);
	col=(colmouse()*8);
	sta=status();
      if(lin>40 && lin<440){
	for(i=0;lin>ml1[i] ^ lin<ml2[i];i++);}
      if(col>95 && col<570 && col!=320 && col!=120 && col!=520){
	for(j=0;col>mc1[j] ^ col<mc2[j];j++);}
      if(lin>=ml1[i] && lin<=ml2[i] && col>=mc1[j] && col<=mc2[j] ){
	    if(stant==0 && sta==1){
	      desliga();
	      bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);
	    /*if(mt[j][i]==0)
	      botao(mc1[j]+4,ml1[i]+4,mc2[j]-3,ml2[i]-4,0);
	    else
	      botao(mc1[j]+4,ml1[i]+4,mc2[j]-3,ml2[i]-4,1);*/
	      mouse();
	      mt[j][i]=1;}
	    else if(stant==0 && sta==2){
		 setfillstyle( SOLID_FILL,0);
		 desliga();
		 bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);
		 mouse();
		 mt[j][i]=0;
		 setfillstyle( SOLID_FILL,15);}}

   }
   desliga();
   cleardevice();
   salva();
   cleardevice();
   sta=0;
   flushall();
   /*while(!(kbhit())){
      mudamouse(_DS,(unsigned) dorme1.imag,7,7);
      mouse();
      delay(500);
      mudamouse(_DS,(unsigned) dorme2.imag,7,7);
      mouse();
      delay(500);}*/
   closegraph();
   return 0;
}
char escreve(void)
{
      if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==1)
	      return 'f';
	   else if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==0)
	      return 'e';
	      else if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==1)
		return 'd';
		else if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==0)
		       return 'c';
		    else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==1)
			    return 'b';
			 else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==0)
				return 'a';
			       else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==1)
					return '9';
				     else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==0)
					     return '8';
					   else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==1)
						    return '7';
						else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==0)
							 return '6';
						     else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==1)
							    return '5';
							  else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==0)
								  return '4';
							       else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==1)
									return '3';
								    else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==0)
									     return '2';
									 else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==1)
										 return '1';
									      else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==0)
										       return '0';
}
