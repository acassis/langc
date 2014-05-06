#include <stdlib.h>
void main()
{
  int x=0,y=0;
  char *p;
  clrscr();
  while(!kbhit())
  {
     x++;
     y++;
     if(y>24)
	y=0;
      if(x>78)
	 x=0;
      if((y==1 && x>1 && x<79) || (x==1 && y>0 && y<24))
       {
	 textcolor(random(15)+1);
	 gotoxy(x,y);
	 cprintf("лл");
       }
      gotoxy(x,y);
      printf(" ");
  }
}