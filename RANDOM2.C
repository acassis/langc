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
  cco=random(2);
  cli=random(2);
  ccol=random(2);
  clin=random(2);
  cor=random(15);

  if(cco==0 && co<639)
    co++;
  else
  if(cco==1 && co>0)
    co--;
  if(cli==0 && li<479)
    li++;
  else
  if(cli==1 && li>0)
    li--;

  if(ccol==0 && col<639)
    col++;
  else
  if(ccol==1 && col>0)
    col--;
  if(clin==0 && lin<479)
    lin++;
  else
  if(clin==1 && lin>0)
    lin--;

  if(co>col)
  {
     if(co-col>100)
     {
	co--;
	col++;
     }
  }
  else
    if(col>co)
      if(col-co>100)
       {
	 col--;
	 co++;
       }

  if(li>lin)
  {
     if(li-lin>100)
     {
	li--;
	lin++;
     }
  }
  else
    if(lin>li)
      if(lin-li>100)
       {
	 lin--;
	 li++;
       }

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



