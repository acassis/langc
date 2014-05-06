#include<iostream.h>
#include <conio.h>
void main ()
{
  int j,i;
  clrscr();
  for(i=0;i<24;i++)
    for(j=0;j<80;j++)
     {
	if(i==0 || i==23)
	  {  gotoxy(j,i);
	     cout<<'ð';}
	if((i>0 && i<23) && (j==0 || j==23))
	  {  gotoxy(j,i);
	     cout<<'³';}
     }
}


