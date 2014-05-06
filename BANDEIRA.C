//----------------------------------------------------------------------------
//Programa: Bandeira.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao:Exibi a bandeira do Brasil, faltam as estrelas ;-(
//-----------------------------------------------------------------------------
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void esperetracovertical( void )
{

  while( inp( 0x3da ) & 8 );

  while( !(inp( 0x3da ) & 8) );

}



void estrela(int x1,int y1,int raio)
{
   int x,y,col,lin,i;
   float ang,ra;
   x = cos(ang) * raio;
   y = sin(ang) * raio;
   setcolor(15);
   for(ra=0;ra<raio;ra+=0.5)
    {
     ang = 0.95;
     for(i=0;i<5;i++)
     {
      ang += 2.51;
      col = cos(ang) * ra;
      lin = sin(ang) * ra;
      line(x+x1,y+y1,col+x1,lin+y1);
      x=col;
      y=lin;
     }
    }
}

int main(void)
{
   int gdriver = DETECT, gmode,p[8],ct,col=320,lin=240;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   setfillstyle( SOLID_FILL, 2 );
   bar(20,10,620,470);
   setcolor(14);
   setfillstyle( SOLID_FILL, 14 );
   p[0]=30;p[1]=240;p[2]=320;p[3]=20;
   p[4]=610;p[5]=240;p[6]=320;p[7]=460;
   fillpoly(4, p);
   setfillstyle( SOLID_FILL, 1 );
   fillellipse(320,240,120,120);
   setcolor(15);
   arc(320,480,61,119,240);
   arc(320,480,61,119,241);
   arc(320,480,61,119,242);
   arc(320,480,61,119,243);
   arc(320,480,61,119,244);
   arc(320,480,61,119,245);
   arc(320,480,61,119,246);
   arc(320,480,61,119,246);
   arc(320,480,61,119,247);
   arc(320,480,61,119,248);
   arc(320,480,62,118,249);
   arc(320,480,62,118,250);
   arc(320,480,62,118,251);
   arc(320,480,62,118,252);
   arc(320,480,62,118,253);
   arc(320,480,62,118,254);
   arc(320,480,62,118,255);
   arc(320,480,62,118,256);
   arc(320,480,63,117,257);
   arc(320,480,63,117,258);
   setcolor(0);
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   outtextxy(210,242,"O");
   outtextxy(222,236,"R");
   outtextxy(234,231,"D");
   outtextxy(246,227,"E");
   outtextxy(258,223,"M");
   outtextxy(290,220,"E");
   outtextxy(322,218,"P");
   outtextxy(334,220,"R");
   outtextxy(347,221,"O");
   outtextxy(359,223,"G");
   outtextxy(371,225,"R");
   outtextxy(383,227,"E");
   outtextxy(395,231,"S");
   outtextxy(407,235,"S");
   outtextxy(419,240,"O");
   setwritemode( XOR_PUT );
   setcolor(15);
   while(!kbhit())
   {
     ct = random(4);
     if(ct==0)
	col++;
     if(ct==1)
	col--;
     if(ct==2)
	lin++;
     if(ct==3)
	lin--;
     //rectangle(col,lin,col+30,lin+30);
     //esperetracovertical();
     //rectangle(col,lin,col+30,lin+30);
   }
   getch();
   closegraph();
   return 0;
}