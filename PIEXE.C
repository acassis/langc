#include <stdio.h>
void main()
{
   FILE *f;
   int i;
   char cor=15;
   union
   { unsigned int linha;
     unsigned char lin[2];
   } posy;
   union
   { unsigned int coluna;
     unsigned char col[2];
   } posx;
   if ((f=fopen("ima.exe","wb"))==NULL)
    {
	printf("\nArquivo nao pode ser criado.");
	return;
    }
   fseek(f, 0, SEEK_SET);
   fprintf(f,"�%c�",0);
for(i=0;i<3;i++)
   {
    printf("\nInforme a %d� coluna e a %d� linha:",i+1,i+1);
    scanf("%d",&posy.linha);
    scanf("%d",&posx.coluna);
    fprintf(f,"��%c%c�%c%c�%c�",posy.lin[0],posy.lin[1],posx.col[0],posx.col[1],cor);
   }
   fprintf(f,"(���%c��L�!",0);
   fclose(f);
}
