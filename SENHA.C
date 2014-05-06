#include<conio.h>
#include<stdio.h>
#include<dos.h>
int i=0,j=0,resp=0,ago=0;
void main()
{
   char senha[]="                                        ";
   int ch=0;
   for(ch=0;ch<256;ch++)
    {
      senha[i]=ch;
      clrscr();
      gotoxy(0,12);
      printf("%s %d",senha,i);
      if(ch>253)
	 getch();
      if(ch==255)
       {
	 ch=1;
	 //if(j != i)
	  for(j=i;j>=0;j--)
	   {
	    //resp=0;
	    if(senha[j]!=255)
	       break;
	    else{
	       resp=1;
	       senha[j] = 1;
	      if(j>0)
	       senha[j-1]=senha[j-1]+2;}
	   }
	 //if(ago==0)
	     //i++;
	 printf(" %d %d %d %d",senha[0],senha[1],senha[2],senha[3]);
	 getch();
	 if(j==1 && resp==1){
	   i++;
	   resp=0;}
	 ago=1;
	 //j=i-1;
	}
    }
}