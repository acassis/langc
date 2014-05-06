
#ifndef _BUTTON_H
#define _BUTTON_H

#define HUMAN    0
#define COMPUTER 1

typedef struct { int c, l; } cl;

extern int ButtonWidth, ButtonHeight, ButtonBorderWidth;
extern int Moves[3][3];

void ButtonDraw(int x, int y);
int ButtonContains(int xSrc, int ySrc, int xPos, int yPos);
void DrawO(int x, int y, int w, int h);
void DrawX(int x, int y, int w, int h);
int WhoWon(void);
void ComputerMove(void);
cl get_move(void);

#endif

