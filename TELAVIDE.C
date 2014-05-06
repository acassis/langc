#include<stdio.h>
void main()
{
   long tam,ta=0,pos=0;
   unsigned char far *tela;
   int ch=0,ct=0;
   union
   {
     int cha;
     unsigned char po[2];
   }te;
   FILE *s,*p;
   if ((s=fopen("c:\\lixo\\imagem.bmp","rb"))==NULL)
   {  printf("\nArquivo nao pode ser aberto.");
      return; }

   if ((p=fopen("c:\\lixo\\imagem.txt","wt"))==NULL)
   {  printf("\nArquivo nao pode ser aberto.");
      return; }

   fprintf(p,"foto[64000]={");

   fseek(s, 0, SEEK_SET);
   tela = (unsigned char far *)0xA0000000;
   asm mov ax,19
   asm int 10h
   while (ch != EOF)
   {
      ch = fgetc(s);
      ct++;
      if(ct>=0x438)
      {
	 //*(tela + pos) = ch;
	 //pos++;
	 //delay(1);
	 //_fmemcpy(tela,(const void far *)s,64000);
	 fprintf(p,"%3d,",ch);
      }
   }
   //getch();
}