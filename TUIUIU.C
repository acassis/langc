#include<graphics.h>
#include <stdlib.h>

void main ()
{
  int lin=100,col=80,cor;
  int drive=DETECT,modo;
  initgraph(&drive,&modo,"c:\\bc\\bgi");
  while(!kbhit())
  {
   col++;
   cor=random(15);
   if(col>100){
     col=80;
     lin++;}
   if(lin>300)
     break;
   setcolor(cor+1);
   line(col,lin,320,470);
   delay(0);
   setcolor(0);
   line(col,lin,320,470);
   putpixel(col,lin,15);

  }
  delay(200);
  closegraph();
}