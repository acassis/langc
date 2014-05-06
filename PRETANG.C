#include <retangul.h>
#define maxlin 480
#define maxcol 640

void main (void)
{
 int nr,lin,col;
 set_modo();
 for(lin=9;lin<maxlin;lin+=40)
    for(col=9;col<maxcol;col+=40)
       for(nr=0;nr<=12;nr+=3)
	  retangulo(lin+nr,col+nr,lin+30,col+30-nr,(nr-2)%15);
	  getch();
}