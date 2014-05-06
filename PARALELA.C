#include <math.h>
#include<graphics.h>
#include<grafico.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
div_t x;
char chaves[]="00000000";
void botao0(int col,int lin)
{
      int p[8];
      p[0]=col+1;
      p[1]=lin;

      p[2]=col-1;
      p[3]=lin;

      p[4]=col-6;
      p[5]=lin+25;

      p[6]=col+6;
      p[7]=lin+25;

      setfillstyle(1,0);
      bar(col-7,lin-31,col+7,lin+31);

      setfillstyle(1,6);
      pieslice(col,lin,0,360,4);

      setfillstyle(1,8);
      fillpoly(4, p);
      pieslice(col,lin+25,180,360,6);
}

void botao1(int col,int lin)
{
      int p[8];
      p[6]=col+1;
      p[7]=lin;

      p[4]=col-1;
      p[5]=lin;

      p[2]=col-6;
      p[3]=lin-25;

      p[0]=col+6;
      p[1]=lin-25;

      setfillstyle(1,0);
      bar(col-7,lin-31,col+7,lin+31);

      setfillstyle(1,6);
      pieslice(col,lin,0,360,4);


      setfillstyle(1,8);
      fillpoly(4, p);
      pieslice(col,lin-25,0,180,6);
}

void numera()
{
    rectangle(0,0,639,479);
    rectangle(210,170,412,310);
    rectangle(190,310,432,340);
    botao0(232,240);
    botao0(256,240);
    botao0(279,240);
    botao0(302,240);
    botao0(325,240);
    botao0(348,240);
    botao0(371,240);
    botao0(394,240);

    outtextxy(229,280,"0");
    outtextxy(253,280,"0");
    outtextxy(276,280,"0");
    outtextxy(299,280,"0");
    outtextxy(322,280,"0");
    outtextxy(345,280,"0");
    outtextxy(369,280,"0");
    outtextxy(391,280,"0");

    outtextxy(229,195,"1");
    outtextxy(253,195,"1");
    outtextxy(276,195,"1");
    outtextxy(299,195,"1");
    outtextxy(322,195,"1");
    outtextxy(345,195,"1");
    outtextxy(369,195,"1");
    outtextxy(391,195,"1");

}
void teste(int lin,int col,int sta,int stant)
{

    if(lin>195 && lin<440 && col>219 && col<238 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[0]=='0'){
	 botao1(232,240);
	 chaves[0]='1';}
      else{
	 botao0(232,240);
	 chaves[0]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>240 && col<262 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[1]=='0'){
	 botao1(256,240);
	 chaves[1]='1';}
      else{
	 botao0(256,240);
	 chaves[1]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>263 && col<286 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[2]=='0'){
	 botao1(279,240);
	 chaves[2]='1';}
      else{
	 botao0(279,240);
	 chaves[2]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>287 && col<309 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[3]=='0'){
	 botao1(302,240);
	 chaves[3]='1';}
      else{
	 botao0(302,240);
	 chaves[3]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>310 && col<332 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[4]=='0'){
	 botao1(325,240);
	 chaves[4]='1';}
      else{
	 botao0(325,240);
	 chaves[4]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>333 && col<355 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[5]=='0'){
	 botao1(348,240);
	 chaves[5]='1';}
      else{
	 botao0(348,240);
	 chaves[5]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>356 && col<378 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[6]=='0'){
	 botao1(371,240);
	 chaves[6]='1';}
      else{
	 botao0(371,240);
	 chaves[6]='0';}
      mouse();
     }
    if(lin>195 && lin<440 && col>379 && col<401 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[7]=='0'){
	 botao1(394,240);
	 chaves[7]='1';}
      else{
	 botao0(394,240);
	 chaves[7]='0';}
      mouse();
     }
}
int controle()
{
  int acum=0,i;
  for(i=0;i<8;i++)
       acum=acum+(chaves[i]-48)*(pow(2,7-i));
  return acum;

}
void main()
{
    int drive=DETECT,modo,lin,col,sta,stant;
    initgraph(&drive,&modo,"");
    numera();
    mouse();
while(!kbhit()){
    col=colmouse()*8;
    lin=linmouse()*8;
    sta=status();
    teste(lin,col,sta,stant);
  if(sta==1 && stant==0){
    outportb(0x378,controle());
    gotoxy(29,21);
    printf("%c  %c  %c  %c  %c  %c  %c  %c",chaves[0],chaves[1],chaves[2],chaves[3],chaves[4],chaves[5],chaves[6],chaves[7]);
    }
    stant=sta;
    }
    closegraph();
}