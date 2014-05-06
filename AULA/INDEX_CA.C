#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void index_caracter(char *ma[],int a)
{
  char *temp;
  int i,j,l=0;
  for(j=0;j<a;j++)
    for(i=0;i<a;i++)
       if(strcmp(ma[i],ma[j])>0)
       {
	 temp=ma[i];
	 ma[i]=ma[j];
	 ma[j]=temp;
	}
}
void main(void)
{
  char *valor[]={"moizes","elizabeth","carlos","debora"};
  int i;
  clrscr();
  index_caracter(valor,4);
  for(i=0;i<4;i++)
     printf("\n%s",valor[i]);
 getch();
}

