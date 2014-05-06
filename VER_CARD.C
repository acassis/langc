#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
char num[16],val[16],ch;
int nu,i,acum=0;
int testa()
{
   return ch-48;
}

void main()
{
while((ch=getch())!=27){
 clrscr();
 puts("Informe um cartao '???? ???? ???? ???X' p/ que eu valide o ultimo nß");
 gets(num);
 strcpy(val,num);
 for(i=0;i<=14;i+=2){
     ch=num[i];
     nu=testa();
     nu=nu*2;
     if(nu>9)
	nu=nu-9;
     val[i]=(char)(nu+48);}
  for(i=0;val[i]!='\0';i++){
      ch=val[i];
      nu=testa();
      acum=acum+nu;}
  printf("\n%d",acum);
  if(acum>100){
      printf("ê impossivel validar este cartao!");
      getch();
      return;}
  while(1){
      acum=acum-10;
      if(acum<=10)
	 break; }
  acum=10-acum;
  num[15]=(char)(acum+48);
  printf("\nO cartao obtido a partir do informado e: %s",num);
  }
}



