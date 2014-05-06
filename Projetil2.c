#include <math.h>
#include<graphics.h>
void main(void)
{
   int drive=DETECT,modo,v, ang;
   float rad, vx, vy, t, tv, x, y;
   initgraph(&drive,&modo,"c:\\bc\\bgi");
//----------------------------------------------------------------------------------
   printf("Informe a velocidade:");
   scanf("%d",&v);
   printf("Informe o angulo:");
   scanf("%d",&ang);
   rad = ang/57.3;
   vx = v * cos(rad);
   vy = v * sin(rad);
   t = vy / 10;
   t = 2 * t;
   for(tv = 0; tv<t; tv += 0.01)
   {
     x = (vx * tv);
     y = ((vy * tv) - (5 * tv * tv));
     setcolor(15);
     setfillstyle( SOLID_FILL,15);
     bar(x,479 - y,x + 2,477 - y);
     delay(1);
     setcolor(0);
     setfillstyle( SOLID_FILL,0);
     bar(x,479 - y,x + 2,477 - y);
   }
}