#include <retangul.h>
#define maxlin 480
#define maxcol 640

void main (void)
{
 int nr;
 set_modo();
 for(nr=0;nr<100;nr+=3){
     retangulo(0+nr,0+nr,479-nr,639-nr,(nr-2)%15);
     }
	  getch();
}