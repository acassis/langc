#include <stdlib.h>
#include<graphics.h>
void main()
{
   int x=310,y=400,move; //1->direita,2->esquerda,3->parar;
   int drive=DETECT,modo,col=320,lin=100;
   char ch=0;
   long cont=0,cont_ant=0;
   initgraph(&drive,&modo,"");
while(ch!=27)
{
  setwritemode(1);
  if(kbhit())
  {
    ch=getch();
  }
  if(ch=='4')
   if(col>10)
     col--;
  if(ch=='6')
   if(col<629)
     col++;
  circle(col,lin,10);

  if(cont==cont_ant)
  {
      move = random(3)+1;
  }
  cont_ant = cont;

  if(move == 1)
   if(x<635)
     x++;
  if(move == 2)
   if(x>5)
     x--;

  if(x>col-10 && x<col+10)
    cont++;
  circle(x,y,4);
  delay(5);
  cleardevice();
}
}