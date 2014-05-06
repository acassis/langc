/*
gravar em disco com fwrite
grav1.c
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main(void)
{
  FILE *fp;
  float f=12.23;
  if((fp=fopen("teste.dff","wb"))==NULL)
  {puts("o arquivo nao pode ser aberto");
   exit(1);
  }
  if(fwrite(&f,sizeof(float),1,fp)!=1)
    printf("erro ao gravar");
    fclose(fp);
}