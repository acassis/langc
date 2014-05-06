#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include <stdlib.h>
void main()
{
   int i,j;
   while(!kbhit()){
	 i=random(255);
	 j=random(500);
	 outportb(0x378,i);
	 delay(j);}

}