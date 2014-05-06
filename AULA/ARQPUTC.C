#include <stdio.h>
#include <conio.h>
#include <string.h>
void main(void)
{
 char s;
 FILE *st;
  if((st=fopen("teste1.fill","w"))==NULL)
 {puts("arquivo nao pode ser aberto\npressione qualquer tecla para continuar... ");
  getch();
 return;}
 while((s=getche())!='\r') /* ou  while((s=getche())!=13)
	putc(s,st);


 fclose(st);
}