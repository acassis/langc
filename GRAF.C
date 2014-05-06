#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void botao(int x1,int y1,int x2,int y2,int log);
int main(void)
{

   int gdriver = DETECT, gmode, errorcode;


   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");


   errorcode = graphresult();

   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }
   bar(0,0,639,479);

   getch();
   closegraph();
}
void botao(int x1,int y1,int x2,int y2,int log)
{


  if(log==0){
  retanulo(x1,y1,x2,y2,8);
  caixa(x1-3,y1-3,x2+1,y2+2,0);
  linha(x1-1,y1-1,x1-1,y2,7);
  linha(x1-2,y1-2,x1-2,y2,7);
  linha(x1,y1-1,x2,y1-1,7);
  linha(x1-1,y1-2,x2,y1-2,7);
  linha(x2-1,y1-1,x2-1,y2,0);
  linha(x2,y1-2,x2,y2,0);
  linha(x1-1,y2,x2,y2,0);
  linha(x1-2,y2+1,x2,y2+1,0);
  }
  else{
  linha(x2-1,y1-1,x2-1,y2,8);
  linha(x2,y1-2,x2,y2,8);
  linha(x1-1,y2,x2,y2,8);
  linha(x1-2,y2+1,x2,y2+1,8);
  linha(x1-1,y1-1,x1-1,y2,0);
  linha(x1-2,y1-2,x1-2,y2,0);
  linha(x1,y1-1,x2,y1-1,0);
  linha(x1-1,y1-2,x2,y1-2,0);

  }
}



