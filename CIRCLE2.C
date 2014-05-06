
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
void main ()
{
  int drive=DETECT,modo,col,lin,ra,cor,ct=0,mh[50],mv[50],cot=0,tam[50];
  initgraph(&drive,&modo,"d:\\bc\\bgi");
  while(!kbhit()){
     lin=random(480);
     col=random(640);
     ra=random(25);
     cor=random(15)+1;
     mv[49]=lin;
     mh[49]=col;
     tam[49]=ra;
     setcolor(cor);
     circle(col,lin,ra);
     for(ct=0;ct<49;ct++)
     {
	 mv[ct]=mv[ct+1];
	 mh[ct]=mh[ct+1];
	 tam[ct]=tam[ct+1];
     }
     delay(1);
     setcolor(0);
     circle(mh[0],mv[0],tam[0]);
     }
     closegraph();

}

