#include<graphics.h>
void main()
{
  int drive = DETECT,modo;
  initgraph(&drive,&modo,"c:\\bc\\bgi");
  circle(320,240,100);
  getch();
  closegraph();
}