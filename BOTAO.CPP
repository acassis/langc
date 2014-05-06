//leandro 822-7983
#include<graphics.h>
#include <math.h>
void mouse (void)
{
   asm mov ax,1
   asm int 0x33
}
int colmouse (void)
{
   asm mov ax,3
   asm int 0x33
   return (_CX);

}

int linmouse (void)
{
   asm mov ax,3
   asm int 0x33
   return (_DX);
}
int status(void)
{
     asm mov ax,3
     asm int 0x33
     return(_BX);
}
void botao(int x1,int y1,int x2,int y2,int sta,char caption[100])
{
  if(sta==0){
  setcolor(0);
  setfillstyle(1,8);
  bar(x1-2,y1-2,x2,y2+1);
  setcolor(7);
  line(x1-1,y1-1,x1-1,y2);
  line(x1-2,y1-2,x1-2,y2);
  line(x1,y1-1,x2,y1-1);
  line(x1-1,y1-2,x2,y1-2);
  setcolor(0);
  line(x2-1,y1-1,x2-1,y2);
  line(x2,y1-2,x2,y2);
  line(x1-1,y2,x2,y2);
  line(x1-2,y2+1,x2,y2+1);
  setcolor(15);
  outtextxy((x1+x2)/2 - (textwidth(caption)/2), (y1+y2)/2 - (textheight(caption)/2), caption);
  }
  else{
  setfillstyle(1,8);
  setcolor(8);
  bar(x1,y1,x2,y2);
  setcolor(7);
  line(x2-1,y1-1,x2-1,y2);
  line(x2,y1-2,x2,y2);
  line(x1-1,y2,x2,y2);
  line(x1-2,y2+1,x2,y2+1);
  setcolor(0);
  line(x1-1,y1-1,x1-1,y2);
  line(x1-2,y1-2,x1-2,y2);
  line(x1,y1-1,x2,y1-1);
  line(x1-1,y1-2,x2,y1-2);
  setcolor(15);
  outtextxy((x1+x2)/2 - (textwidth(caption)/2) + 1, (y1+y2)/2 - (textheight(caption)/2) + 1, caption);
  }
}
void desliga (void)
{
      asm mov ax,2
      asm int 0x33
}
void mousexy(int col,int lin)
{
    asm mov ax,4
    asm mov dx,lin
    asm mov cx,col
    asm int 0x33
}
void mudamouse(unsigned segimag,unsigned offimag,unsigned lin,unsigned col)
{
  asm mov ax,0x09
  asm mov bx,col
  asm mov cx,lin
  asm mov ES,&segimag
  asm mov dx,offimag
  asm int 0x33
}
struct imagem
{
  unsigned imag[32];
  int lin,col;
};
void main(void)
{
  int sta,drive=DETECT,modo;
  int altr, cpmt, x1 = 200, y1 = 200, x2 = 250, y2 = 220;
  int x, y, xant, yant, xini, yini,var;
  char msg[]="Sair!";
  initgraph(&drive,&modo,"c:\\bc\\bgi");
  mouse();
  mousexy(320,240);
  botao(x1,y1,x2,y2,0,msg);
  sta = 0;
  while(1)
  {
    sta = status();
    x = colmouse();
    y = linmouse();
    if(sta == 1 && x>=x1 && x<=x2 && y>=y1 && y<=y2) //se clicou sobre o botao
    {
      desliga();
      botao(x1,y1,x2,y2,1,msg);
      mouse();
      xini = colmouse();
      yini = linmouse();
      setwritemode(1);
      altr = 0;
      cpmt = 0;
      var = 0;
      while((sta = status())==1)// enquanto o botao esquerto estiver press!
      {
	 xant = x;
	 yant = y;
	 x = colmouse();
	 y = linmouse();
	 if(xant!=x || yant!=y) //olha se o cursor moveu!
	 {
	   desliga();

	   if(var!=0)
	   {
	    setcolor(7);        //apaga o retangulo anterior!
	    rectangle(x1 - cpmt, y1 - altr, x2 - cpmt, y2 - altr);
	   }
	   altr = yini - y;   //atualiza o deslocamento
	   cpmt = xini - x;

	   setcolor(7);      //impreme um retangulo na nova posicao!
	   rectangle(x1 - cpmt, y1 - altr, x2 - cpmt, y2 - altr);
	   mouse();
	   var = 1;
	 }
      }
      altr = yini - y;
      cpmt = xini - x;

      if(altr==0 && cpmt==0) //se nao moveu o botao(se clicou) sai!
	 return;

      setwritemode(0);
      desliga();
      setfillstyle(1,0);
      bar(x1-2,y1,x2,y2+1);
      x1 -= cpmt;
      x2 -= cpmt;
      y1 -= altr;
      y2 -= altr;
      botao(x1,y1,x2,y2,0,msg);
      mouse();
    }
  }
}