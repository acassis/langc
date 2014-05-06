#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>

void save_screen(void far *buf[4]);
void restore_screen(void far *buf[4]);

int maxx, maxy;

int main(void)
{
   int gdriver=DETECT, gmode, errorcode;
   void far *ptr[4];

   /* auto-detect the graphics driver and mode */
   initgraph(&gdriver, &gmode, "\\arquiv~1\\bc\\bgi");
   errorcode = graphresult(); /* check for any errors */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   maxx = getmaxx();
   maxy = getmaxy();

   /* draw an image on the screen */
   rectangle(0, 0, maxx, maxy);
   line(0, 0, maxx, maxy);
   line(0, maxy, maxx, 0);

   save_screen(ptr);    /* save the current screen */
   getch();             /* pause screen */
   cleardevice();       /* clear screen */
   restore_screen(ptr); /* restore the screen */
   getch();             /* pause screen */

   closegraph();
   return 0;
}

void save_screen(void far *buf[4])
{
   unsigned size;
   int ystart=0, yend, yincr, block;

   yincr = (maxy+1) / 4;
   yend = yincr;
   size = imagesize(0, ystart, maxx, yend); /* get byte size of image */

   for (block=0; block<=3; block++)
   {
      if ((buf[block] = farmalloc(size)) == NULL)
      {
	 closegraph();
	 printf("Error: not enough heap space in save_screen().\n");
	 exit(1);
      }

      getimage(0, ystart, maxx, yend, buf[block]);
      ystart = yend + 1;
      yend += yincr + 1;
   }
}

void restore_screen(void far *buf[4])
{
   int ystart=0, yend, yincr, block;

   yincr = (maxy+1) / 4;
   yend = yincr;

   for (block=0; block<=3; block++)
   {
      putimage(0, ystart, buf[block], COPY_PUT);
      farfree(buf[block]);
      ystart = yend + 1;
      yend += yincr + 1;
   }
}

