/****************************************************************************
arqptus.c
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
void main(void)
{
 char s[30],d[30];
 int c;
 FILE *stream;
 if((stream=fopen("teste.fill","w+"))==NULL)
 {puts("arquivo nao pode ser aberto\npressione qualquer tecla para continuar... ");
  getch();
 return;}
 puts("entre com uma string");
 gets(s);

 /*int fputs(const char *s, FILE *stream);*/
 if(fputs(s,stream)==NULL)
 {puts("nao foi possivel gravar string\npressione qualquer tecla para continuar... ");
  getch();
  return;
 }
 fseek(stream,0,SEEK_SET);
 /*
 fgets(msg, strlen(string)+1,stream);*/
 fgets(d,strlen(d)+1,stream);
 printf("%s",d);
 fclose(stream);
}
