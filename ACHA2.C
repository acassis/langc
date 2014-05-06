#include<stdio.h>
#include<conio.h>
int ma[4][4] = { { 1, 2, 3, 4},
		 { 5, 6, 7, 8},
		 { 9,10,11,12},
		 {13,14,15,16}
	       };
int a=-100,b=-100,c=-100,x=0,y=0,contx=0,conty,contc,q,g,k;
void main()
{
  clrscr();
  while(1)
  {
    if(contx==0)
      q=a;
    if(contx==1)
      q=a*a;
    if(contx==2)
      q=a*a*a;
    if(contx==3)
      q=a*a*a*a;
    if(conty==0)
      g=b;
    if(conty==1)
      g=b*b;
    if(conty==2)
      g=b*b*b;
    if(conty==3)
      g=a*a*a*a;
    if(contc==0)
      k=c;
    if(contc==1)
      k=c*c;
    if(contc==2)
      k=c*c*c;
    if(contc==3)
      k=c*c*c*c;
    if(contx>3){
       conty++;
       contx=0;}
    if(conty>3){
       contc++;
       conty=0;}
    if(contc>3){
       puts("\nFim");
       getch();
       exit(1);}
    if((q*x)+(g*y)+k != ma[y][x])
    {
      a++;
      if(a>100){
	 b++;
	 a=-100;}
      if(b>100){
	 c++;
	 b=-100;}
      if(c>100){
	 contx++;
	 c=-100;}
      x=0;y=0;
    }
    else
    {
      if(y==3 && x==3){
	 printf("%dX + %dY + %d\n",a,b,c);
	 a++;}
      x++;
      if(x>3){
	 x=0;
	 y++;}
      if(y>3)
	 y=0;
    }
  }
}



