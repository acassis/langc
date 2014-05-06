
#include <graphics.h>
#include "math.h"
#include "button.h"

//#define check(a0, a1, a2, b) (((a0) == (b)) && ((a1) == (b)) && ((a2) == (b)))

#define check(a0, a1, a2) ((a0) != -1 && (a0) == (a1) && (a0) == (a2))

int ButtonWidth = 100, ButtonHeight = 100, ButtonBorderWidth = 1;
int Moves[3][3] = {{ -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 }};

void ButtonDraw(int c, int l)
{
  int x, y, i;

  x = (getmaxx() - ButtonWidth * 3) / 2 + c * ButtonWidth;
  y = (getmaxy() - ButtonHeight * 3) / 2 + l * ButtonHeight;

  setfillstyle(SOLID_FILL, LIGHTGRAY);
  bar(x, y, x + ButtonWidth, y + ButtonHeight);

  setcolor(BLACK);
  rectangle(x, y, x + ButtonWidth, y + ButtonHeight);

  for(i = 0; i < ButtonBorderWidth; i++)
  {
    setcolor(Moves[l][c] == -1 ? WHITE : DARKGRAY);
    moveto(x + i + 1, y + ButtonHeight - i - 1);
    lineto(x + i + 1, y + i + 1);
    lineto(x + ButtonWidth - i - 1, y + i + 1);

    setcolor(Moves[l][c] == -1 ? DARKGRAY : WHITE);
    lineto(x + ButtonWidth - i - 1, y + ButtonHeight - i - 1);
    lineto(x + i + 1, y + ButtonHeight - i - 1);
  }

  setcolor(Moves[l][c] ? WHITE : BLACK);
  switch(Moves[l][c])
  {
    case 0:
      DrawO(x + ButtonBorderWidth,
            y + ButtonBorderWidth,
            ButtonWidth, ButtonHeight);
    break;

    case 1:
      DrawX(x + ButtonBorderWidth,
            y + ButtonBorderWidth,
            ButtonWidth, ButtonHeight);
    break;
  }
}

int ButtonContains(int c, int l, int xPos, int yPos)
{
  int x, y;

  x = (getmaxx() - ButtonWidth * 3) / 2 + c * ButtonWidth;
  y = (getmaxy() - ButtonHeight * 3) / 2 + l * ButtonHeight;

  return (x <= xPos && (x + ButtonWidth) >= xPos) &&
         (y <= yPos && (y + ButtonHeight) >= yPos);
}

void DrawO(int x, int y, int w, int h)
{
  setcolor(BLACK);
  ellipse(x + w / 2, y + h / 2, 0, 360, w * 0.4, h * 0.4);
  ellipse(x + w / 2, y + h / 2, 0, 360, w * 0.3, h * 0.3);
}

void DrawX(int x, int y, int w, int h)
{
  int point[26], c;

  c = 0;
  point[c++] = x + w * 0.1;
  point[c++] = y + h * 0.1;

  point[c++] = x + w * 0.4;
  point[c++] = y + h * 0.5;

  point[c++] = x + w * 0.1;
  point[c++] = y + h * 0.9;

  point[c++] = x + w * 0.3;
  point[c++] = y + h * 0.9;

  point[c++] = x + w * 0.5;
  point[c++] = y + h * 0.6;

  point[c++] = x + w * 0.7;
  point[c++] = y + h * 0.9;

  point[c++] = x + w * 0.9;
  point[c++] = y + h * 0.9;

  point[c++] = x + w * 0.6;
  point[c++] = y + h * 0.5;

  point[c++] = x + w * 0.9;
  point[c++] = y + h * 0.1;

  point[c++] = x + w * 0.7;
  point[c++] = y + h * 0.1;

  point[c++] = x + w * 0.5;
  point[c++] = y + h * 0.4;

  point[c++] = x + w * 0.3;
  point[c++] = y + h * 0.1;

  point[c++] = x + w * 0.1;
  point[c++] = y + h * 0.1;

  setcolor(YELLOW);
  drawpoly(13, point);
}

int WhoWon(void)
{
  if(check(Moves[0][0], Moves[0][1], Moves[0][2]) ||
     check(Moves[1][0], Moves[1][1], Moves[1][2]) ||
     check(Moves[2][0], Moves[2][1], Moves[2][2]) ||

     check(Moves[0][0], Moves[1][0], Moves[2][0]) ||
     check(Moves[0][1], Moves[1][1], Moves[2][1]) ||
     check(Moves[0][2], Moves[1][2], Moves[2][2]) ||

     check(Moves[0][0], Moves[1][1], Moves[2][2]) ||
     check(Moves[0][2], Moves[1][1], Moves[2][0]))
    return Moves[0][0];

  return -1;
}

void ComputerMove(void)
{
  int c;
  int point[9][2] = {
      { 0, 0 }, { 1, 1 }, { 2, 2 },
      { 0, 1 }, { 1, 0 }, { 1, 1 },
      { 1, 2 }, { 2, 1 }, { 2, 2 }
  };

  for(c = 0; c < 9; c++)
    if(Moves[point[c][0]][point[c][1]] == -1)
    {
      Moves[point[c][0]][point[c][1]] = COMPUTER;
      ButtonDraw(point[c][1], point[c][0]);
      return;
    }
}


//////////
/*
int WhoWon(form)
{
  if ((form.a0.value!="" && form.a0.value==form.a3.value && form.a0.value==form.a6.value) ||
      (form.a0.value!="" && form.a0.value==form.a1.value && form.a0.value==form.a2.value) ||
      (form.a0.value!="" && form.a0.value==form.a4.value && form.a0.value==form.a8.value) ||
      (form.a1.value!="" && form.a1.value==form.a4.value && form.a1.value==form.a7.value) ||
      (form.a2.value!="" && form.a2.value==form.a5.value && form.a2.value==form.a8.value) ||
      (form.a2.value!="" && form.a2.value==form.a4.value && form.a2.value==form.a6.value) ||
      (form.a3.value!="" && form.a3.value==form.a4.value && form.a3.value==form.a5.value) ||
      (form.a6.value!="" && form.a6.value==form.a7.value && form.a6.value==form.a8.value))
    return 1;
  else
    return 0;
}

*/

int comp_move(int player, int weight, int depth)
{
  int cost, bestcost = -2, newplayer, c, l, done = 0;

  newplayer = (player == COMPUTER) ? HUMAN : COMPUTER;

  if(depth == 3)
    return 0;

  if(WhoWon() != -1)
    return 1;

  for(l = 0; l < 3 && !done; l++)
    for(c = 0; c < 3 && !done; c++)
    {
      if(Moves[l][c] != -1)
        continue;

      Moves[l][c] = player;
      cost = comp_move(newplayer, -weight, depth + 1);
      if(cost > bestcost)
      {
        bestcost = cost;
        if(cost == 1)
          done = 1;
      }

      Moves[l][c] = -1;
    }

  if(bestcost == -2)
    bestcost = 0;

  return -bestcost;
}

cl get_move(void)
{
  int cost, c, l, done = 0;
  int bestcost = -2;
  cl bestmove = { -1, -1 };
  static int step = 0;

  if(step++ == 0)
  {
    if(Moves[1][1] == -1)
      bestmove.c = bestmove.l = 1;
    else if(Moves[0][0] == -1)
      bestmove.c = bestmove.l = 0;

    return bestmove;
  }

  for(l = 0; l < 3 && !done; l++)
    for(c = 0; c < 3 && !done; c++)
    {
      if(Moves[l][c] != -1)
        continue;

      Moves[l][c] = COMPUTER;
      cost = comp_move(HUMAN, -1, 0);
      if(cost > bestcost)
			{
				if(cost == 1)
          done = 1;

        bestmove.c = c;
        bestmove.l = l;
				bestcost = cost;
			}
			Moves[l][c] = -1;
		}

  return bestmove;
}

