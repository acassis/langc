//----------------------------------------------------------------------------
//Programa: Calma.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Com este programa voce edita um cursor para o mouse, o cursor e'
//exibido no mouse e salvo num arquivo let.c
//-----------------------------------------------------------------------------
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>
FILE *s;
void controle();
void salva();
char escreve(void);
char ch;
void desliga (void)
{
      union REGS regs;
      regs.x.ax=2;
      int86(0x33,&regs,&regs);
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
void mudamouse(unsigned segimag,unsigned offimag,unsigned lin,unsigned col)
{
  union REGS regs;
  struct SREGS sregs;
  regs.x.ax=0x09;
  regs.x.bx=col;
  regs.x.cx=lin;
  sregs.es=segimag;
  regs.x.dx=offimag;
  int86x(0x33,&regs,&regs,&sregs);
}
typedef struct imagem
{
  unsigned imag[32];
  int lin,col;
}imagem;

imagem barra = { {
0xffff,0xffff,0xffff,0xffff,
0xffff,0xffff,0xffff,0xffff,
0xffff,0xffff,0xffff,0xffff,
0xffff,0xffff,0xffff,0xffff,

0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000},7,7};

int mt[16][16],i,j;
void main()
{
   int gdriver = DETECT, gmode,lin=40,col=16,sta,stant,ml1[16],ml2[16],mc1[16],mc2[16];
   for(j=0;j<16;j++)
     for(i=0;i<16;i++)
	mt[j] [i]=0;
   i=0;j=0;
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");
   for(lin=40;lin<=440;lin=lin+25,i++){
      line(120,lin,520,lin);
      if(lin<440){
	 ml1[i]=lin;
	 if(i>0)
	   ml2[i-1]=ml1[i];}}
   ml2[15]=440;
   i=0;
   for(col=120;col<=520;col=col+25,i++){
     line(col,40,col,440);
     if(col<520){
	mc1[i]=col;
	if(i>0)
	   mc2[i-1]=mc1[i];}}
   mc2[15]=520;
   mouse();
   while(!(kbhit())){
	stant=sta;
	lin=(linmouse()*8);
	col=(colmouse()*8);
	sta=status();
      if(lin>40 && lin<440){
	for(i=0;lin>ml1[i] ^ lin<ml2[i];i++);}
      if(col>120 && col<520 && col!=320){
	for(j=0;col>mc1[j] ^ col<mc2[j];j++);}
      if(lin>=ml1[i] && lin<=ml2[i] && col>=mc1[j] && col<=mc2[j] ){
	    if(/*stant==0 &&*/ sta==1){
	      desliga();
	      bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);
	      mouse();
	      mt[j][i]=1;}
	    else if(stant==0 && sta==2){
		 setfillstyle( SOLID_FILL,0);
		 desliga();
		 bar(mc1[j]+2,ml1[i]+2,mc2[j]-2,ml2[i]-2);
		 mouse();
		 mt[j][i]=0;
		 setfillstyle( SOLID_FILL,15);}}

  }
  controle();
  desliga();
  cleardevice();
  mudamouse(_DS,(unsigned)barra.imag,7,7);
  mouse();
  while(getch()!=27);
  salva();
  closegraph();
}
void salva(void)
{
   char nome[]="";
   printf("\nDigite o nome do cursor:");
   flushall();
   gets(nome);
   if(nome[0]>=65){
   if ((s=fopen("let.h","r+"))==NULL)
   {  printf("\nArquivo nao pode ser criado.");
      return; }
   do
   {
      ch = fgetc(s);
   } while (ch != EOF);
   fprintf(s,"\n\nstruct imagem %s = { {\n",nome);
   for(i=0;i<16;i++){
      for(j=0;j<16;j++){
      ch=escreve();
      if(ch=='0')
	 ch='f';
      else if(ch=='1')
	 ch='e';
      else if(ch=='2')
	 ch='d';
      else if(ch=='3')
	 ch='c';
      else if(ch=='4')
	 ch='b';
      else if(ch=='5')
	 ch='a';
      else if(ch=='6')
	 ch='9';
      else if(ch=='7')
	 ch='8';
      else if(ch=='8')
	 ch='7';
      else if(ch=='9')
	 ch='6';
      else if(ch=='a')
	 ch='5';
      else if(ch=='b')
	 ch='4';
      else if(ch=='c')
	 ch='3';
      else if(ch=='d')
	 ch='2';
      else if(ch=='e')
	 ch='1';
      else if(ch=='f')
	 ch='0';
      if(j==0 || j==4 || j==8 || j==12){
	if(j==0)
	   if(i==0 || i==4 || i==8 || i==12)
	      fprintf(s, "0x%c",ch);
	   else
	      fprintf(s, ",0x%c",ch);
	else{
	     fprintf(s, "%c",ch);}}}
      if(i==3 || i==7 || i==11 || i==15)
	fprintf(s,",\n");}
   fprintf(s,"\n");
   for(i=0;i<16;i++){
      for(j=0;j<16;j++){
      if(j==0 || j==4 || j==8 || j==12){
	if(j==0)
	   if(i==0 || i==4 || i==8 || i==12)
	      fprintf(s, "0x%c",escreve());
	   else
	      fprintf(s, ",0x%c",escreve());
	else{
	     fprintf(s, "%c",escreve());}}}
      if(i==3 || i==7 || i==11)
	fprintf(s,",\n");}
   fprintf(s,"},7,7};        ");
   fclose(s); }
}

void controle()
{
  long int acum=0,i,j;
  for(j=0;j<32;j++)
  {
   acum = 0;
   for(i=0;i<16;i++)
    {
       if(j<16)
	acum=acum+(mt[i][j]) * (int)pow(2,15-i);
       else
	acum=acum+(mt[i][j-16]) * (int)pow(2,15-i);
    }
   if(j<16)
    barra.imag[j]=32767-acum;
   else
    barra.imag[j]=acum;
  }
}
char escreve(void)
{
      if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==1)
	      return 'f';
      else if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==0)
	      return 'e';
      else if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==1)
	      return 'd';
      else if(mt[j][i]==1 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==0)
	      return 'c';
      else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==1)
	      return 'b';
      else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==0)
	      return 'a';
      else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==1)
	      return '9';
      else if(mt[j][i]==1 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==0)
	      return '8';
      else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==1)
	      return '7';
      else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==1 && mt[j+3][i]==0)
	      return '6';
      else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==1)
	      return '5';
      else if(mt[j][i]==0 && mt[j+1][i]==1 && mt[j+2][i]==0 && mt[j+3][i]==0)
	      return '4';
      else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==1)
	      return '3';
      else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==1 && mt[j+3][i]==0)
	      return '2';
      else if(mt[j][i]==0 && mt[j+1][i]==0 && mt[j+2][i]==0 && mt[j+3][i]==1)
	      return '1';
      else return '0';
}

