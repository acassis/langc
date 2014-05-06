#include <stdio.h>
#include <conio.h>
void main()
{
  int l=1,sair=1;
  char a='>',b=' ',c=' ',tc=' ';

  while(sair==1)
  {
    clrscr();

    printf(" %c INCLUSAO\n",a);
    printf(" %c consulta\n",b);
    printf(" %c sair\n",c);
    printf("Use setas para navegar...");

    tc=getch();

    if(l==3 && tc==13)
    {  sair=0;
      continue;}

    if(tc==80)
      l++;
    if(tc==72)
      l--;

    if(l>3)
      l=1;
    if(l<1)
      l=3;

    switch(l)
    {
      case 1: a='>'; b=c=' '; break;
      case 2: b='>'; a=c=' '; break;
      case 3: c='>'; b=a=' '; break;
    }
  }
}

