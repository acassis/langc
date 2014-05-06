//----------------------------------------------------------------------------
//Programa: Coratest.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Este programa recria com pequenos coracoes um coracao maior.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include<graphics.h>
void cardio(int col,int lin,int r)
{
   int p[6];
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
}
void cardio2(int col,int lin,int r)
{
   arc(col-r,lin,0,180,r);
   arc(col+r,lin,0,180,r);
   arc(col,lin,180,210,2*r);
   arc(col,lin,330,360,2*r);
   line(col,3.3*r+lin,col+(1.75*r),0.98*r+lin);
   line(col,3.3*r+lin,col-(1.75*r),0.98*r+lin);
}

int linha(int x1,int y1,int x2,int y2,char cor);
float i,j,col,lin,mt[42]={3.67,4.00,4.30,4.60,4.90,5.20,5.50,5.80,6.10,6.40,6.50,6.65,6.79,267,290,310,330,350,370,390,410,420,425,430,431};
int num=0;
void main()
{
   int modo=DETECT,drive,resp;
   initgraph(&modo,&drive,"c:\\bc\\bgi");
inicio:
   setcolor(4);
   setfillstyle( SOLID_FILL,4);
   resp=linha(247,179,432,320,4);
   if(resp==1)
      goto inicio;
   for(i=6.8;i>6.4;i-=0.005)
   {
     col=cos(i)*160 + 320;
     lin=sin(i)*160 + 170;
     setcolor(4);
     cardio(col,lin,4);
     cardio(640-col,lin,4);
     setcolor(0);
     cardio2(col,lin,4);
     cardio2(col,lin,5);
     cardio2(col,lin,6);
     cardio2(col,lin,7);
     cardio2(640-col,lin,4);
     cardio2(640-col,lin,5);
     cardio2(640-col,lin,6);
     cardio2(640-col,lin,7);
     delay(1);
     if(num>9 && num<13)
     if(i<mt[num])
     {
       num++;
       goto inicio;
     }
   }
   for(i=6.5;i>3.2;i-=0.005)
   {
     col=cos(i)*80 + 400;
     lin=sin(i)*80 + 170;
     setcolor(4);
     cardio(col,lin,4);
     cardio(640-col,lin,4);
     setcolor(0);
     cardio2(col,lin,4);
     cardio2(col,lin,5);
     cardio2(col,lin,6);
     cardio2(col,lin,7);
     cardio2(640-col,lin,4);
     cardio2(640-col,lin,5);
     cardio2(640-col,lin,6);
     cardio2(640-col,lin,7);
     delay(1);
    if(num<10)
      if(i<mt[num])
     {
       num++;
       goto inicio;
     }
   }
  cleardevice();
  setcolor(4);
  cardio(320,165,4);
  for(i=650;i>25;i--)
  {
   setcolor(4);
   outtextxy(i,200,"No final, Dois coracoes apaixonados sempre se encontram em um so coracao. ");
   delay(50);
   setcolor(0);
   outtextxy(i,200,"No final, Dois coracoes apaixonados sempre se encontram em um so coracao. ");
  }
   setcolor(4);
   outtextxy(i,200,"No final, Dois coracoes apaixonados sempre se encontram em um so coracao. ");
   getch();
}

int linha(int x1,int y1,int x2,int y2,char cor)
{
  int dx,dy,dyy,x=x2,y=y2,i,xt,yt,yy=y,xx=x;
  float erro=0.0,error=0.0;
  if(x1>x2){
     xt=x2;
     x2=x1;
     x1=xt;}
  if(y1>y2){
     yt=y2;
     y2=y1;
     y1=yt;}
  dx=(x2-x1);dy=(y2-y1);
  for(i=0;i<=dx;i++)
  {
    setcolor(4);
    cardio(y,x,4);
    cardio(yy,xx,4);
    setcolor(0);
    cardio2(y,x,4);
    cardio2(yy,xx,4);
    cardio2(y,x,5);
    cardio2(yy,xx,5);
    cardio2(y,x,6);
    cardio2(yy,xx,6);
    cardio2(y,x,7);
    cardio2(yy,xx,7);
    cardio2(y,x,8);
    cardio2(yy,xx,8);
    if(num>12)
      if(x<mt[num])
     {
       num++;
       return 1;
     }
    delay(5);
    x--;
    xx--;
    erro=erro+(float)dy/(float)dx;
    if(erro>0.5)
    {
      erro=erro-1.0;
      y--;
      yy++;
    }
  }
  return 0;
}

