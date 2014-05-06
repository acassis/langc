#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include <grafico.h>
char m1[]="   ",m2[]="   ",m3[]="   ",n1[12],n2[12],mt[3][3];
int lin,col;
char camp='N',resp='s',re='s';
int lx,cx,lo,co,ct=0,sta,confct,i,j,pos=0;
int gdriver = DETECT, gmode,lin=40,col=16,stant,ml1[3],ml2[3],mc1[3],mc2[3];
void lemouse();
void main(void)
{
  printf("\nInforme o nome do jogador X: ");
  gets(n1);
  printf("\nInforme o nome do jogador O: ");
  gets(n2);
  initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
  for(lin=160;lin<=340;lin=lin+60,i++){
      line(230,lin,410,lin);
      if(lin<340){
	 ml1[i]=lin;
	 if(i>0)
	   ml2[i-1]=ml1[i];}}
   ml2[2]=340;
   i=0;
   for(col=230;col<=410;col=col+60,i++){
     line(col,160,col,340);
     if(col<410){
	mc1[i]=col;
	if(i>0)
	   mc2[i-1]=mc1[i];}}
   mc2[2]=410;
   mouse();
 while(re=='s'|| re=='S')
 {
      ct=0;
      resp='s';
      camp='N';
  while(ct<9 && resp=='s')
   {


      if (ct%2==0)
      {
	/*volta*/
	printf("Jogador %s clique na posicÆo desejada",n1);
	while(pos==0)
	 {
	   lemouse();
	 }
	 pos=0;
      }
      if(ct%2!=0)
      {
       /*volta*/
       printf("Jogador %s clique na posicÆo desejada",n2);
       while(pos==0)
	{
	   lemouse();
	}
	pos=0;
      }
   }
	re='n';
	if(camp=='N')
	   puts("\nNÆo houve vencedor!");
	else
	   if(camp=='X')
	      printf("\nO vencedor ‚ %s",n1);
	   else if(camp=='O')
	      printf("\nO vencedor ‚ %s",n2);
	getch();
	gotoxy(1,22);
	puts("jogar outro(s/n)");
	re=getche();
      }
}


    /*	confct=1;
	sta=0;
	printf("%c",m1[0]);
	gotoxy(41,10);
	printf("%c",m1[1]);
	gotoxy(45,10);
	printf("%c",m1[2]);
	gotoxy(37,12);
	printf("%c",m2[0]);
	gotoxy(41,12);
	printf("%c",m2[1]);
	gotoxy(45,12);
	printf("%c",m2[2]);
	gotoxy(37,14);
	printf("%c",m3[0]);
	gotoxy(41,14);
	printf("%c",m3[1]);
	gotoxy(45,14);
	printf("%c",m3[2]);
	gotoxy(1,20);*/
void lemouse()
{
      stant=sta;
      lin=linmouse()*8;
      col=colmouse()*8;
      if(lin>160 && lin<340){
	for(i=0;lin>ml1[i] ^ lin<ml2[i];i++);}
      if(col>230 && col<410 && col!=320){
	for(j=0;col>mc1[j] ^ col<mc2[j];j++);}
      if(lin>=ml1[i] && lin<=ml2[i] && col>=mc1[j] && col<=mc2[j] ){
	     if(stant==0 && sta==1){
	      desliga();
	     /*if(m1[j]==' '){*/
	      botao(mc1[j]+4,ml1[i]+4,mc2[j]-3,ml2[i]-4,1);
	      mt[j][i]=1;
	      pos=1;
	      if(i==0)
		m1[j]='X';
	      else if(i==1)
		m2[j]='X';
		else if(i==2)
		 m3[j]='X';}
	     mouse();
	     mt[j][i]=1;/*}
	    else*/ if(stant==0 && sta==2){
		 setfillstyle( SOLID_FILL,0);
		 desliga();
		 bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);
		 mouse();
		 mt[j][i]=0;
		 setfillstyle( SOLID_FILL,15);}

       }

}
