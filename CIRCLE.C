//----------------------------------------------------------------------------
//Programa: Circle.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Cria um efeito com circulos!
//-----------------------------------------------------------------------------
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
void main ()
{
  int drive=DETECT,modo,col,lin,ra,cor,ct=0,mh[500],mv[500],cot=0,tam[500];
  initgraph(&drive,&modo,"c:\\bc\\bgi");
  while(!kbhit()){
   for(ct=0;ct<200;ct++){
     lin=random(480);
     col=random(640);
     ra=random(25);
     cor=random(15)+1;
     mv[ct]=lin;
     mh[ct]=col;
     tam[ct]=ra;
     setcolor(cor);
     circle(col,lin,ra);
     delay(1);
     mh[ct]=col;
     mv[ct]=lin;
     }
     setcolor(0);
     for(;ct>=0;ct--){
     circle(mh[ct],mv[ct],tam[ct]);
       delay(20);}
     delay(200);
     }
     closegraph();

}

