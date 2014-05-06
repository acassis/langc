#include <conio.h>
#include <stdlib.h>
#include<graphics.h>
#include <stdio.h>
#include <dos.h>
class estrela
{
   private:
    int x[100],y[100];
    int brilho;
   public:
   void ini()
   {
      int i;
      printf("\nIniciando coordenadas...");
      for(i=0;i<100;i++)
      {
	x[i] = random(640);
	y[i] = random(480);
      }
   }
   void mostra()
   {
     int i;
     cleardevice();
     for(i=0;i<100;i++)
      putpixel(x[i],y[i],15);
   }
};
void main()
{
    int drive=DETECT,modo;
    estrela *nova;
    initgraph(&drive,&modo,"c:\\bc\\bgi");
    nova->ini();
    delay(500);
    nova->mostra();
}