#include <stdio.h>
#include <math.h>
void main()
{
   int x,y,tx=25,ty=13;
   float ang=45;
   char cor[]="Û\004";
   clrscr();
   while(!kbhit())
   {
      x = cos(ang) * tx;
      y = sin(ang) * ty;
      puttext(40+x,13+y,40+x,13+y,cor);
      ang+=0.001;
      gotoxy(40,12);
      printf("  %d %d   ",x,y);
      //delay(10);
      if(x==13 && y==10)
      {
	ang=45;
	tx--;
	ty--;
	strcpy(cor,"Û\002");
      }
   }
}


/////////////////////////////////////////////////////////////////////////////




















