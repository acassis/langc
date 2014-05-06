#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
void cardio(int col,int lin,int r)
{
   arc(col-r,lin,0,180,r);
   arc(col+r,lin,0,180,r);
   arc(col,lin,180,210,2*r);
   arc(col,lin,330,360,2*r);
   line(col,3.3*r+lin,col+(1.75*r),0.98*r+lin);
   line(col,3.3*r+lin,col-(1.75*r),0.98*r+lin);
}

void main ()
{
  int drive=DETECT,modo,col,lin,ra,cor,ct=0,mh[30],mv[30],tam[30];
  initgraph(&drive,&modo,"c:\\bc\\bgi");
  while(!kbhit())
  {
     lin=random(480);
     col=random(640);
     ra=random(25);
     cor=random(15)+1;
     mv[29]=lin;
     mh[29]=col;
     tam[29]=ra;
     setcolor(cor);
     cardio(col,lin,ra);
     for(ct=0;ct<29;ct++)
     {
	 mv[ct]=mv[ct+1];
	 mh[ct]=mh[ct+1];
	 tam[ct]=tam[ct+1];
     }
     delay(3);
     setcolor(0);
     cardio(mh[0],mv[0],tam[0]);
  }
  closegraph();
}