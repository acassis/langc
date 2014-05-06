#include <conio.h>
#include <stdio.h>
#include <dos.h>
void main(void)
{
  char h=' ',v=' ';
  float acel=400;
  int matcol [15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},matlin [15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  char nome[]="ALAN CARVALHO";
  int lin=25,col=79,i,acl=0,ct=0;
  clrscr();
  while(1){
       _setcursortype(0);
       /*x=wherex();
       y=wherey();
       gotoxy(40,30)*/
       if(h=='s')
	  lin++;
       if(h==' ')
	  lin--;
       if(v=='s')
	  col++;
       if(v==' ')
	  col--;
	if(lin>24)
	   h=' ';
	 if(lin<2)
	   h='s';
	 if(col>79)
	    v=' ';
	 if(col<2)
	    v='s';
	 matcol[14]=col;
	 matlin[14]=lin;
	 for(i=0;i<14;i++)
	   matcol[i]=matcol[i+1];
	 for(i=0;i<14;i++)
	   matlin[i]=matlin[i+1];
	 gotoxy(matcol[13],matlin[13]);
	 textcolor(1);
	 cprintf("%c",nome[0]);
	 gotoxy(matcol[12],matlin[12]);
	 textcolor(2);
	 cprintf("%c",nome[1]);
	 gotoxy(matcol[11],matlin[11]);
	 textcolor(4);
	 cprintf("%c",nome[2]);
	 gotoxy(matcol[10],matlin[10]);
	 textcolor(5);
	 cprintf("%c",nome[3]);
	 gotoxy(matcol[9],matlin[9]);
	 textcolor(6);
	 cprintf("%c",nome[4]);
	 gotoxy(matcol[8],matlin[8]);
	 textcolor(7);
	 cprintf("%c",nome[5]);
	 gotoxy(matcol[7],matlin[7]);
	 textcolor(8);
	 cprintf("%c",nome[6]);
	 gotoxy(matcol[6],matlin[6]);
	 textcolor(9);
	 cprintf("%c",nome[7]);
	 gotoxy(matcol[5],matlin[5]);
	 textcolor(10);
	 cprintf("%c",nome[8]);
	 gotoxy(matcol[4],matlin[4]);
	 textcolor(11);
	 cprintf("%c",nome[9]);
	 gotoxy(matcol[3],matlin[3]);
	 textcolor(12);
	 cprintf("%c",nome[10]);
	 gotoxy(matcol[2],matlin[2]);
	 textcolor(13);
	 cprintf("%c",nome[11]);
	 gotoxy(matcol[1],matlin[1]);
	 textcolor(14);
	 cprintf("%c",nome[12]);
	 gotoxy(matcol[0],matlin[0]);
	 printf(" ");
	 delay(acel);
	 if(acel<6){
	   acl=2;
	   acel=10;}
	 if(acel>200)
	   acl=0;
	  if(acl==1)
	    acel+=1;
	  if(acl==0)
	    acel-=5;
	  if(acl==2)
	     ct++;
	  if(ct>500){
	    acl=1;
	    ct=0;}
      }
      _setcursortype(2);
}