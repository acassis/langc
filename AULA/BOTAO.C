#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
union REGS in,out;


struct botao2{
	int x1,y1,x2,y2,cs,as,xc,yc,xy;
	char *texto;
	void inicializa(int a,int b,int c,int d,char *s)
	{
		x1=a;y1=b;
		x2=c;y2=d;
		texto=s;
		cs=textwidth(s);
		as=textheight(s);
		xc=(((x2-x1)-cs)/2)+x1;
		yc=(((y2-y1)-as)/2)+y1;
		}
		void exibe(void)
		{
			rectangle(x1,y1,x2,y2);
			outtextxy(xc,yc,texto);
			}
};

int testa_botao(int li, int ci, int lf, int cf)
{
	 union REGS i,out;
	 i.x.ax=3;
	 int86(0x33,&i,&out);
	 if(out.x.cx >= ci && out.x.cx <= cf && out.x.dx>= li && out.x.dx <= lf)
		 return(1);
	 else
		 return(0);
}


void main(void)
{

	 /* request autodetection */
	 int gdriver = DETECT, gmode, errorcode;
	 int x, y,t,f;


	 /* initialize graphics and local variables */
	 initgraph(&gdriver, &gmode, "c:\\arquiv~1\\bc\\bgi");

	 /* read result of initialization */
	 errorcode = graphresult();
	 if (errorcode != grOk)  /* an error occurred */
	 {
			printf("Graphics error: %s\n", grapherrormsg(errorcode));
			printf("Press any key to halt:");
			getch();
			exit(1); /* terminate with an error code */
	 }





	botao2 b1;
	b1.inicializa(250,270,270,290,"ok");
	b1.exibe();
	in.x.ax=1;
	int86(0x33,&in,&out);

	while(!kbhit())
	{
	in.x.ax=5;
	in.x.bx=0;
	int86(0x33,&in,&out);
	if(out.x.bx!=0)
	  if(testa_botao(250,270,270,290)) //_> modo texto
	   {  printf("sair" );
	      getch();exit(1);}
	in.x.ax=3;
	int86(0x33,&in,&out);
	gotoxy(10,23);
	printf("%03d - %03d",out.x.cx,out.x.dx);
	}




	closegraph();
}