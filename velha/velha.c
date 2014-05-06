#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include "mouse.h"
#include "button.h"

#define ESC 27

void main()
{
  int driver = DETECT, mode, l, c;
  int x, y, done, winner;
  cl bestmove;

  if(MouseExists() == 0)
  {
    printf("Este programa necessita de um mouse.");
    return;
  }

  initgraph(&driver, &mode, "");
  if(graphresult() != grOk)
  {
    printf("Erro ao inicializar o modo grafico.");
    return;
  }

  settextstyle(1, HORIZ_DIR, 5);
  //settextjustify(LEFT_TEXT, TOP_TEXT);
  settextjustify(CENTER_TEXT, CENTER_TEXT);

  for(l = 0; l < 3; l++)
    for(c = 0; c < 3; c++)
      ButtonDraw(c, l);

  MouseSetCursorPos(getmaxx() / 2, getmaxy() / 2);
  MouseShowCursor();

  done = 0;
  while(!done)
  {
    TMouseButton pressed = MouseButtonPressed();

    if(pressed == mbLeft)
    {
      MouseGetCursorPos(&x, &y);
      MouseHideCursor();

      for(l = 0; l < 3; l++)
	for(c = 0; c < 3; c++)
	  if(ButtonContains(c, l, x, y) && Moves[l][c] == -1)
	  {
	    Moves[l][c] = HUMAN;
	    ButtonDraw(c, l);

	    winner = WhoWon();
	    if(winner == -1)
	    {
	      //ComputerMove();
	      bestmove = get_move();
	      if(bestmove.c != -1 && bestmove.l != -1)
	      {
		Moves[bestmove.l][bestmove.c] = COMPUTER;
		ButtonDraw(bestmove.c, bestmove.l);
		winner = WhoWon();
	      }
						}
	  }

      MouseShowCursor();
      while(MouseButtonPressed() == mbLeft);
    }

    done = (winner == 0 || winner == 1) ||
	   pressed == mbRight || (kbhit() ? getch() == ESC : 0);
  }

  MouseHideCursor();
  closegraph();
}

