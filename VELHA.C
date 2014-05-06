#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
int colmouse();
int linmouse();
int status(void);
void mouse (void);
void main(int argc,char *argv[])
{
  char m1[4],m2[4],m3[4],n1[12],n2[12];
  char camp='N',resp='s',re='s';
  int lx,cx,lo,co,ct=0,lin,col,sta,confct,x;
  if (argc==3)
  {
     for(x=0;*argv[1]!='\0'|| *argv[2]!='\0';x++,argv[1]++,argv[2]++){
	  n1[x] =toupper(*argv[1]);
	  n2[x] =toupper(*argv[2]);
	  if(!(n1[x]>='A' && n1[x]<='Z'))
	       n1[x]='\0';
	  if(!(n2[x]>='A' && n2[x]<='Z'))
	       n2[x]='\0'; }
    }
 while(re=='s'|| re=='S')
 {
  ct=0;
  resp='s';
  camp='N';
  clrscr();
  m1[0]=' ';
  m1[1]=' ';
  m1[2]=' ';
  m1[3]='\0';
  m2[0]=' ';
  m2[1]=' ';
  m2[2]=' ';
  m2[3]='\0';
  m3[0]=' ';
  m3[1]=' ';
  m3[2]=' ';
  m3[3]='\0';
  while(ct<9 && resp=='s')
   {
	confct=1;
	sta=0;
	clrscr();
	mouse();
	gotoxy(34,10);
	puts("     ³   ³  ");
	gotoxy(34,11);
	puts("  ÄÄÄÅÄÄÄÅÄÄÄ");
	gotoxy(34,12);
	puts("     ³   ³  ");
	gotoxy(34,13);
	puts("  ÄÄÄÅÄÄÄÅÄÄÄ");
	gotoxy(34,14);
	puts("     ³   ³ ");
	gotoxy(37,10);
	printf("%c",m1[0]);
	gotoxy(41,10);
	printf("%c",m1[1]);
	gotoxy(45,10);
	printf("%c",m1[2]);
	gotoxy(37,12);
	printf("%c",m2[0]);
	gotoxy(41,12);
	printf("%c",m2[1]);
	gotoxy(45,12);
	printf("%c",m2[2]);
	gotoxy(37,14);
	printf("%c",m3[0]);
	gotoxy(41,14);
	printf("%c",m3[1]);
	gotoxy(45,14);
	printf("%c",m3[2]);
	gotoxy(1,20);
      if (ct%2==0)
      {
	/*volta*/
	printf("\njogador %s clique na posicÆo desejada",n1);
	while(sta==0)
	 {
	   lx=linmouse();
	   cx=colmouse();
	   sta=status();
	 }
	 while(sta!=0)
	    sta=status();
	 if(lx==9)
	   {
	     if(cx==36 || cx==35 || cx==37)
	       {
		       if(m1[0]==' ')
			  m1[0]='X';
		       else
			  confct=0;
	       }
	     else
	     if(cx==40 || cx==39 || cx==41)
	       {
		       if(m1[1]==' ')
			  m1[1]='X';
		       else
		       confct=0;
	       }
	     else
	     if(cx==44 || cx==43 || cx==45)
	       {
		       if(m1[2]==' ')
			  m1[2]='X';
		       else
			  confct=0;
	       }
	     else confct=0;
	   }
	 else
	 if(lx==11)
	   {
	     if(cx==36 || cx==35 || cx==37)
	       {
		       if(m2[0]==' ')
			  m2[0]='X';
		       else
			  confct=0;
	       }
	     else
	     if(cx==40 || cx==39 || cx==41)
	       {
		       if(m2[1]==' ')
			  m2[1]='X';
		       else
			  confct=0;
	       }
	     else
	     if(cx==44 || cx==43 || cx==45)
	       {
		       if(m2[2]==' ')
			  m2[2]='X';
		       else
			  confct=0;
		}
	      else confct=0;
	   }
	 else
	 if(lx==13)
	   {
	     if(cx==36 || cx==35 || cx==37)
	       {
		       if(m3[0]==' ')
			  m3[0]='X';
		       else
			  confct=0;
	       }
	     else
	     if(cx==40 || cx==39 || cx==41)
	       {
		       if(m3[1]==' ')
			  m3[1]='X';
		       else
			  confct=0;
	       }
	     else
	     if(cx==44 || cx==43 || cx==45)
	       {
		       if(m3[2]==' ')
			  m3[2]='X';
		       else confct=0;
	       }
	     else confct=0;
	    }
	 else confct=0;
      }
      if(ct%2!=0)
      {
       /*volta*/
       printf("\njogador %s clique na posicÆo desejada",n2);
       while(sta==0)
	 {
	   lo=linmouse();
	   co=colmouse();
	   sta=status();
	 }
	 while(sta!=0)
	   sta=status();
	 if(lo==9)
	   {
	     if(co==36 || co==35 || co==37)
		       if(m1[0]==' ')
			  m1[0]='O';
		       else confct=0;
	     if(co==40 || co==39 || co==41)
		       if(m1[1]==' ')
			  m1[1]='O';
		       else confct=0;
	     if(co==44 || co==43 || co==45)
		       if(m1[2]==' ')
			  m1[2]='O';
		       else confct=0;
	   }
	 if(lo==11)
	   {
	     if(co==36 || co==35 || co==37)
		       if(m2[0]==' ')
			  m2[0]='O';
		       else confct=0;
	     if(co==40 || co==39 || co==41)
		       if(m2[1]==' ')
			  m2[1]='O';
		       else confct=0;
	     if(co==44 || co==43 || co==45)
		       if(m2[2]==' ')
			  m2[2]='O';
		       else confct=0;
	   }
	 if(lo==13)
	   {
	     if(co==36 || co==35 || co==37)
		       if(m3[0]==' ')
			  m3[0]='O';
		       else confct=0;
	     if(co==40 || co==39 || co==41)
		       if(m3[1]==' ')
			  m3[1]='O';
		       else confct=0;
	     if(co==44 || co==43 || co==45)
		       if(m3[2]==' ')
			  m3[2]='O';
		       else confct=0;
	    }

      }
     if (confct==1)
	  ct++;
     if(m1[0]=='X' && m1[1]=='X' && m1[2]=='X'|| m2[0]=='X' && m2[1]=='X' && m2[2]=='X' || m3[0]=='X' && m3[1]=='X' && m3[2]=='X'|| m1[0]=='X' && m2[1]=='X' && m3[2]=='X'|| m1[2]=='X' && m2[1]=='X' && m3[0]=='X'|| m1[0]=='X' && m2[0]=='X' && m3[0]=='X'|| m1[1]=='X' && m2[1]=='X' && m3[1]=='X'|| m1[2]=='X' && m2[2]=='X' && m3[2]=='X')
       {	 camp='X';
		 resp='n';
       }
     if(m1[0]=='O' && m1[1]=='O' && m1[2]=='O'|| m2[0]=='O' && m2[1]=='O' && m2[2]=='O'|| m3[0]=='O' && m3[1]=='O' && m3[2]=='O'|| m1[0]=='O' && m2[1]=='O' && m3[2]=='O'|| m1[2]=='O' && m2[1]=='O' && m3[0]=='O'|| m1[0]=='O' && m2[0]=='O' && m3[0]=='O'|| m1[1]=='O' && m2[1]=='O' && m3[1]=='O'|| m1[2]=='O' && m2[2]=='O' && m3[2]=='O')
       {	 camp='O';
		 resp='n';
       }
   }
	gotoxy(37,10);
	printf("%c",m1[0]);
	gotoxy(41,10);
	printf("%c",m1[1]);
	gotoxy(45,10);
	printf("%c",m1[2]);
	gotoxy(37,12);
	printf("%c",m2[0]);
	gotoxy(41,12);
	printf("%c",m2[1]);
	gotoxy(45,12);
	printf("%c",m2[2]);
	gotoxy(37,14);
	printf("%c",m3[0]);
	gotoxy(41,14);
	printf("%c",m3[1]);
	gotoxy(45,14);
	printf("%c",m3[2]);

	if(camp=='N')
	   puts("\nNÆo houve vencedor!");
	else
	   if(camp=='X')
	      printf("\nO vencedor ‚ %s",n1);
	   else if(camp=='O')
	      printf("\nO vencedor ‚ %s",n2);
	getch();
	gotoxy(1,22);
	puts("jogar outro(s/n)");
	re=getche();
	 }
}

 int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx/8);

  }

int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx/8);
  }
void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
int status(void)
{
     union REGS regs;
     regs.x.ax=3;
     int86(0x33,&regs,&regs);
     return(regs.x.bx);
}
