#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define ARROW_SIZE 10

void draw_arrow(int x, int y);

int main(void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;
   void *arrow;
   int x, y, maxx;
   unsigned int size;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "d:\\bc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   maxx = getmaxx();
   x = 0;
   y = getmaxy() / 2;

   /* draw the image to be grabbed */
   draw_arrow(x, y);

   /* calculate the size of the image */
   size = imagesize(x, y-ARROW_SIZE, x+(4*ARROW_SIZE), y+ARROW_SIZE);

   /* allocate memory to hold the image */
   arrow = malloc(size);
   /*bar(10,10,600,400);*/
   /* grab the image */
   getimage(x, y-ARROW_SIZE, x+(4*ARROW_SIZE), y+ARROW_SIZE, arrow);

   /* repeat until a key is pressed */
   while (!kbhit())
   {
      /* erase old image */
      putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);

      x += ARROW_SIZE;
      if (x >= maxx)
	  x = 0;

      /* plot new image */
      putimage(x, y-ARROW_SIZE, arrow, XOR_PUT);
   }

   /* clean up */
   free(arrow);
   closegraph();
   return 0;
}

void draw_arrow(int x, int y)
{
   /* draw an arrow on the screen */
   moveto(x, y);
   linerel(4*ARROW_SIZE, 0);
   linerel(-2*ARROW_SIZE, -1*ARROW_SIZE);
   linerel(0, 2*ARROW_SIZE);
   linerel(2*ARROW_SIZE, -1*ARROW_SIZE);
}