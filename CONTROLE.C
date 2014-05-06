//----------------------------------------------------------------------------
//Programa: Controle.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao:Este programa foi usado na feira tecnica da minha escola, ele serve
//para controlar um carrinho de controle remoto.
//Voce deve substituir os interruptores do controle remoto por chaves digitais
//CI-4066, ligadas `a porta paralela!
//-----------------------------------------------------------------------------
#include <math.h>
#include <dos.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80

void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx);

  }
int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx);
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
char chaves[]="0000";
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
      bar(col-36,lin-31,col+36,lin+31);

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
      bar(col-36,lin-31,col+36,lin+31);

      setfillstyle(1,6);
      pieslice(col,lin,0,360,4);


      setfillstyle(1,8);
      fillpoly(4, p);
      pieslice(col,lin-25,0,180,6);
}

void botao2(int col,int lin)
{
      int p[8];
      p[6]=col;
      p[7]=lin-1;

      p[4]=col;
      p[5]=lin+1;

      p[2]=col+27;
      p[3]=lin+6;

      p[0]=col+27;
      p[1]=lin-6;

      setfillstyle(1,0);
      bar(col-33,lin-31,col+33,lin+31);

      setcolor(6);
      setfillstyle(1,6);
      pieslice(col,lin,0,360,4);

      setcolor(15);
      setfillstyle(1,8);
      fillpoly(4, p);
      pieslice(col+27,lin,270,360,6);
      pieslice(col+27,lin,0,90,6);
      setcolor(8);
      line(col+28,lin,col+32,lin);
      setcolor(15);
}

void botao3(int col,int lin)
{
      int p[8];
      p[6]=col;
      p[7]=lin-1;

      p[4]=col;
      p[5]=lin+1;

      p[2]=col-27;
      p[3]=lin+6;

      p[0]=col-27;
      p[1]=lin-6;

      setfillstyle(1,0);
      bar(col-33,lin-31,col+33,lin+31);

      setcolor(6);
      setfillstyle(1,6);
      pieslice(col,lin,0,360,4);

      setcolor(15);
      setfillstyle(1,8);
      fillpoly(4, p);
      pieslice(col-27,lin,270,90,6);
}

void numera()
{
    rectangle(0,0,639,479);
    rectangle(240,130,362,330);
    rectangle(271,150,331,170);
    line(301,150,301,170);
    line(301,30,301,130);
    pieslice(301,30,0,360,4);
    botao1(302,240);
    circle(301,240,50);
    outtextxy(305,157,"Des");
    setcolor(2);
    outtextxy(299,280,"T");
    outtextxy(299,195,"F");
    outtextxy(342,237,"D");
    outtextxy(255,237,"E");
    setcolor(8);
    outtextxy(275,157,"Lig");
    setcolor(15);
}

void ligado()
{
      setcolor(8);
      outtextxy(305,157,"Des");
      setcolor(15);
      outtextxy(275,157,"Lig");
      strcpy(chaves,"10000000");
}

void teste(int lin,int col,int sta,int stant,char tecla)
{
    if(lin>190 && lin<240 && col>287 && col<309 && stant==0 && sta==1 || tecla==SETA_SOBE)
     {
      desliga();
      ligado();
      botao1(302,240);
      strcpy(chaves,"1000");
      tecla=0;
      mouse();
     }
    if(lin>241 && lin<305 && col>287 && col<309 && stant==0 && sta==1 || tecla==SETA_DESCE)
     {
      desliga();
      ligado();
      botao0(302,240);
      strcpy(chaves,"0100");
      mouse();
     }

    if(lin>230 && lin<245 && col>237 && col<300 && stant==0 && sta==1 || tecla==SETA_ESQ)
     {
      desliga();
      ligado();
      botao3(302,240);
      strcpy(chaves,"1010");
      mouse();
     }
    if(lin>230 && lin<245 && col>301 && col<359 && stant==0 && sta==1 || tecla==SETA_DIR)
     {
      desliga();
      ligado();
      botao2(302,240);
      strcpy(chaves,"1001");
      mouse();
     }

}
int controle()
{
  int acum=0,i;
  for(i=0;i<4;i++)
       acum=acum+(chaves[i]-48)*(pow(2,3-i));
  return acum+128;

}
void main()
{
    int drive=DETECT,modo,lin,col,sta,stant;
    char tecla;
    initgraph(&drive,&modo,"C:\\bc\\bgi");
    numera();
    mouse();
while(1){
    col=colmouse();
    lin=linmouse();
    sta=status();
  if(kbhit()){
    tecla=getch();
    if(tecla==27)
      exit(1);}
    if( (chaves[0]=='1' && tecla==SETA_SOBE) && !(chaves[2]=='1' || chaves[3]=='1') )
      tecla=0;
    if(chaves[1]=='1' && tecla==SETA_DESCE)
      tecla=0;
    if(chaves[2]=='1' && tecla==SETA_ESQ)
      tecla=0;
    if(chaves[3]=='1' && tecla==SETA_DIR)
      tecla=0;
    if(tecla==' ') {
      strcpy(chaves,"0000");
      desliga();
      setcolor(15);
      outtextxy(305,157,"Des");
      setcolor(8);
      outtextxy(275,157,"Lig");
      setcolor(15);
      botao1(302,240);
      mouse();
      tecla=0;}
    if(col>271 && col<301 && lin>150 && lin<170 && sta==1 && stant==0){
      desliga();
      setcolor(8);
      outtextxy(305,157,"Des");
      setcolor(15);
      outtextxy(275,157,"Lig");
      strcpy(chaves,"10000000");
      botao1(302,240);
      mouse();
      tecla=0;}
    if(col>301 && col<331 && lin>150 && lin<170 && sta==1 && stant==0){
      desliga();
      setcolor(8);
      outtextxy(275,157,"Lig");
      setcolor(15);
      outtextxy(305,157,"Des");
      strcpy(chaves,"00000000");
      botao1(302,240);
      mouse();}
    teste(lin,col,sta,stant,tecla);
    outportb(0x378,controle());
    stant=sta;
    }
    closegraph();
}