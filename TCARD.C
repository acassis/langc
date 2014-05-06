#include<conio.h>
#include<graphics.h>
#include "grafico.h"
void cardio(int col,int lin,int r,int log)
{
   int p[6];
   setfillstyle(1,8);
   setcolor(8);
   fillellipse(col-r,lin,r,r);
   fillellipse(col+r,lin,r,r);
   pieslice(col,lin,180,210,2*r);
   pieslice(col,lin,330,360,2*r);
   p[0]=col-(1.75*r);p[1]=0.98*r+lin;
   p[2]=col;p[3]=3.3*r+lin;
   p[4]=col+(1.75*r);p[5]=0.98*r+lin;
   fillpoly(3, p);
   p[2]=col;
   p[3]=lin;
   fillpoly(3, p);
  if(log==0){
   setcolor(0);
   arc(col+r,lin,0,180,r);
   arc(col,lin,330,360,2*r);
   line(col,3.3*r+lin,col+(1.75*r),0.98*r+lin);
   arc(col+r,lin,0,180,r+1);
   arc(col,lin,330,360,2*r+1);
   line(col+1,3.3*r+lin,col+(1.75*r)+1,0.98*r+lin);
   arc(col+r,lin,0,180,r-1);
   arc(col,lin,330,360,2*r-1);
   line(col-1,3.3*r+lin,col+(1.75*r)-1,0.98*r+lin);

   setcolor(7);
   arc(col,lin,180,210,2*r);
   arc(col-r,lin,0,180,r);
   line(col,3.3*r+lin,col-(1.75*r),0.98*r+lin);
   arc(col,lin,180,210,2*r+1);
   arc(col-r,lin,0,180,r+1);
   line(col-1,3.3*r+lin,col-(1.75*r)-1,0.98*r+lin);
   arc(col,lin,180,210,2*r-1);
   arc(col-r,lin,0,180,r-1);
   line(col+1,3.3*r+lin,col-(1.75*r)+1,0.98*r+lin);}
  else{
   setfillstyle(1,8);
   setcolor(8);
   fillellipse(col-r,lin,r,r);
   fillellipse(col+r,lin,r,r);
   pieslice(col,lin,180,210,2*r);
   pieslice(col,lin,330,360,2*r);
   p[0]=col-(1.75*r);p[1]=0.98*r+lin;
   p[2]=col;p[3]=3.3*r+lin;
   p[4]=col+(1.75*r);p[5]=0.98*r+lin;
   fillpoly(3, p);
   p[2]=col;
   p[3]=lin;
   fillpoly(3, p);
   setcolor(0);
   arc(col,lin,180,210,2*r);
   arc(col-r,lin,0,180,r);
   line(col,3.3*r+lin,col-(1.75*r),0.98*r+lin);
   arc(col,lin,180,210,2*r+1);
   arc(col-r,lin,0,180,r+1);
   line(col-1,3.3*r+lin,col-(1.75*r)-1,0.98*r+lin);
   arc(col,lin,180,210,2*r-1);
   arc(col-r,lin,0,180,r-1);
   line(col+1,3.3*r+lin,col-(1.75*r)+1,0.98*r+lin);
   setcolor(7);
   arc(col+r,lin,0,180,r);
   arc(col,lin,330,360,2*r);
   line(col,3.3*r+lin,col+(1.75*r),0.98*r+lin);
   arc(col+r,lin,0,180,r+1);
   arc(col,lin,330,360,2*r+1);
   line(col+1,3.3*r+lin,col+(1.75*r)+1,0.98*r+lin);
   arc(col+r,lin,0,180,r-1);
   arc(col,lin,330,360,2*r-1);
   line(col-1,3.3*r+lin,col+(1.75*r)-1,0.98*r+lin);}
}
void main ()
{
   int drive=DETECT,modo,sta,stant;
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   mouse();
   cardio(320,240,20,0);
   sta=0;
  while(sta!=2)
   {
     stant=sta;
     sta=status();
    if(stant!=sta){
     if(sta==1){
       cardio(320,240,20,1);
       delay(1000);}
     else
       cardio(320,240,20,0);}
   }
   getch();
}
