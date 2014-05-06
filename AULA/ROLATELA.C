#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include "funcao.h"
union REGS out,sai;
main()
{
   int l=2,c=11;
   char tecla;
   textbackground(BLUE);                 /*YELLOW*/
   clrscr();

   textcolor(GREEN);      /*BLACK*/
  textbackground(RED);        /*WHITE*/

   borda(1,10,25,50);
   /*window(1, 10, 50, 25);*/
while(1){
   textbackground(BLUE);
   textcolor(GREEN);
   posc(l,c);
   printf("teste");
   switch(l)
   {
    case 24:
	    l=24;
	    tecla=getch();
	    if(tecla==27) break;
	    if(tecla==80)
	     {
	      out.h.ah=0x07;
	      out.h.al=1;
	      out.h.bh=7;
	      out.h.ch=23;
	      out.h.cl=10;
	      out.h.dh=23;
	      out.h.dl=48;
	      int86(0x10,&out,&out);

	     }
	    break;
    default:
	    l++;
	    break;

   }
} /* fim de while */
}




































/*

    case 1:
	    tecla=getch();
	    if(tecla==27) break;
	    if(tecla==0)
	     {
	      out.h.ah=0x06;
	      out.h.al=1;
	      out.h.ch=1;
	      out.h.cl=10;
	      out.h.dh=23;
	      out.h.dl=79;
	      int86(0x10,&out,&out);
	     }
	     l=23;
	    l=1;
	    break;
*/