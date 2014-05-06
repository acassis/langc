#include<stdio.h>
#include<conio.h>
int ma[4][4] = { { 1, 2, 3, 4},
		 { 5, 6, 7, 8},
		 { 9,10,11,12},
		 {13,14,15,16}
	       };
int a=-100,b=-100,c=-100,x=0,y=0;
void main()
{
  clrscr();
  puts("Aguarde...\n");
  while(1)
  {
    if((a*x)+(b*y)+c != ma[y][x])
    {
      a++;
      if(a>100){
	 b++;
	 a=-100;}
      if(b>100){
	 c++;
	 b=-100;}
      if(c>100){
	 puts("\nFim.");
	 getch();
	 exit(1);}
      x=0;y=0;
    }
    else
    {
      if(y==3 && x==3)
	 printf("%dX + %dY + %d\n",a,b,c);
      x++;
      if(x>3){
	 x=0;
	 y++;}
    }
  }
}



