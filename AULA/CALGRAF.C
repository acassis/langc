#include<graphics.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
union REGS in,out;
#include "mouse.med"
void main(void)
{
 int gdriver=DETECT,gmod ,errorcode;
 initgraph(&gdriver,&gmod,"c:\\arquiv~1\\bc\\bgi\\");
 errorcode=graphresult();
 if(errorcode!=grOk)
  {printf("erro ao iniciar mode grafico :%s\n",grapherrormsg(errorcode));
   printf("pressione qualquer tecla para retornar...");
   getch();  exit(1);
    }
   if(!mousepresente())  exit(1);

   setfillstyle(SOLID_FILL,3);
   bar(0,0,680,480);
   setcolor(0);
   rectangle(1,1,201,201);
   setfillstyle(SOLID_FILL,5);
   bar(2,2,200,200);
   botao(6,177,36,196,"0",0,1);
   botao(40,177,72,196,"1",0,1);
   botao(76,177,109,196,"2",0,1);
   botao(113,177,146,196,"3",0,1);
   botao(6,150,36,171,"4",0,1);
   botao(40,150,72,171,"5",0,1);
   botao(76,150,109,171,"6",0,1);
   botao(113,150,146,171,"7",0,1);
   botao(6,123,36,146,"8",0,1);
   botao(40,123,72,146,"9",0,1);
   botao(76,123,109,146,"CE",0,1);
   botao(113,123,146,146,"OFF",0,1);


   ligamouse();
  getch();


  desligamouse();
}