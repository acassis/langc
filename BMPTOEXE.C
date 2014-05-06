#include <stdio.h>
#include<dos.h>
char bina[]="";
unsigned int linha,coluna;
unsigned char cor1,cor2;
void testacor(unsigned char ch)
{
  unsigned char tem;
  tem = ch & 15;
  if(tem==0)
     cor1=0;
  else if(tem==1)
	  cor1=4;
  else if(tem==2)
	  cor1=2;
  else if(tem==3)
	  cor1=6;
  else if(tem==4)
	  cor1=1;
  else if(tem==5)
	  cor1=5;
  else if(tem==6)
	  cor1=3;
  else if(tem==7)
	  cor1=8;
  else if(tem==8)
	  cor1=7;
  else if(tem==9)
	  cor1=12;
  else if(tem==10)
	  cor1=10;
  else if(tem==11)
	  cor1=14;
  else if(tem==12)
	  cor1=9;
  else if(tem==13)
	  cor1=13;
  else if(tem==14)
	  cor1=11;
  else if(tem==15)
	  cor1=15;

  tem = ch & 240;
  if(tem==0)
     cor2=0;
  else if(tem==16)
	  cor2=4;
  else if(tem==32)
	  cor2=2;
  else if(tem==48)
	  cor2=6;
  else if(tem==64)
	  cor2=1;
  else if(tem==80)
	  cor2=5;
  else if(tem==96)
	  cor2=3;
  else if(tem==112)
	  cor2=8;
  else if(tem==128)
	  cor2=7;
  else if(tem==144)
	  cor2=12;
  else if(tem==160)
	  cor2=10;
  else if(tem==176)
	  cor2=14;
  else if(tem==192)
	  cor2=9;
  else if(tem==208)
	  cor2=13;
  else if(tem==224)
	  cor2=11;
  else if(tem==240)
	  cor2=15;
};
void testa()
{
	     if(bina[1]=='\0')
	      {
		bina[2]='\0';
		bina[1]=bina[0];
		bina[0]='0';
	      }
};
void main()
{
   FILE *s,*f;
   char nome[]="";
   unsigned char ch=0;
   unsigned long int tam,ta=0;
   int col=0,lin=0,ctcol,ctlin=0;
   int resp=1;
   clrscr();
   printf("Informe o nome de um bitmap de 16 cores:");
   gets(nome);
   if ((s=fopen(nome,"rt"))==NULL)
    {
      printf("\nArquivo nao pode ser aberto.");
      return;
    }
    fseek(s, 0, SEEK_END);
    tam=ftell(s);
    fseek(s, 0, SEEK_SET);
    ta=ftell(s);
    printf("Tamanho=%x",(unsigned int)tam);
    printf("\nInforme quantas colunas tem a imagem:");
    scanf("%d",&col);
    printf("\nInforme quantas linhas  tem a imagem:");
    scanf("%d",&lin);
    while(tam>ta || ch==eof(s))
    {
       ch = getc(s);
       gotoxy(40,12);
       printf("   %x   ",ch);
       ta=ftell(s);
       printf("\n  Posicao=%x   ",(unsigned int)ta);
       /*if(ta==0xf)
	{
	  ch = getc(s);
	  ch = getc(s);
	  ch = getc(s);
	  ch = getc(s);
	 if(ch!=0)
	   {
	     itoa(ch,bina,16);
	     testa();
	     col=(bina[0]-48)*16 + (bina[1]-48);
	   }
	  ch = getc(s);
	 if(col!=0)
	  {
	     itoa(ch,bina,16);
	     testa();
	     col+=(bina[0]-48)*4096 + (bina[1]-48)*256;
	  }
	 else
	  {
	     itoa(ch,bina,16);
	     testa();
	     col=(bina[0]-48)*16 + (bina[1]-48)*256;
	  }
	  ch = getc(s);
	  ch = getc(s);
	  ch = getc(s);
	 if(ch!=0)
	   {
	     itoa(ch,bina,16);
	     testa();
	     lin=(bina[0]-48)*16 + (bina[1]-48);
	   }
	  ch = getc(s);
	 if(lin!=0)
	  {
	     itoa(ch,bina,16);
	     testa();
	     lin+=(bina[0]-48)*4096 + (bina[1]-48)*256;
	  }
	 else
	  {
	     itoa(ch,bina,16);
	     testa();
	     lin=(bina[0]-48)*16 + (bina[1]-48);
	  }
	  printf("\nColunas=%d \nLinhas=%d",col,lin);
	}*/
       if(ta>=0x77)
	{
	  if(resp==1)
	    {
	      ctcol=col;
	      resp=0;
	      delay(1000);
	      gotoxy(36,24);
	      if ((f=fopen("image.exe","wb"))==NULL)
	       {
		   printf("\nArquivo nao pode ser criado.");
		   return;
	       }
	       fseek(f, 0, SEEK_SET);
	       fprintf(f,"¸%cÍ",0);
	    }
	  gotoxy(1,24);
	  printf(" %x ",ch);
	  //delay(100);
	  if(ctcol<2)
	    {
	      ctcol=col;
	      ctlin++;
	    }
	  ctcol-=2;
	  printf("   %d   ",ctcol);
	   coluna=col-(ctcol+2);
	   linha =lin-(ctlin);
	   testacor(ch);
	   if(cor1!=0 || cor2!=0)
	    {
		 fprintf(f,"´¶%c²%cÍ´%c°Û³%c¹%cÍ",linha-1,coluna,9,cor2,0);
		 fprintf(f,"´¶%c²%cÍ´%c°Û³%c¹%cÍ",linha-1,coluna+1,9,cor1,0);
	    }
	}
    }
    fprintf(f,"´%cÍ%c´LÍ!",0,22);
    fclose(f);
    fclose(s);
}
