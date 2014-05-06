#include<graphics.h>
void main(void)
{
  char cor;
  int nd;
  int driver=DETECT,mode;
  initgraph(&driver, &mode, "c:\\bc\\bgi");
  for(nd=0;nd<2000;nd++)
  {
    if(nd%10==0)
       cor=(char)(nd%6);
    setcolor(cor);
    line(0,479-nd,639,nd);
    //delay(30);
  }
  getch();

}