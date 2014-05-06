#include <math.h>
void main()
{  int col=1,lin=1;
   clrscr();
   while(!kbhit())
   {
       if(col>-79)
          col--;
        else
           col = 78;

       if(lin>-24 )
          lin--;
        else
           lin = 23;

        gotoxy(abs(col)+1,abs(lin)+1);
        textcolor(col);
        cprintf("Û");
        delay(100);
   }
}