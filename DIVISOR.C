#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
div_t x;
void main()
{
  int num,i=2,ct=0;
  clrscr();
  puts("Informe um n§");
  scanf("%d",&num);
    while(i<=num)
    {
	x=div(num,i);
	if(x.rem!=0)
	  i++;
	else
	  {
	   printf("\n                                 %5.0d³%d",num,i);
	   num=x.quot;
	  }
    }
    printf("\n                                     1³");
  getch();
}
