#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
void janela(int a,int b,int x,int z,int k,int fl,int f,int ch,int cha)
{ int c,l,m,n;
 textcolor(cha);
  textbackground(f);
  for(c=b;c<=z;c++)
   for(l=a;l<=x;l++)
     {
       gotoxy(c,l);
       cprintf("%c",ch);
     }
    textcolor(k);
  textbackground(fl);
     for(l=a;l<=x;l++)
    {
       gotoxy(b,l);
       cprintf("%c",186);
       gotoxy(z,l);
       cprintf("%c",186);
    }
  for(c=b;c<=z;c++)
    {  gotoxy(c,a);
       cprintf("%c",205);
       gotoxy(c,x);
       cprintf("%c",205);
    }
  gotoxy(b,a);
  cprintf("%c",201);
  gotoxy(z,x);
  cprintf("%c",188);
  gotoxy(b,x);
  cprintf("%c",200);
  gotoxy(z,a);
  cprintf("%c",187);

}


void main( void )
{
 int sorte,tx=-1,i=0,f,max=101;
 char sair='s';
 while(sair=='s')
 {
  i=0;
  randomize();
  sorte=random(100);
  f=max;
  max+=100;
  while(1)
  {
    clrscr();
   textmode(C80);
   janela(1,1,24,80,6,18,165,178,0);
   /* printf("%dsorte %dtx %d ",sorte,tx,random(100));*/
       textmode(C80);
   janela(9,7,16,72,10,142,777,688,149);
    gotoxy(15,12);
    textmode(C80);
     textbackground(185);
     textcolor(0);
    cprintf("%d__________________?________________%5d ",i,f);
    gotoxy(13,14);
    cprintf("adivinhe o numero entre%d a %5d==>",i,f);
    textbackground(15);
     textcolor(367);

   cscanf("%d",&tx);
    if(tx<sorte)
      i=tx;
    if(tx>sorte)
      f=tx;
    if(sorte==tx||tx==-1)
       break;
    else
     {
       textmode(C80);
       janela(11,15,15,58,14,31,24,179,171);
       textbackground(9);
       textcolor(142);
       gotoxy(25,13);
       cprintf("#############ERRADO##########");
      }
    getche();
    getche();
    tx=-1;
   } if(tx==-1)
   {  textmode(C40);
      janela(9,1,14,40,9,10,142,688,171);
     textbackground(168);
     textcolor(142);
     gotoxy(10,11);
     cprintf("!!!!!!!!!EXIT!!!!!!!!!!!");
     gotoxy(18,10);
    cprintf("%c%c %d %c%c ",16,16,sorte,17,17);
     delay(5000);
    break;
    }
     else
     {
     textmode(C80);
     janela(9,10,18,68,9,10,142,688,171);
     textbackground(168);
     textcolor(142);
     gotoxy(38,11);
     cprintf("!!%4d!!",sorte);
     gotoxy(28,13);
   cprintf("!!!!!!!!!certo!!!!!!!!!!!");
   gotoxy(24,15);
   cprintf("SE DESEJA CONTINUAR TECLE (S/N)? ");
  sair=getche();
  getch();
  }
}
}