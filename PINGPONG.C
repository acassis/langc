#include <conio.h>
#include <stdio.h>
#include <dos.h>
void main(void)
{
  char h='s',v='s';
  int lin=1,col=1,x,y,acel=230;
  clrscr();
  while(!(kbhit())){
       _setcursortype(0);
       /*x=wherex();
       y=wherey();
       gotoxy(40,30)*/
       if(h=='s')
	  lin++;
       if(h==' ')
	  lin--;
       if(v=='s')
	  col++;
       if(v==' ')
	  col--;
	if(lin>24)
	   h=' ';
	 if(lin<2)
	   h='s';
	 if(col>78)
	    v=' ';
	 if(col<2)
	    v='s';
	 if(h=='s')
	    acel=acel-10;
	 if(h==' ')
	    acel=acel+10;
	  gotoxy(col,lin);
	  printf("");
	  delay(acel);
	  clrscr();
      }
}