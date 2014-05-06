//----------------------------------------------------------------------------
//Programa: Relogio.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao:Exibi um relogio com os ponteiros de horas,minutos e segundos
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#define	PI  3.14159265358979323846 //constante pi

float seno(int ang) //Calcula o seno recebendo como argumento o angulo em vez de radiano
{
  return sin(ang*PI/180);
}

float coseno(int ang) //Calcula o coseno recebendo como argumento o angulo em vez de radiano
{
  return cos(ang*PI/180);
}
int hora,minu,segu,seguant;
struct  time t;
void main()
{
      int gdriver = DETECT, gmode;
      float ang=0,xsegu=0,ysegu=0,xseguant,yseguant,xminu,yminu,xminuant,
	    yminuant,xhora=0,yhora=0,xhoraant,yhoraant,raio=100;
      char tempo[9];
      initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
      circle(320,240,110);
      for(segu=0;segu<60;segu++)
      {
	ang = segu * 6;
	xsegu = coseno(ang) * 110;
	ysegu = seno(ang) * 110;
	setcolor(15);
	line(320,240,320+xsegu,240+ysegu);
      }
      setcolor(0);
      setfillstyle(1,0);
      fillellipse(320,240,105,105);
      setcolor(15);
      outtextxy(310,120,"12");
      outtextxy(317,355,"6");
      outtextxy(200,235,"9");
      outtextxy(434,235,"3");
      outtextxy(374,133,"1");
      outtextxy(419,175,"2");
      outtextxy(419,293,"4");
      outtextxy(378,340,"5");
      outtextxy(260,342,"7");
      outtextxy(215,298,"8");
      outtextxy(206,179,"10");
      outtextxy(250,134,"11");
      while(!kbhit())
      {
       gettime(&t);
       hora = t.ti_hour;
       minu=t.ti_min;
       segu=t.ti_sec;

       ang = segu * 6 - 90;
       xsegu = coseno(ang) * raio;
       ysegu = seno(ang) * raio;
       setcolor(15);
       line(320,240,320+xsegu,240+ysegu);
       sprintf(tempo, "%02d:%02d:%02d",hora,minu,segu);

       ang = minu * 6 - 90;
       xminu = coseno(ang) * (raio - 10);
       yminu = seno(ang) * (raio - 10);
       setcolor(9);
       line(320,240,320+xminu,240+yminu);

       ang = ( (hora * 30) + (6 * (minu/12)) ) - 90;
       xhora = coseno(ang) * (raio - 20);
       yhora = seno(ang) * (raio - 20);
       setcolor(2);
       line(320,240,320+xhora,240+yhora);
       if(seguant != segu){
	 setcolor(0);
	 line(320,240,320+xhoraant,240+yhoraant);
	 line(320,240,320+xseguant,240+yseguant);
	 line(320,240,320+xminuant,240+yminuant);
	 outtextxy(290,410,"лллллллллллл");
	 setcolor(15);
	 outtextxy(290,410,tempo);
	}
       seguant = segu;
       xseguant = xsegu;
       yseguant = ysegu;
       xminuant = xminu;
       yminuant = yminu;
       xhoraant = xhora;
       yhoraant = yhora;
      }
      closegraph();
}
