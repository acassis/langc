#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#define lim 1000
int vet1[1000];
void zero(void){
  int i;
  for(i=0;i<lim;i++)vet1[i]=0;
}
void init(void){
int i;
  randomize();
  for(i=0;i<lim;i++)vet1[i]=(rand()%9000);
}
float media(void){
 int i;
  unsigned int s=0;
  for(i=0;i<lim;i++)
  {gotoxy(1,1);
   printf("%u + %d =%u",s,vet1[i],s+vet1[i]);
   s+=vet1[i];
   //delay(10);
   }
return (s/lim);
}
void ordem(void){
  int i,j,temp;
  for(i=0;i<lim;i++)
     for(j=i+1;j<lim;j++)
       if(vet1[i]>vet1[j])
	 {
	   temp=vet1[i];
	   vet1[i]=vet1[j];
	   vet1[j]=temp;
	 }
}
void print(void){
int i;
 for(i=0;i<lim;i++)
 {
    printf("\n[%4d] n§=>%6d",i,vet1[i]);
    delay(10);
 }
}
int loc1(int x){
 int i,c=0;
 for(i=0;i<lim;i++)
 {  c++;
    if(x==vet1[i])
    { printf("\n loc1 esta rotina fez -> %d <- compara‡äes",c);
      getch();
      return 1;
     }
  }
  printf("\n loc1 esta rotina fez -> %d <- compara‡äes",c);
  getch();
  return 0;
}
int loc2(int x){
 int i,c=0;
 for(i=0;i<lim;i++)
 {  c++;
    if(x==vet1[i])
    { printf("\n loc2 esta rotina fez -> %d <- compara‡äes",c);
      getch();
      return 1;
     }
     else
     if(x<vet1[i])
     {
       printf("\n loc2 esta rotina fez -> %d <- compara‡äes",c);
       getch();
       return 0;
     }
 }
}
// implementa‡Æo da fun‡Æo div
// defini‡Æo de uma estrutura
// incluir stdlib.h tipo div_t x, x=div(10,3)
// resultado x.quot, resto x.rem
int loc3(int x){
 int i,ini,fim,ponto,c=0;
 div_t EST;
 ini=0;
 fim=lim-1;
 while(ponto>1)
 {
  c++;
  EST=div( (lim+1)+ini,2);
  //EST=div(lim,2);
  ponto=EST.quot;
  if(x==vet1[ponto])
  {printf("\nloc3 esta rotina fez -< %d <-compara‡äes",c);
   getch();
   return 1;
   }
   else
     if(fim-ini>1)
     {
       if(x>vet1[ponto])
	 ini=ponto;
       else
	  fim=ponto;
     }
     else{
	  printf("\nloc3 esta rotina fez -< %d <-compara‡äes",c);
	  getch();
	  return 1;
	 }
 } // fim do while
}// fim de loc3

void main(void)
{
  int i,num,x;
  float m;
  clrscr();
  zero();
  init();
  m=media();
  printf("\nresultado da media=%10.2f",m);
  getch();
  print();
  getch();
  puts("\ndigite um numero");
  scanf("%d",&num);
  if(loc1(num))
     printf("\nloc1 o numero ->%d<- esta no vetor",num);
  else
     printf("\nloc1 o numero ->%d<- nÆo esta no vetor",num);
  printf("\norenando a matriz");
  delay(1000);
  ordem();
  print();
  getch();
  if(loc2(num))
     printf("\loc2 o numero ->%d<- esta no vetor",num);
  else
     printf("\loc2 o numero ->%d<- nÆo esta no vetor",num);
  puts("\ndigite um numero");
  scanf("%d",&num);
  if(loc3(num))
     printf("\nloc3 o numero ->%d<- esta no vetor",num);
  else
     printf("\nloc3 o numero ->%d<- nÆo esta no vetor",num);
}
