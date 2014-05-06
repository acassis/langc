//----------------------------------------------------------------------------
//Programa: Desenha.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Desenha caracteres p/ formar linhas
//-----------------------------------------------------------------------------
#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80
#define DIR_DES /*187*/ 191
#define DIR_SOB /*188*/ 217
#define ESQ_SOB /*200*/ 192
#define ESQ_DES /*201*/ 218
#define DES_ESQ /*188*/ 217
#define DES_DIR /*200*/ 192
#define SOB_ESQ /*187*/ 191
#define SOB_DIR /*201*/ 218
#define HOR /*205*/ 196
#define VER /*186*/ 179
void main(void)
{
	int tecla,x=1,y=1,ct=-1;
	char ult='r';
	clrscr();

	while((tecla=getch())==0)
	{
		 /*_setcursortype(0);*/
		 tecla=getch();
		 ct++;
		 switch (tecla){
			 case SETA_ESQ:
			      gotoxy(x,y);
			      if(ct!=0){
			      if(ult=='s')
				 putch(SOB_ESQ);
			      if(ult=='d')
				 putch(DES_ESQ);  }
			      if(x>1)
				x--;
			      gotoxy(x,y);
			      putch(HOR);
			      ult='e';
			      break;

			 case SETA_DIR:
			      gotoxy(x,y);
			      if(ct!=0){
			      if(ult=='s')
				putch(SOB_DIR);
			      if(ult=='d')
				putch(DES_DIR);  }
			      if(x<80)
				 x++;
			      gotoxy(x,y);
			      putch(HOR);
			      ult='r';
			      break;

			 case SETA_SOBE:
			      gotoxy(x,y);
			      if(ct!=0){
			      if(ult=='e')
				putch(ESQ_SOB);
			      if(ult=='r')
				putch(DIR_SOB);}
			      if(y>1)
				 y--;
			      gotoxy(x,y);
			      putch(VER);
			      ult='s';
			      break;

			 case SETA_DESCE:
			      gotoxy(x,y);
			      if(ct!=0){
			      if(ult=='e')
				putch(ESQ_DES);
			      if(ult=='r')
				putch(DIR_DES); }
			      if(y<24)
				 y++;
			      gotoxy(x,y);
			      putch(VER);
			      ult='d';
			      break;

			 }
	}
}
