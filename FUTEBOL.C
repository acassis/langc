struct time
{
   char nome[20];
   int pg,gm,gs;
}
#include <stdio.h>
#include <conio.h>
void main(void)
{
   struct time tim[20];
   int i,timi;

   for(i=0;i<5;i++)
    {
      flushall();
      printf("\nInforme o nome %d� time:",i+1);
      gets(tim[i].nome);
      printf("\nInforme os pontos ganhos pelo %d� time:",i+1);
      scanf("%d",&tim[i].pg);
      printf("\nInforme os gols marcados pelo %d� time:",i+1);
      scanf("%d",&tim[i].gm);
      printf("\nInforme os gols sofridos pelo %d� time:",i+1);
      scanf("%d",&tim[i].gs);
      getch();
   }
   for(i=0;i<5;i++)
   {
     if (i==0)
	timi=i;
     else if (tim[timi].pg<tim[i].pg)
	     timi=i;
	  else if (tim[timi].pg==tim[i].pg)
		 if (tim[timi].gm<tim[i].gm)
		    timi=i;
		 else if (tim[timi].gm==tim[i].gm)
			 if (tim[timi].gs>tim[i].gs)
			    timi=i;
   }
   printf("%s � o campe�o.",tim[timi].nome);
   getch();
}