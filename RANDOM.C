#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
union REGS regs;
void main()
{
  int lin=0,col=320,cco,cli,cor,cont;
  int drive=DETECT,modo;
  initgraph(&drive,&modo,"c:\\bc\\bgi");
while(!kbhit())
{
  cco=random(2);
  cli=random(2);
  cor=random(15);
  if(cco==0 && col<639)
    col++;
  else
  if(cco==1 && col>0)
    col--;
  if(cli==0 && lin<479)
    lin++;
  else
  if(cli==1 && lin>0)
    lin--;
  setcolor(cor);
  line(col,lin,320,240);
  putpixel(col,lin,15);
  putpixel(col-1,lin,15);
  putpixel(col+1,lin,15);
  putpixel(col,lin-1,15);
  putpixel(col,lin+1,15);
 }
 closegraph();
}



