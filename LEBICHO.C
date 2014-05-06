#include <graphics.h>
#include <grafico.h>
#include "bicho.h"
int dorme1 [16][19];
int dorme2 [16][19];
int alan [16][19];
int main(void)
{
   int gdriver = DETECT , gmode;
   int lin,col,sta,stant,ml1[16],ml2[16],mc1[19],mc2[19],x,i,j;
   i=0;j=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   ml2[0]=65;
   for(lin=40;lin<=440;lin+=25,i++){
      if(lin<440){
	 ml1[i]=lin;
	 if(i>0)
	   ml2[i-1]=ml1[i];}}
   ml2[15]=440;
   i=0;
   for(col=95;col<=570;col=col+25,i++){
     if(col<570){
	mc1[i]=col;
	if(i>0)
	   mc2[i-1]=mc1[i];}}
   mc2[18]=570;
  while(!kbhit()){
   for(i=0;i<16;i++)
    for(j=0;j<19;j++)
   {
	if(dorme1[i][j]==1){
		setfillstyle( SOLID_FILL, 15 );
		bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);}
	else {
	setfillstyle( SOLID_FILL, 0 );
	bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);}
   }
   delay(500);
   for(i=0;i<16;i++)
    for(j=0;j<19;j++)
   {
	if(dorme2[i][j]==1){
	   setfillstyle( SOLID_FILL, 15 );
	   bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);}
	else{
	setfillstyle( SOLID_FILL, 0 );
	bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);}
   }
  delay(500);
  }
   getch();
   closegraph();
   return 0;
}
