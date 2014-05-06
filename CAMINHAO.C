#include <stdio.h>
#include <conio.h>
struct con
{
 int km1,km2, totcomb;
 char placa[7],ch;
};
void main(void)
{
 char ch,pl[7],plac[7],t='s',r='s';
 int i=0,j=0;
 struct con n[200];
 for(i=0;i<=200;i++)
   n[i].placa[0]='\0';
 while(!(ch=='s'||r=='S'))
 {
  clrscr();
  puts("Fechamento \nEntrada \nSaida");
  ch=getche();
  if(ch=='e'||ch=='E')
  while(t=='s'||t=='S')
  {
   flushall();
   puts("entre com a placa:");
   gets(n[j].placa);
   puts("kilometragem inicial:");
   scanf("%d",&n[j].km1);
   puts("continuar?(S/N)");
   t=getche();
   j++;
  }
  r='s';
  if(ch=='f'||ch=='F')
   while(r=='s'||r=='S')
   {
    flushall();
    puts("informe a placa:");
    gets(pl);
    plac[0]='\0';
    for(j=0;n[0].placa[j]!='\0';j++)
     plac[j]=n[0].placa[j];
     plac[j]='\0';
    printf("a%sb a%sb",plac,pl);
    for(i=0;pl[0]!=n[i].placa;i++)
     {
       /*	plac[0]='\0';
	for(j=0;n[i].placa[j]!='\0';j++)
	plac[j]=n[i].placa[j];*/

      if(i==200)
       {
	puts("esta placa e inexistente:");
	return;
       }
     }
       puts("entre com a quilometragem final:");
       scanf("%d",&n[i].km2);
       puts("entre com a quantidade de combustivel consumido");
       scanf("%d",n[i].totcomb);
       puts("continuar?(S/N)");
       r=getche();
    }
}
}