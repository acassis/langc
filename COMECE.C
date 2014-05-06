//----------------------------------------------------------------------------
//Programa: Comece.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Este programa comeceu a ser desenvolvido para controlar um PLC da
//escola, mas ficou inacabado faltando o protocolo de comunicacao!
//-----------------------------------------------------------------------------
#include <math.h>
#include <dos.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
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
int status(void)
{
     union REGS regs;
     regs.x.ax=3;
     int86(0x33,&regs,&regs);
     return(regs.x.bx);
}
void desliga (void)
{
union REGS regs;
      regs.x.ax=2;
      int86(0x33,&regs,&regs);
}

div_t x;
char chaves[]="0000000000000000";
void apaga(int oct)
{
   setfillstyle(1,7);
//---------OCTETO 0---------------------------------------------------------
if(oct==0){
   fillellipse(92,100,10,10);
   fillellipse(116,100,10,10);
   fillellipse(139,100,10,10);
   fillellipse(162,100,10,10);
   fillellipse(185,100,10,10);
   fillellipse(208,100,10,10);
   fillellipse(231,100,10,10);
   fillellipse(254,100,10,10);}
//---------OCTETO 1----------------------------------------------------------
else{
   fillellipse(547,100,10,10);
   fillellipse(524,100,10,10);
   fillellipse(501,100,10,10);
   fillellipse(478,100,10,10);
   fillellipse(455,100,10,10);
   fillellipse(432,100,10,10);
   fillellipse(409,100,10,10);
   fillellipse(386,100,10,10);}

};
void mostra(int oct,int val)
{
   char led[]="00000000";
   int i=7;
   apaga(oct);
   if(val==1)
      led[7]='1';
if(val>1)
 while(1)
 {
   x=div(val,2);
   led[i]=x.rem+48;
   i--;
   if(x.quot==1){
      led[i]=x.quot+48;
      break;}
   val=x.quot;
   gotoxy(40,12);
 }
setfillstyle(1,4);
//---------OCTETO 0---------------------------------------------------------
if(oct==0)
{
  if(led[0]=='1')
     fillellipse(92,100,10,10);
  if(led[1]=='1')
     fillellipse(116,100,10,10);
  if(led[2]=='1')
     fillellipse(139,100,10,10);
  if(led[3]=='1')
     fillellipse(162,100,10,10);
  if(led[4]=='1')
     fillellipse(185,100,10,10);
  if(led[5]=='1')
     fillellipse(208,100,10,10);
  if(led[6]=='1')
     fillellipse(231,100,10,10);
  if(led[7]=='1')
     fillellipse(254,100,10,10);
}
//---------OCTETO 1----------------------------------------------------------
if(oct==1)
{
  if(led[7]=='1')
     fillellipse(547,100,10,10);
  if(led[6]=='1')
     fillellipse(524,100,10,10);
  if(led[5]=='1')
     fillellipse(501,100,10,10);
  if(led[4]=='1')
     fillellipse(478,100,10,10);
  if(led[3]=='1')
     fillellipse(455,100,10,10);
  if(led[2]=='1')
     fillellipse(432,100,10,10);
  if(led[1]=='1')
     fillellipse(409,100,10,10);
  if(led[0]=='1')
     fillellipse(386,100,10,10);
 }

};

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
    rectangle(0,310,639,340);
    line(320,310,320,479);
    botao0(92,400);
    botao0(116,400);
    botao0(139,400);
    botao0(162,400);
    botao0(185,400);
    botao0(208,400);
    botao0(231,400);
    botao0(254,400);

    botao0(386,400);
    botao0(409,400);
    botao0(432,400);
    botao0(455,400);
    botao0(478,400);
    botao0(501,400);
    botao0(524,400);
    botao0(547,400);

    outtextxy(89,440,"0");
    outtextxy(113,440,"0");
    outtextxy(136,440,"0");
    outtextxy(159,440,"0");
    outtextxy(182,440,"0");
    outtextxy(205,440,"0");
    outtextxy(229,440,"0");
    outtextxy(251,440,"0");
    outtextxy(383,440,"0");
    outtextxy(406,440,"0");
    outtextxy(429,440,"0");
    outtextxy(452,440,"0");
    outtextxy(475,440,"0");
    outtextxy(499,440,"0");
    outtextxy(521,440,"0");
    outtextxy(543,440,"0");

    outtextxy(89,355,"1");
    outtextxy(113,355,"1");
    outtextxy(136,355,"1");
    outtextxy(159,355,"1");
    outtextxy(182,355,"1");
    outtextxy(205,355,"1");
    outtextxy(229,355,"1");
    outtextxy(251,355,"1");
    outtextxy(383,355,"1");
    outtextxy(406,355,"1");
    outtextxy(429,355,"1");
    outtextxy(452,355,"1");
    outtextxy(475,355,"1");
    outtextxy(499,355,"1");
    outtextxy(521,355,"1");
    outtextxy(543,355,"1");

}
void teste(int lin,int col,int sta,int stant)
{

    if(lin>355 && lin<440 && col>79 && col<98 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[0]=='0'){
	 botao1(92,400);
	 chaves[0]='1';}
      else{
	 botao0(92,400);
	 chaves[0]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>100 && col<122 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[1]=='0'){
	 botao1(116,400);
	 chaves[1]='1';}
      else{
	 botao0(116,400);
	 chaves[1]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>121 && col<146 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[2]=='0'){
	 botao1(139,400);
	 chaves[2]='1';}
      else{
	 botao0(139,400);
	 chaves[2]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>147 && col<169 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[3]=='0'){
	 botao1(162,400);
	 chaves[3]='1';}
      else{
	 botao0(162,400);
	 chaves[3]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>170 && col<192 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[4]=='0'){
	 botao1(185,400);
	 chaves[4]='1';}
      else{
	 botao0(185,400);
	 chaves[4]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>193 && col<215 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[5]=='0'){
	 botao1(208,400);
	 chaves[5]='1';}
      else{
	 botao0(208,400);
	 chaves[5]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>216 && col<238 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[6]=='0'){
	 botao1(231,400);
	 chaves[6]='1';}
      else{
	 botao0(231,400);
	 chaves[6]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>239 && col<261 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[7]=='0'){
	 botao1(254,400);
	 chaves[7]='1';}
      else{
	 botao0(254,400);
	 chaves[7]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>371 && col<393 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[8]=='0'){
	 botao1(386,400);
	 chaves[8]='1';}
      else{
	 botao0(386,400);
	 chaves[8]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>394 && col<416 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[9]=='0'){
	 botao1(409,400);
	 chaves[9]='1';}
      else{
	 botao0(409,400);
	 chaves[9]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>417 && col<439 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[10]=='0'){
	 botao1(432,400);
	 chaves[10]='1';}
      else{
	 botao0(432,400);
	 chaves[10]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>440 && col<462 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[11]=='0'){
	 botao1(455,400);
	 chaves[11]='1';}
      else{
	 botao0(455,400);
	 chaves[11]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>463 && col<485 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[12]=='0'){
	 botao1(478,400);
	 chaves[12]='1';}
      else{
	 botao0(478,400);
	 chaves[12]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>486 && col<508 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[13]=='0'){
	 botao1(501,400);
	 chaves[13]='1';}
      else{
	 botao0(501,400);
	 chaves[13]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>509 && col<531 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[14]=='0'){
	 botao1(524,400);
	 chaves[14]='1';}
      else{
	 botao0(524,400);
	 chaves[14]='0';}
      mouse();
     }
    if(lin>355 && lin<440 && col>532 && col<554 && stant==0 && sta==1)
     {
      desliga();
      if(chaves[15]=='0'){
	 botao1(547,400);
	 chaves[15]='1';}
      else{
	 botao0(547,400);
	 chaves[15]='0';}
      mouse();
     }
}
int controle(int oct)
{
  int acum=0,i;

  if(oct==0)
    for(i=0;i<8;i++)
       acum=acum+(chaves[i]-48)*(pow(2,7-i));
  else
    for(i=8;i<16;i++)
       acum=acum+(chaves[i]-48)*(pow(2,15-i));
  return acum;

}
void main()
{
    int drive=DETECT,modo,lin,col,sta,stant;
    initgraph(&drive,&modo,"c:\\bc\\bgi");
    apaga(0);
    apaga(1);
    numera();
    mouse();
while(!kbhit()){
    col=colmouse()*8;
    lin=linmouse()*8;
    sta=status();
    teste(lin,col,sta,stant);
  if(sta==1 && stant==0){
    mostra(0,controle(0));
    mostra(1,controle(1));
    gotoxy(37,21);
    printf("    ");
    gotoxy(12,21);
    printf("%c  %c  %c  %c  %c  %c  %c  %c => %d",chaves[0],chaves[1],chaves[2],chaves[3],chaves[4],chaves[5],chaves[6],chaves[7],controle(0));
    gotoxy(49,21);
    printf("%c  %c  %c  %c  %c  %c  %c  %c => %d  ",chaves[8],chaves[9],chaves[10],chaves[11],chaves[12],chaves[13],chaves[14],chaves[15],controle(1));
    }
    stant=sta;
    }
    closegraph();
}