#include <graphics.h>
#include <grafico.h>
#include <stdio.h>
#include<conio.h>
#include "let.h"
char escreve(void);
char m[]="0xffff";
int mt[3] [3],i=0,j;
int main(void)
{
   int gdriver = DETECT, gmode,lin=40,col=16,sta,stant,ml1[4],ml2[4],mc1[4],mc2[4];
   for(j=0;j<3;j++)
     for(i=0;i<3;i++)
	mt[j] [i]=0;
   i=0;j=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   for(lin=40;lin<=440;lin=lin+25,i++){
      line(120,lin,520,lin);
      if(lin<440){
	 ml1[i]=lin;
	 if(i>0)
	   ml2[i-1]=ml1[i];}}
   ml2[15]=440;
   i=0;
   for(col=120;col<=520;col=col+25,i++){
     line(col,40,col,440);
     if(col<520){
	mc1[i]=col;
	if(i>0)
	   mc2[i-1]=mc1[i];}}
   mc2[15]=520;
   mouse();
   while(!(kbhit())){
	stant=sta;
	lin=(linmouse()*8);
	col=(colmouse()*8);
	sta=status();
      if(lin>40 && lin<440){
	for(i=0;lin>ml1[i] ^ lin<ml2[i];i++);}
      if(col>120 && col<520 && col!=320){
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
   closegraph();
   return 0;
}