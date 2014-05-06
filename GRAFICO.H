#include<dos.h>
#define imprponto 0x0c
#define maxlin 480
#define maxcol 640
#define setmodo 0x00

void set_modo(void)
{
  union REGS regs;
  regs.h.ah=setmodo;
  regs.h.al=18;
  int86(0x10,& regs,& regs);
}
void set_modo4(void)
{
  union REGS regs;
  regs.h.ah=4;
  regs.h.al=1;
  int86(0x10,& regs,& regs);
}
void mouse (void)
  { union REGS regs;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
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
int status(void)
{
     union REGS regs;
     regs.x.ax=3;
     int86(0x33,&regs,&regs);
     return(regs.x.bx);
}

void ponto(int linha,int coluna,unsigned char cor)
{
  union REGS regs;
  regs.h.ah=imprponto;
  regs.x.dx=linha;
  regs.x.cx=coluna;
  regs.h.al=cor;
  regs.h.bh=0;
  int86(0x10,&regs,&regs);
}
void linha(int x1,int y1,int x2,int y2,char cor)
{
  int dx,dy,x=x1,y=y1,i,xt,yt;
  float erro=0.0;
  if(x1>x2){
     xt=x2;
     x2=x1;
     x1=xt;}
  if(y1>y2){
     yt=y2;
     y2=y1;
     y1=yt;}
  dx=(x2-x1);dy=(y2-y1);
  if(dx==0){
  for(i=0;i<=dy;i++)
  {
    ponto(y,x,cor);
    y++;
    erro=erro+(float)dx/(float)dy;
    if(erro>0.5)
    {
      erro=erro-1.0;
      x++;
    }
  }
 }
 else{
 for(i=0;i<=dx;i++)
  {
    ponto(y,x,cor);
    x++;
    erro=erro+(float)dy/(float)dx;
    if(erro>0.5)
    {
      erro=erro-1.0;
      y++;
    }
  }
 }
}
#define IDO 0x17

void imprime(int x)
{
   union REGS regs;
   regs.h.ah = 0;  /* set cursor postion */
   regs.h.al = x;
   regs.x.dx = 0;
   int86(IDO, &regs, &regs);
}
void retangulo(int ci,int li,int cf,int lf,char cor)
{
 int linha,coluna,ct,lt;
 if(li>lf){
    lt=lf;
    lf=li;
    li=lt;}
 if(ci>cf){
    ct=cf;
    cf=ci;
    ci=ct;}
 for (linha=li;linha<=lf;linha++)
     for(coluna=ci;coluna<=cf;coluna++)
	ponto(linha,coluna,cor);
}
void caixa(int ci,int li,int cf,int lf,char cor)
{
  int ct,lt;
  if(ci>cf){
     ct=cf;
     cf=ci;
     ci=ct;}
  if(li>lf){
     lt=lf;
     lf=li;
     li=lt;}
  linha(cf,li,cf,lf,cor);
  linha(ci,li,cf,li,cor);
  linha(ci,lf,cf,lf,cor);
  linha(ci,li,ci,lf,cor);

}
void botao(int x1,int y1,int x2,int y2,int log)
{


  if(log==0){
  retangulo(x1,y1,x2,y2,8);
  caixa(x1-3,y1-3,x2+1,y2+2,0);
  linha(x1-1,y1-1,x1-1,y2,7);
  linha(x1-2,y1-2,x1-2,y2,7);
  linha(x1,y1-1,x2,y1-1,7);
  linha(x1-1,y1-2,x2,y1-2,7);
  linha(x2-1,y1-1,x2-1,y2,0);
  linha(x2,y1-2,x2,y2,0);
  linha(x1-1,y2,x2,y2,0);
  linha(x1-2,y2+1,x2,y2+1,0);
  }
  else{
  linha(x2-1,y1-1,x2-1,y2,8);
  linha(x2,y1-2,x2,y2,8);
  linha(x1-1,y2,x2,y2,8);
  linha(x1-2,y2+1,x2,y2+1,8);
  linha(x1-1,y1-1,x1-1,y2,0);
  linha(x1-2,y1-2,x1-2,y2,0);
  linha(x1,y1-1,x2,y1-1,0);
  linha(x1-1,y1-2,x2,y1-2,0);

  }
}
void desliga (void)
{
union REGS regs;
      regs.x.ax=2;
      int86(0x33,&regs,&regs);
}
void mousexy(int lin,int col)
{
    union REGS regs;
    regs.x.ax=4;
    regs.x.dx=lin;
    regs.x.cx=col;
    int86(0x33,&regs,&regs);
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
  struct imagem{
  unsigned imag[32];
  int lin,col;
  };
