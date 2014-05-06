
#ifndef _MOUSE_H
#define _MOUSE_H

#include <dos.h>

#define MouseFunction(i)  \
  r.x.ax = i;             \
  int86(0x33, &r, &r);

typedef enum
{
  mbNone = 0,
  mbLeft = 1,
  mbRight = 2,
  mbCenter = 4
} TMouseButton;

int MouseExists(void);
void MouseShowCursor(void);
void MouseHideCursor(void);
TMouseButton MouseButtonPressed(void);
TMouseButton MouseGetCursorPos(int *x, int *y);
void MouseSetCursorPos(int x, int y);

#endif

