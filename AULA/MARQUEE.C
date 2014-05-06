#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy,tam=5,cor=15;
   char texto[35];
   int letra=0;
   time_t t;
   char *fname[] = { "DEFAULT font",
		  "TRIPLEX font",
		  "SMALL font",
		  "SANS SERIF font",
		  "GOTHIC font"
		};
   initgraph(&gdriver,&gmode,"\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   midx = getmaxx();
   midy = 240;

   printf("Digite o Texto: ");
   gets(texto);
   flushall();

   srand((unsigned) time(&t));
   cleardevice();
   while(!kbhit())
   {
     settextstyle(SANS_SERIF_FONT, HORIZ_DIR, tam);
     setcolor(cor);
     outtextxy(midx, midy, texto);
     delay(10);
     setcolor(0);
     outtextxy(midx, midy, texto);
     midx-=2;

     if(midx<=(textwidth(texto)*-1))
     {
       tam=rand()%10;
       cor=rand()%15;
       if(cor==0)
	 cor=1;
       midx=640;
       midy =rand()% 480;
       letra=rand()%5;
     }
   }

   /* clean up */
   closegraph();
   return 0;
}