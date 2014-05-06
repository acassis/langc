#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

int main(void)
{
 int gdriver = DETECT, gmode, errorcode;
 int xmax, ymax;
 initgraph(&gdriver, &gmode, "c:\\arquiv~1\\bc\\bgi");
 errorcode = graphresult();
 if (errorcode != grOk)
 {
  printf("Graphics error: %s\n", grapherrormsg(errorcode));
  printf("Press any key to halt:");
  getch();
  exit(1);
  }
  setcolor(getmaxcolor());
  xmax = getmaxx();
  ymax = getmaxy();
  while(!kbhit())
  {
   putpixel((sin(rand()%40*xmax/2))+rand()%xmax,(cos(rand()%40*ymax/2))+rand()%ymax,rand()%15);
   delay(1);
   }
   getch();
  closegraph();
  return 0;
}