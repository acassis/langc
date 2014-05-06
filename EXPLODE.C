//----------------------------------------------------------------------------
//Programa: Explode.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Cria um efeito semelhante a explosao de fogos de artificio.
//-----------------------------------------------------------------------------
#include<dos.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
void main()
{
    float ang=160,ang2=0,x=0,y=0,r1=1,r2=2;
    int gdriver = DETECT, gmode;
    int cor1=4,cor2=1,cor3=7,cor4=8,posx1,posy1,posx2,posy2,posx3,posy3,posx4,posy4;
    initgraph(&gdriver, &gmode, "c:\\bc\\bgi");

    while(!kbhit())
    {
	ang +=0.4;
	x = cos(ang) * r1;
	y = sin(ang) * r1;
	cor1 = getpixel(posx1+x,posy1+y);
	cor2 = getpixel(posx2+x,posy2+y);
	cor3 = getpixel(posx3+x,posy3+y);
	cor4 = getpixel(posx4+x,posy4+y);
       for(ang2=0;ang2<6.5;ang2+=0.1)
       {
	 x = cos(ang2) * r2;
	 y = sin(ang2) * r2;
	 putpixel(posx1 + y*(cos(y)),posy1 + x*(cos(y)),cor1);
	 putpixel(posx2 + y*(cos(y)),posy2 + x*(cos(y)),cor2);
	 putpixel(posx3 + y*(cos(y)),posy3 + x*(cos(y)),cor3);
	 putpixel(posx4 + y*(cos(y)),posy4 + x*(cos(y)),cor4);
       }
	r1+=0.2;
	r2+=0.4;
	if(ang>150)
	 {
	   cleardevice();
	   posx1 = random(580) + 30;
	   posy1 = random(420) + 30;
	   cor1  = random(15)+1;
	   setcolor(cor1);
	   setfillstyle( SOLID_FILL, cor1);
	   putpixel(posx1,posy1,cor1);

	   posx2 = random(580) + 30;
	   posy2 = random(420) + 30;
	   cor2  = random(15)+1;
	   setcolor(cor2);
	   setfillstyle( SOLID_FILL, cor2);
	   putpixel(posx2,posy2,cor2);

	   posx3 = random(580) + 30;
	   posy3 = random(420) + 30;
	   cor3  = random(15)+1;
	   setcolor(cor3);
	   setfillstyle( SOLID_FILL, cor3);
	   putpixel(posx3,posy3,cor3);

	   posx4 = random(580) + 30;
	   posy4 = random(420) + 30;
	   cor4  = random(15)+1;
	   setcolor(cor4);
	   setfillstyle( SOLID_FILL, cor4);
	   putpixel(posx4,posy4,cor4);

	   r1=1;
	   r2=2;
	   ang = 0;
	 }
    }
    closegraph();
}