#include <graphics.h>
#include"yang.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int lin=240,col=320,r=140;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   yang(col,lin,r);
   getch();
   closegraph();
   return 0;
}
