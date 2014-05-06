#include <stdio.h>
#include <conio.h>
void main()
{
  int l=1,sair=1;
  char a='>',b=' ',c=' ',tc=' ';
  clrscr();
	       textattr(0+((14+1)<<4));
	       gotoxy(10,10);cprintf(" %c INCLUSAO\n",a);
	       textattr(1+((0+0)<<4));
	       gotoxy(10,11);cprintf(" %c consulta\n",b);
	       gotoxy(10,12);cprintf(" %c sair\n",c);

  while(sair==1)
  {
    gotoxy(10,22);printf("Use setas para navegar...");


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
      case 1:  a='>';
	       b=c=' ';
	       textattr(0+((14+1)<<4));
	       gotoxy(10,10);cprintf(" %c INCLUSAO\n",a);
	       textattr(1+((0+0)<<4));
	       gotoxy(10,11);cprintf(" %c consulta\n",b);
	       gotoxy(10,12);cprintf(" %c sair\n",c);
	       break;
      case 2: b='>'; a=c=' ';
	      // textcolor(15);
	      // textbackground(0);
	       gotoxy(10,10);cprintf(" %c INCLUSAO\n",a);
	       textattr(0+((14+1)<<4));
	       gotoxy(10,11);cprintf(" %c consulta\n",b);
	      textattr(1+((0+0)<<4));
	      // textcolor(0);
	       //textbackground(15);
	       gotoxy(10,12);cprintf(" %c sair\n",c);
	       //textcolor(15);
	       //textbackground(0);

	      break;
      case 3: c='>'; b=a=' ';
	      // textcolor(15);
	      // textbackground(0);

	       gotoxy(10,10); cprintf(" %c INCLUSAO\n",a);
	       gotoxy(10,11); cprintf(" %c consulta\n",b);
	       textattr(0+((14+1)<<4));
	       gotoxy(10,12); cprintf(" %c sair\n",c);
	       textattr(1+((0+0)<<4));

	      break;
    }
  }
}

