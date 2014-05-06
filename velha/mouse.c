
#include "mouse.h"

int MouseExists(void)
{
  union REGS r;
  MouseFunction(0);
  return r.x.ax;
}

/* Mostra o cursor do mouse */
void MouseShowCursor(void)
{
  union REGS r;
  MouseFunction(1);
}

/* Esconde o cursor do mouse */
void MouseHideCursor(void)
{
  union REGS r;
  MouseFunction(2);
}

/* Retorna qual botao do mouse foi acionado e em que posicao da tela */
TMouseButton MouseButtonPressed(void)
{
  union REGS r;
  MouseFunction(3);
  return (TMouseButton)r.x.bx;
}

/* Retorna qual botao do mouse foi acionado e em que posicao da tela */
TMouseButton MouseGetCursorPos(int *x, int *y)
{
  union REGS r;
  MouseFunction(3);
  *x = r.x.cx;
  *y = r.x.dx;
  return (TMouseButton)r.x.bx;
}

/* Seta a posicao co cursor do mouse na tela */
void MouseSetCursorPos(int x, int y)
{
  union REGS r;
  r.x.cx = x;
  r.x.dx = y;
  MouseFunction(4);
}
/*////////////////////////////////////////////////////////////////////////////*/

