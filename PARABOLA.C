#include<conio.h>
#include<stdio.h>
#include<graphics.h>
void main()
{
   int drive=DETECT,modo,i=1;
   float ct=150;
   char msg[]="ALAN";
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   while(!kbhit())
   {
     ct=ct-0.2;
     if(i==0)
      i=1;
     setcolor(i);
     circle(320,230,20);
     settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
     circle(ct+440,(ct*ct)/128+(2*ct)+240,5);
     setcolor(i+1);
     circle(640-(ct+440),480-((ct*ct)/128+(2*ct)+255),5);

     setcolor(i+2);
     circle((ct*ct)/128+(2*ct)+320,480-(ct+380),5);
     setcolor(i+3);
     circle(450-((ct*ct)/128+(2*ct)+140),ct+360,5);
     if(ct<-410){
       ct=150;
       delay(1000);
       cleardevice();
       i++;
       if(i>12)
	i=1;}
    }
}