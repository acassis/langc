#include<math.h>
void circulo(int col,int lin,int raio,unsigned char cor)
{
   int l,c;
   float ang;
   unsigned char far *tela;
   tela =  (unsigned char far *)0xA0000000;
   for(ang=0.1;ang<6.5;ang += 0.001)
     {
       l = sin(ang) * raio;
       c = cos(ang) * raio;
       *(tela + 320*(l + lin) + (c + col)) = cor;
     }
}

void retangulo(int ci,int li,int cf,int lf,unsigned char cor)
{
   int l=li;
   unsigned char far *tela;
   tela =  (unsigned char far *)0xA0000000;
   for(;li<=lf;li++)
    {
	*(tela + 320*(li) + (ci)) = cor;
	*(tela + 320*(li) + (cf)) = cor;
    }
   for(;ci<=cf;ci++)
    {
	*(tela + 320*(l) + (ci)) = cor;
	*(tela + 320*(lf) + (ci)) = cor;
    }
}

void barra(int ci,int li,int cf,int lf,unsigned char cor)
{
   int co = ci;
   unsigned char far *tela;
   tela =  (unsigned char far *)0xA0000000;
   for(;li<=lf;li++)
     for(ci=co;ci<=cf;ci++)
      {
	*(tela + 320*(li) + (ci)) = cor;
      }
}

void main()
{
  int col,lin,ct = -400,cor;
  float raio,ang=0;
  asm mov ax,19
  asm int 10h
  while(!kbhit())
  {
       circulo(100,100,10,cor);
       retangulo(10,10,310,190,cor);
       barra(150,90,170,110,cor);
       cor++;
  }
}