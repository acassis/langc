#define branco 3
#include <dos.h>
#include <stdio.h>
#include <graphics.h>
void logotipo(char *arq,int lin,int col);
void main(void)
{
 int drive=DETECT,modo;
 initgraph(&drive,&modo,"d:\\bc\\bgi");
 logotipo("c:\\teste.txt",10,10);
 if(kbhit())
   flushall();
 flushall();
 getch();
 closegraph();
}

void logotipo(char *arq,int lin,int col)
{
 unsigned char cor;
 int nlin,ncol,c,l;
 FILE *p;
 if ((p=fopen(arq,"r"))==NULL)
 {
   printf("erro na abertura do arquivo %s",arq);
   exit();
 }
 fscanf(p,"%d\n%d\n",&nlin,&ncol);
 //printf("col = %d, lin = %d",ncol,nlin);
 for (l=0;l<nlin;l++)
   for(c=0;c<ncol;c++)
   {
     fscanf(p,"%1x,",&cor);
     putpixel(col+c,lin+l,cor);
   }
   fscanf(p,"\n");
   fclose(p);
}
