#include<grafico.h>
#include <conio.h>
void main(void)
  {
	int li,co,sta,stant;
	clrscr();
	set_modo();
	botao(300,200,330,230,1);
	while(!(kbhit()))
	{
		 mouse();
		 li=(linmouse()*8);
		 co=(colmouse()*8);
		 stant=sta;
		 sta=status();
		 if(co>=300 && co<=330 && li>=200 && li<=230 && stant==1 && sta==0){
		    botao(300,200,330,230,1);}
		 else
		   if(co>=300 && co<=330 && li>=200 && li<=230 && sta==1)
		   botao(300,200,330,230,0);

	}
}

