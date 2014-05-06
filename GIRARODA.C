#include<dos.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
void main()
{
    char resp='n';
    int gdriver = DETECT, gmode,cor=1,ct=0;
    float ang1=0,x1=0,y1=0,raio1=100,ang2=0,x2,y2,raio2=10,ang3=0,x3,y3,raio3=55,ang4=0,x4,y4,raio4=25;
    initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
  while(!kbhit())
  {
    ang1+=0.03;
    x1 = cos(ang1) * raio1;
    y1 = sin(ang1) * raio1;
    ang2+=0.003;
    x2 = cos(ang2) * raio2;
    y2 = sin(ang2) * raio2;
    ang3+=0.003;
    x3 = cos(ang3) * raio3;
    y3 = sin(ang3) * raio3;
    ang4+=0.003;
    x4 = cos(ang4) * raio4;
    y4 = sin(ang4) * raio4;
    putpixel(x4+x3+x2+x1+320,y4+y3+y2+y1+240,15);
  }
  closegraph();
}