#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
void main()
{
  int lin=240,col=320,li=240,co=320,cco,cli,ccol,clin,cor;
  int drive=DETECT,modo;
  initgraph(&drive,&modo,"c:\\bc\\bgi");

while(!kbhit())
{
inicio:
  cco=random(2);
  cli=random(2);
  ccol=random(2);
  clin=random(2);
  cor=random(15);

  if(cco==0 && co<col+50 && co>col-50)
    co++;
  else
  if(cco==1 && co<col+50 && co>col-50)
    co--;
  if(cli==0 && li<lin+50 && li>lin-50)
    li++;
  else
  if(cli==1 && li<lin+50 && li>lin-50)
    li--;

  if(ccol==0 && col<co+50 && col>co-50)
    col++;
  else
  if(ccol==1 && col<co+50 && col>co-50)
    col--;
  if(clin==0 && lin<li+50 && lin>li-50)
    lin++;
  else
  if(clin==1 && lin>0)
    lin--;
  else
    goto inicio;

  setcolor(cor);
  line(col,lin,co,li);
  putpixel(col,lin,1);
  putpixel(col-1,lin,1);
  putpixel(col+1,lin,1);
  putpixel(col,lin-1,1);
  putpixel(col,lin+1,1);

  putpixel(co,li,15);
  putpixel(co-1,li,15);
  putpixel(co+1,li,15);
  putpixel(co,li-1,15);
  putpixel(co,li+1,15);
 }
 closegraph();
}



