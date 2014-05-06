#include<grafico.h>
#include <conio.h>
void main(void)
  {
	int lin,col,sta,lix=1,cox=1;
	clrscr();
	set_modo();
	mouse();
	while(!(kbhit()))
	{
		 lin=(linmouse()*8);
		 col=(colmouse()*8);
		 sta=status();
		 if(sta==2){
		   lix=lin;cox=col;}
		 while((lix!=lin|| cox!=col)&& sta==1){
		    lin=(linmouse()*8);
		    col=(colmouse()*8);
		    sta=status();
		    if(lix<lin)
		       lix++;
		    if(lix>lin)
		       lix--;
		    if(cox<col)
		       cox++;
		    if(cox>col)
		       cox--;
		    ponto(lix,cox,15); }
	  }
 }