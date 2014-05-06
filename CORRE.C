//----------------------------------------------------------------------------
//Programa: Corre.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Este programa simula uma simples perseguicao, corra pra ver o que
//acontece!
//-----------------------------------------------------------------------------

#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80

#include <stdio.h>
#include <graphics.h>

unsigned int far *clock = (unsigned int far *)0x0000046C; // ponteiro para clock
							  // interno 18.2 Hz

Timer(int clicks)
{
  unsigned int now;
  now = *clock;

  while(abs(*clock - now) < clicks);

}


main()
{
unsigned char far *tela;

int px=160,py=100,
    ex=0,ey=0;

int done=0; // exit flag
tela = (unsigned char far *)0xA0000000;
asm mov ax,19
asm int 10h

printf("     8 2 4 6  ou ESC p/ Sair");

// main game loop

while(!done)
     {
     // erase dots

     *(tela + 320*py + px) = 0;
     *(tela + 320*ey + ex) = 0;

     // move player

     if (kbhit())
	{

	// which way is player moving

	switch(getch())
	      {

	      case '8': // up
		      {
		if(py>2)
		  py-=2;
		      } break;

	      case '2': // down
		      {
		 if(py<198)
		  py+=2;
		      } break;

	      case '6': // right
		      {
		 if(px<318)
		  px+=2;
		      } break;


	      case '4': // left
		      {
		 if(px>2)
		  px-=2;
		      } break;

	      case 27:
		      {
		      done=1;
		      } break;

	      } // end switch

	} // end if player hit a key

     // move enemy

     // begin brain

     if (px>ex) ex++;
     if (px<ex) ex--;
     if (py>ey) ey++;
     if (py<ey) ey--;

     if(px==ex && py==ey)
	done=1;
     // end brain

     // draw dots

     *(tela + 320*py + px) = 9;

     *(tela + 320*ey + ex) = 12;

     Timer(1);

     } // end while

     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nVc foi atingido!");
     getch();

     asm mov ax,3
     asm int 10h

} // end main

