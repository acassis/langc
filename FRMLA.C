#include<math.h>
#include<graphics.h>
#define PI 3.1415926535897932385

void main()
{
   int ang=0,x=5,y=25,x2,y2,drive=DETECT,modo;
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   while(!kbhit())
   {
      ang++;
      x2 = x * cos((ang*PI)/180) - y * sin((ang*PI)/180);
      y2 = y * cos((ang*PI)/180) + x * sin((ang*PI)/180);
      circle(x2+320,y2+240,3);
      delay(100);
   }
}