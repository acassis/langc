#define com0       0x3f8
#define veloc      115200L
#define paridade   0
#define stop       1
#define bits_dados 8
#define true       1
int i;
#include <stdio.h>
char nome1[12],nome2[12];
void recebe_arq(unsigned chr);
void main(int argc,char *argv[])
{
  unsigned int ch;
  FILE *f;
  clrscr();
  if(argc!=3)
    exit();
  for(i=0;*argv[1]!='\0'|| *argv[2]!='\0';i++,argv[1]++,argv[2]++){
	  nome1[i] = toupper(*argv[1]);
	  nome2[i] = toupper(*argv[2]);
	  if(!(isupper(nome1[i])))
	       nome1[i]='\0';
	  if(!(isupper(nome2[i])))
	       nome2[i]='\0'; }
  if((f=fopen("velha.c" ,"r"))==NULL)
  {
    printf("\n Acesso negado ");
    exit();
  }
  fseek (f,0L,2);
  fseek (f,0L,0);
  while ((ch=getc(f))!=(unsigned int) EOF)
  {
    recebe_arq(ch);
  }
  fclose(f);
  exit();
}

void recebe_arq(unsigned chr)
{
  FILE *f;
  fseek (f,0L,2);
  fseek (f,0L,0);
  if ((f=fopen("bicho.c" ,"w"))==NULL)
  {
   printf("\n Acesso negado ");
   exit();
  }
  putc(chr,f);
  if(chr==((unsigned int) EOF)){
       fclose(f);
       exit();}
}
