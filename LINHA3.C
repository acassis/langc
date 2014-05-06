#include<grafico.h>
#include <conio.h>
#include <graphics.h>
void main(void)
  {
	int lin,col,sta;
	clrscr();
	set_modo();
	mouse();
	while(!(kbhit()))
	{
		 lin=(linmouse()*8);
		 col=(colmouse()*8);
		 sta=status();
		 if(sta==2)
		   getpixel(lin,col);

	  }
 }