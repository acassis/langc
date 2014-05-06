int card8 [16] [19];
int dorme1 [16][19];
int dorme2 [16][19];
int alan [16][19];
int doente [16] [19];
#include <graphics.h>
#include <grafico.h>
#include <stdlib.h>
#include <stdio.h>
#include "bicho.h"
int mt[19] [16],i=0,j;
void salva(void)
{  FILE *s,*p;
   char nome[30],ch;
   printf("\nDigite o nome do cursor:");
   flushall();
   gets(nome);
   if(nome[0]>=65){
   if ((s=fopen("bicho.h","r+"))==NULL)
   {  printf("\nArquivo nao pode ser criado.");
      return; }
   fseek(s, 0, SEEK_SET);
   if ((p=fopen("edibicho.c","r+"))==NULL)
   {  printf("\nArquivo nao pode ser criado.");
      return; }
   fseek(p, 0, SEEK_SET);
   fprintf(p,"int %s [16] [19];",nome);
   ch='s';
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
   int gdriver = DETECT , gmode;
   int lin,col,sta,stant,ml1[16],ml2[16],mc1[19],mc2[19],x,i,j;
   i=0;j=0;
   clrscr();
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   for(i=0;i<16;i++)
     for(j=0;j<19;j++)
	mt[j] [i] = card5[i] [j];
   i=0;j=0;

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

   for(i=0;i<16;i++)
    for(j=0;j<19;j++)
   {
	if(card5[i][j]==1)
	bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);
   }
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
   closegraph();
   return 0;
}
