/* leitura com fread
grav2.c
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main(void)
{
  FILE *fp;
  float f;
  if((fp=fopen("teste.dff","rb"))==NULL)
  {puts("o arquivo nao pode ser aberto");
   exit(1);
  }
  if(fread(&f,sizeof(float),1,fp)!=1)
    printf("erro ao gravar");
  printf("%f",f);
  getch();
  fclose(fp);
}