#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include<grafico.h>
void main()
{
  int lin=0,col=0,sta=0;
  char fim;
  clrscr();
  //moldura();
  printf("                                FIM");
  while(!(lin==24&&sta==1&&(col==41||col==42||col==43)))
  {
  mouse();
  lin=linmouse()*8;
  col=colmouse()*8;
  sta=status();
  gotoxy(10,25);

  if(lin==24&&sta==1&&(col==41||col==42||col==43))
     fim='s';
  gotoxy(5,25);
  printf("%d",lin);
  printf("                %d",col);
  }
}
