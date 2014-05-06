#include <conio.h>
#include <stdio.h>
#include <dos.h>
#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80
void main(void)
{
  char h=' ',v=' ',ch;
  float acel=400;
  int matcol [16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},matlin [16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  char nome[]="HELEM CAROLINA";
  int lin=25,col=79,i,acl=0,ct=0;
  clrscr();
  while(v!='f'){
       _setcursortype(0);
       if(kbhit())
       {
	 ch=getch();
	 if(ch==SETA_DIR)
	    v='s';
	 if(ch==SETA_ESQ)
	    v=' ';
	 if(ch==SETA_SOBE)
	    h=' ';
	 if(ch==SETA_DESCE)
	    h='s';
	 if(ch==27)
	    v='f';
       }
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
	 matcol[15]=col;
	 matlin[15]=lin;
	 for(i=0;i<15;i++)
	   matcol[i]=matcol[i+1];
	 for(i=0;i<15;i++)
	   matlin[i]=matlin[i+1];
	 gotoxy(matcol[14],matlin[14]);
	 textcolor(1);
	 cprintf("%c",nome[0]);
	 gotoxy(matcol[13],matlin[13]);
	 textcolor(2);
	 cprintf("%c",nome[1]);
	 gotoxy(matcol[12],matlin[12]);
	 textcolor(4);
	 cprintf("%c",nome[2]);
	 gotoxy(matcol[11],matlin[11]);
	 textcolor(5);
	 cprintf("%c",nome[3]);
	 gotoxy(matcol[10],matlin[10]);
	 textcolor(6);
	 cprintf("%c",nome[4]);
	 gotoxy(matcol[9],matlin[9]);
	 textcolor(7);
	 cprintf("%c",nome[5]);
	 gotoxy(matcol[8],matlin[8]);
	 textcolor(8);
	 cprintf("%c",nome[6]);
	 gotoxy(matcol[7],matlin[7]);
	 textcolor(9);
	 cprintf("%c",nome[7]);
	 gotoxy(matcol[6],matlin[6]);
	 textcolor(10);
	 cprintf("%c",nome[8]);
	 gotoxy(matcol[5],matlin[5]);
	 textcolor(11);
	 cprintf("%c",nome[9]);
	 gotoxy(matcol[4],matlin[4]);
	 textcolor(12);
	 cprintf("%c",nome[10]);
	 gotoxy(matcol[3],matlin[3]);
	 textcolor(13);
	 cprintf("%c",nome[11]);
	 gotoxy(matcol[2],matlin[2]);
	 textcolor(14);
	 cprintf("%c",nome[12]);
	 gotoxy(matcol[1],matlin[1]);
	 textcolor(15);
	 cprintf("%c",nome[13]);
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