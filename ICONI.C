#include <stdio.h>
#include<dos.h>
char bina[]="";
unsigned char che;
void main()
{
   FILE *s,*f;
   char nome[]="";
   unsigned char ch=0,mt[16]={0xff,0x0,0x0,0x0,0xff,0x0,0xff,0x0,0xff,0xff,0x0,0x0,0xff,0xff,0xff,0x0};
   unsigned long int tam,ta=0;
   int resp=1,i=0;
   clrscr();
   printf("Informe o nome de um bitmap de 16 cores:");
   gets(nome);
   if ((s=fopen(nome,"rb"))==NULL)
    {
      printf("\nArquivo nao pode ser criado.");
      return;
    }
    fseek(s, 0, SEEK_END);
    tam=ftell(s);
    fseek(s, 0, SEEK_SET);
    ta=ftell(s);
    while(tam>ta || ch==eof(s))
    {
       ch = getc(s);
       gotoxy(40,12);
       printf("   %x   ",ch);
       ta=ftell(s);
       printf("\n  Posicao=%x   ",(unsigned int)ta);
       if(ta>=0x77)
       {
	  if(resp==1)
	    {
	      resp=0;
	      delay(1000);
	      gotoxy(36,24);
	      printf("Informe o nome de um EXE for WINDOWS");
	      gets(nome);
	      if ((f=fopen(nome,"rwb"))==NULL)
	       {
		   printf("\nArquivo nao pode ser criado.");
		   return;
	       }
	       fseek(f, 0, SEEK_SET);
	       while(i<16)
	       {
		 che=getc(f);
		 gotoxy(10,24);
		 printf(" %d %d   ",che,i);
		 //delay(100);
		 if(che!=mt[i])
		   {
		    i=0;
		    continue;
		   }
		 else
		   i++;
	       }
	   }
	   fprintf(f,"%c",ch);
       }
    }
    fclose(f);
    fclose(s);
}
