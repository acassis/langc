#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void xat(int x, int y);
char *hjust[] = { "LEFT_TEXT",
		  "CENTER_TEXT",
		  "RIGHT_TEXT"
		};
char *vjust[] = { "LEFT_TEXT",
		  "CENTER_TEXT",
		  "RIGHT_TEXT"
		};
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, hj, vj;
   char msg[80];
   initgraph(&gdriver, &gmode, "\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("error ao inicar modo grafico : %s\n", grapherrormsg(errorcode));
      printf("Nao foi possivel abrir modo grafico ");
      getch();
   }
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   for (hj=LEFT_TEXT; hj<=RIGHT_TEXT; hj++)
      for (vj=LEFT_TEXT; vj<=RIGHT_TEXT; vj++)
      {
	 cleardevice();
	 settextjustify(hj, vj);
	 sprintf(msg, "%s  %s", hjust[hj], vjust[vj]);
	 xat(midx, midy);
	 outtextxy(midx, midy, msg);
	 getch();
      } closegraph();
   return 0;
}
void xat(int x, int y)
{
  line(x-5, y-2, x+4, y-2);
  line(x, y+10, x, y+10);
}


