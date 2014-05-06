#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx);

  }
void desliga (void)
{
union REGS regs;
      regs.x.ax=2;
      int86(0x33,&regs,&regs);
}

int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx);
  }

void main()
{
      int gdriver = DETECT, gmode,x,y,xant,yant,raio = 100;
      float seno,coseno,hipotenusa,col,lin;
      char ch=0;
      initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
      mouse();
      while(!kbhit())
      {
	 col = colmouse();
	 lin = linmouse();
	 col-=320;         //Transforma a tela em coordenadas absolutas
	 lin-=240;

	 hipotenusa = col*col + lin*lin; //Teorema de Pitagoras
	 hipotenusa = sqrt(hipotenusa);

	 seno   = lin/(hipotenusa+0.000001);//Some 0.000001 p/ impedir divisao
	 coseno = col/(hipotenusa+0.000001);//por zero!
	 x = raio * coseno;
	 y = raio * seno;

	 if(xant!=x || yant !=y)  //Se mudou de posicao
	 {
		 desliga();
		 setcolor(0);
		 line(320,240,320+xant,240+yant);
		 circle(320+xant,240+yant,10);
		 setcolor(15);
		 line(320,240,320+x,240+y);
		 circle(320+x,240+y,10);
		 mouse();
	 }
	 xant = x;
	 yant = y;
      }
      closegraph();
}
