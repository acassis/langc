#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void main(void)
{
  int gdrive=DETECT,gmode,errorcode;
  char msg[20]="texto cor n§ ";
  int x=0,y=0,color=RED;
  initgraph(&gdrive,&gmode,"c:\\arquiv~1\\bc\\bgi");
  errorcode=graphresult();
  if (errorcode!=grOk)
  {
    printf("erro ao inicializar modo grafico :%s\n",grapherrormsg(errorcode));
    exit(1);
    }
       setcolor(color);
       outtextxy(x,y,msg);
       line(x,y+10,x+130,y+10);
       y+=20;
       getch();
   closegraph();
}