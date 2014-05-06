#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
char num[16],val[16],ch,nume[8];
int nu,i,acum=0,rad;
void main()
{
 clrscr();
 puts("Informe o codigo do banco que deseja os cartoes '????????' p/ que eu os crie:");
 gets(num);
 while((ch=getch())!=27){
inicio:
 rad=random(10);
 num[8]=(char)(rad+48);
 rad=random(10);
 num[9]=(char)(rad+48);
 rad=random(10);
 num[10]=(char)(rad+48);
 rad=random(10);
 num[11]=(char)(rad+48);
 rad=random(10);
 num[12]=(char)(rad+48);
 rad=random(10);
 num[13]=(char)(rad+48);
 rad=random(10);
 num[14]=(char)(rad+48);
 rad=random(10);
 num[15]='\0';
 strcpy(val,num);
 for(i=0;i<=14;i+=2){
     ch=num[i];
     nu=ch-48;
     nu=nu*2;
     if(nu>9)
	nu=nu-9;
     val[i]=(char)(nu+48);}
  acum=0;
  for(i=0;val[i]!='\0';i++){
      ch=val[i];
      nu=ch-48;
      acum=acum+nu;}
  //printf("\n%d",acum);
  if(acum>60)
     goto inicio;
  while(1){
      acum=acum-10;
      if(acum<=10)
	 break; }
  acum=10-acum;
  num[15]=(char)(acum+48);
  printf("\nO cartao obtido a partir do informado e: %s",num);
   }
}
