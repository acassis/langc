#include <grafico.h>
#include<conio.h>
#define x 100
#define y 20
#define esc 0x1b
void main(void)
{
  char ch='s';
  if(ch=='s');
  mouse();
  set_modo();
  while((ch=getch())!=esc){
  retangulo(180+x,180+y,240+x,240+y,15);
  retangulo(198+x,198+y,220+x,220+y,8);
  caixa(197+x,197+y,221+x,221+y,0);
  linha(199+x,198+y,199+x,220+y,7);
  linha(198+x,198+y,198+x,220+y,7);
  linha(200+x,199+y,220+x,199+y,7);
  linha(200+x,198+y,220+x,198+y,7);
  linha(219+x,199+y,219+x,220+y,0);
  linha(220+x,198+y,220+x,220+y,0);
  linha(199+x,219+y,220+x,219+y,0);
  linha(198+x,220+y,220+x,220+y,0);
  getch();
  caixa(197+x,197+y,221+x,221+y,0);
  retangulo(198+x,198+y,220+x,220+y,8);
  linha(199+x,198+y,199+x,220+y,0);
  linha(198+x,198+y,198+x,220+y,0);
  linha(200+x,199+y,220+x,199+y,0);
  linha(200+x,198+y,220+x,198+y,0);
}

}