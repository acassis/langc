#include <stdio.h>
#include <conio.h>

/* retorna 1,0 ou -1*/
int car(char a)
{
  if(a>='a'&& a<='z')
     return(0);
  else if(a>='A'&& a<='Z')
          return(1);
       else
          return(-1);
}
main()
{ char a;
   clrscr();
  printf("\n\n%d",car( getche(a) ) );
  getch();
}