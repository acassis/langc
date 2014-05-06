#include <conio.h>
#include <stdio.h>
#include <dos.h>
#define limpa        printf("\x1b[2J"])
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

void main(void)
{
  char h='s',v='s',*nome;
  int lin=0,col=0,lims,coms;
  clrscr();
  //nome=getpass("Digite sua senha:");
  //printf("%s",nome);
  while(!(kbhit())){
       /*clrscr();*/
       _setcursortype(0);
       lims=linmouse();
       coms=colmouse();
       mouse();
       if(h=='s')
	  lin++;
       if(h==' ')
	  lin--;
       if(v=='s')
	  col++;
       if(v==' ')
	  col--;
	if(lin==lims && col==coms){
	   if(h=='s' && v=='s')
	      v=' ';
	    if(h=='s' && v==' ')
	      v='s';
	     if(h==' ' && v=='s')
		h='s';
	       if(h==' ' && v==' ')
		  h=' ';}

	if(lin>23)
	   h=' ';
	 if(lin<2)
	   h='s';
	 if(col>78)
	    v=' ';
	 if(col<2)
	    v='s';
	  gotoxy(col,lin);
	  printf("");
	  delay(5);
      }
}