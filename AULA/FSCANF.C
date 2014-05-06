#include <stdio.h>
int main(void)
{
   FILE *stream;
   int i;
   char c;
   float f;
   if((stream = fopen("DUMMY.FIL","rb"))==NULL)
     { printf("arquivo n∆o pode ser aberto");
      return 0;
      }
   if(fscanf(stream,"%d %c %f",&i,&c,&f))
      printf("o valores lidos sao: %d %c %f \n",i,c,f);
   else
   {
   fprintf(stderr, "error ao ler os dados de stream.\n");
   exit(1);
}
   return 0;
}
/*
*****************************************************************************
*/
