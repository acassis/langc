#include<dos.h>
#define imprponto 0x0c
#define maxlin 480
#define maxcol 640
#define setmodo 0x00
#include <pixel.h>
void main (void)
{
 int linha,coluna;
 char cor;
 set_modo();
 while (!kbhit())
  {
   linha=rand() % maxlin;
   coluna=rand() % maxcol;
   cor=(char) ((linha*coluna)%256);
   imprpt(linha,coluna,cor);
  }
}