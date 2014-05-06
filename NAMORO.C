#include<graphics.h>
#include<dos.h>
void main(void)
{
  char cor;
  int nd,i=260,j=-260;
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "d:\\bc\\bgi");
 while(!kbhit() && i>0){
  cleardevice();
  for(nd=0;nd<320;nd++){
    if(kbhit())
    return;
    if(nd%10==0)
       cor=(char)(nd%51);
    setcolor(cor);
    /*setfillstyle( SOLID_FILL,cor);
    fillellipse(0+nd,479-nd+j,nd/2,nd/2);
    fillellipse(639-nd,479-nd+j,nd/2,nd/2);*/
    circle(0+nd,479-nd+j,nd/2);
    circle(639-nd,479-nd+j,nd/2);
    /*delay(30);*/}
  for(;nd>0;nd--){
    if(kbhit())
    return;
    if(nd%10==0)
       cor=(char)(nd%51);
    setcolor(cor);
    /*setfillstyle( SOLID_FILL,cor);
    fillellipse(320,479-nd+j,nd/2,nd/2);*/
    circle(320,479-nd+j,nd/2);}
  for(nd=0;nd<320;nd++){
    if(kbhit())
    return;
    if(nd%10==0)
       cor=(char)(nd%51);
    setcolor(cor);
    /*setfillstyle( SOLID_FILL,cor);
    fillellipse(0+nd,0+nd+i,nd/2,nd/2);
    fillellipse(639-nd,0+nd+i,nd/2,nd/2);*/
    circle(0+nd,0+nd+i,nd/2);
    circle(639-nd,0+nd+i,nd/2);
    /*delay(30);*/}
  for(;nd>0;nd--){
    if(kbhit())
    return;
    if(nd%10==0)
       cor=(char)(nd%51);
    setcolor(cor);
    /*setfillstyle( SOLID_FILL,cor);
    fillellipse(320,0+nd+i,nd/2,nd/2);*/
    circle(320,0+nd+i,nd/2);}
    i-=10;j+=10;}
  getch();
  closegraph();

}