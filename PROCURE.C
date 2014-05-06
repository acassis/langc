#include <stdlib.h>
#include<math.h>

unsigned char far *tela;

void putpixel(int col,int lin,unsigned char cor)
{
   if(lin>0 && lin<200 && col>0 && col<320)
   *(tela + 320*lin +col) = cor;
}
void main()
{
   unsigned char cor1,cor2,cor3,cor4,cor5;
   int px=160,py=100,d=0,ct=10,c1=0,c2=1,c3=0,c4=1,c5=0;
   float x1=10,x2=120,x3=150,x4=140,x5=160,y1=50,y2=160,y3=130,y4=100,y5=50,ct1=1,ct2=0.5,ct3=1,ct4=0.5,ct5=1,ang1=0,ang2=0,ang3=0,ang4=0,ang5=0;
   tela = (unsigned char far *)0xA0000000;
   asm mov ax,19
   asm int 10h

   while(!kbhit())
   {
      if(d==0)
	{
	 if(px<317)
	    px+=2;
	 if(py<197)
	    py+=2;
	}
      if(d==1)
	{
	 if(px>2)
	    px-=2;
	 if(py<197)
	    py+=2;
	}
      if(d==2)
	{
	 if(px<316)
	    px+=2;
	 if(py>2)
	    py-=2;
	}
      if(d==3)
	{
	 if(px>2)
	    px-=2;
	 if(py>2)
	    py-=2;
	}

     ang1+=0.15;
     ang2+=0.14;
     ang3+=0.13;
     ang4+=0.12;
     ang5+=0.1;
     ct--;

     if(ct<1)
     {
	ct = random(50)+1;
	d = random(4);
	cor1 = random(15)+1;
	cor2 = random(15)+1;
	cor3 = random(15)+1;
	cor4 = random(15)+1;
	cor5 = random(15)+1;

     }
     if(c1==0)
	ct1 -= 0.01;
     if(c2==0)
	ct2 -= 0.02;
     if(c3==0)
	ct3 -= 0.03;
     if(c4==0)
	ct4 -= 0.04;
     if(c5==0)
	ct5 -= 0.05;

     if(c1==1)
	ct1 += 0.05;
     if(c2==1)
	ct2 += 0.04;
     if(c3==1)
	ct3 += 0.03;
     if(c4==1)
	ct4 += 0.02;
     if(c5==1)
	ct5 += 0.01;


     if(ct1>2)
	c1 = 0;
     if(ct1<0.5)
	c1 =1;
     if(ct2>2)
	c2 = 0;
     if(ct2<0.5)
	c2 =1;
     if(ct3>2)
	c3 = 0;
     if(ct3<0.5)
	c3 =1;
     if(ct4>2)
	c4 = 0;
     if(ct4<0.5)
	c4 =1;
     if(ct5>2)
	c5 = 0;
     if(ct5<0.5)
	c5 =1;


     if(x1>px)
	x1-=ct1;
     if(x2>px)
	x2-=ct2;
     if(x3>px)
	x3-=ct3;
     if(x4>px)
	x4-=ct4;
     if(x5>px)
	x5-=ct5;

     if(x1<px)
	x1+=ct1;
     if(x2<px)
	x2+=ct2;
     if(x3<px)
	x3+=ct3;
     if(x4<px)
	x4+=ct4;
     if(x5<px)
	x5+=ct5;


     if(y1>py)
	y1-=ct1;
     if(y2>py)
	y2-=ct2;
     if(y3>py)
	y3-=ct3;
     if(y4>py)
	y4-=ct4;
     if(y5>py)
	y5-=ct5;

     if(y1<py)
	y1+=ct1;
     if(y2<py)
	y2+=ct2;
     if(y3<py)
	y3+=ct3;
     if(y4<py)
	y4+=ct4;
     if(y5<py)
	y5+=ct5;

     x1 += 7 * cos(ang1);
     y1 += 7 * sin(ang1);

     x2 += 9 * cos(ang2);
     y2 += 9 * sin(ang2);

     x3 += 11 * cos(ang3);
     y3 += 11 * sin(ang3);

     x4 += 13 * cos(ang4);
     y4 += 13 * sin(ang4);

     x5 += 15 * cos(ang5);
     y5 += 15 * sin(ang5);

     putpixel(px,py,15);
     putpixel(x1,y1,cor1);
     putpixel(x2,y2,cor2);
     putpixel(x3,y3,cor3);
     putpixel(x4,y4,cor4);
     putpixel(x5,y5,cor5);

     delay(10);

     putpixel(px,py,0);
     putpixel(x1,y1,0);
     putpixel(x2,y2,0);
     putpixel(x3,y3,0);
     putpixel(x4,y4,0);
     putpixel(x5,y5,0);

     x1 -= 7 * cos(ang1);
     y1 -= 7 * sin(ang1);

     x2 -= 9 * cos(ang2);
     y2 -= 9 * sin(ang2);

     x3 -= 11 * cos(ang3);
     y3 -= 11 * sin(ang3);

     x4 -= 13 * cos(ang4);
     y4 -= 13 * sin(ang4);

     x5 -= 15 * cos(ang5);
     y5 -= 15 * sin(ang5);

   }
}