#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
union REGS p;
main (void)

 {
  int gdriver=DETECT, gmode, errorcode;
  int maxx, maxy, i, y;
  initgraph(&gdriver,&gmode, "c:\\arquiv~1\\bc\\bgi");
  errorcode=graphresult();
  if (errorcode != grOk)

   {
    printf ("Graphics error: %s\n", grapherrormsg(errorcode));
    printf ("Pressione qualquer tecla para continuar...");
    getch();
    exit(1);
   }

  cleardevice();
  setfillstyle(SOLID_FILL,1);
  sector(320,220,0,360,100,100);
  getch();
  setfillstyle(SOLID_FILL,2);
  sector(100,100,0,60,50,50);
  setfillstyle(SOLID_FILL,6);
  sector(100,100,60,150,50,50);
  setfillstyle(SOLID_FILL,4);
  sector(100,100,150,360,50,50);

  getch();
  closegraph();

}