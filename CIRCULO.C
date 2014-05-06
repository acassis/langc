#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
float p2=2*(3.141592),ang=(2*(3.141592))/150,rota=0,pontox,pontoy;
float cor=1,raioy=240,raiox=240,posx=80,posy=0;
void rot()
{
  int i;
  float j;
  for(i=0,j=rota;i<181;i++,j+=ang){
    rota+=(p2/2)/64;
    if(rota>ang)
      rota-=ang;
    pontox = cos(j);
    pontoy = sin(j);
    setcolor(cor);
    setfillstyle(1,cor);
    fillellipse((raiox+floor(pontox * raiox))+posx,(raioy+floor(pontoy * raioy))+posy,5,5);
    setfillstyle(1,16-cor);
    delay(5);
    setcolor(16-cor);
    //fillellipse((raiox+floor(pontox * raiox))+posx,(raioy+floor(pontoy * raioy))+posy,5,5);
    line(320,240,(raiox+floor(pontox * raiox))+posx,(raioy+floor(pontoy * raioy))+posy);
    raiox-=0.2;
    raioy-=0.2;
    posx+=0.2;
    posy+=0.2;
    if(raiox<=0){
	 cor++;
	 //delay(1000);
	 cleardevice();
	 raiox=240;
	 raioy=240;
	 posx=80;
	 posy=0;
	}
  }
}

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;
   char colstr[80];
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   while(!kbhit()){
     rot();
     if(cor>15)
       cor=1;
    }
   closegraph();
   return 0;
}

