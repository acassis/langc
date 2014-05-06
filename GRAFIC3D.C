#include<graphics.h>
#include<math.h>
void main()
{
   int drive=DETECT,modo;
   int largura=280,altura=190,va=-1;
   int xfal=5,zfal=3,tamanho = 64,prof = 54;
   int inicio = 5,a,b;
   float g[100][100],x,y,z,xbase,zbase;
   int xvelho,xnovo,zvelho,znovo;
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   printf("Calculando");
   for(a=(prof/2) * -1;a<=prof/2;a++)
   {
    for(b=(tamanho/2) * -1;b<=tamanho/2;b++)
    {
      gotoxy(1,1);
      printf("a = %d e b = %d ",a,b);
      x = a * 18/tamanho;
      z = b * 18/prof;
      y = (sin(x) + cos(z))/100;
      g[b+32][a+27] = y*va*altura;
    }
   }
   for(z=1;z<=prof;z++)
   {
    xbase = xfal * z;
    zbase = altura/2 + z * zfal + inicio * va;
    xvelho = xbase + xfal;
    zvelho = 191 - zbase + zfal + g[1][z];
    for(x=1;x<=tamanho;x++)
     {
       xnovo = xbase + x + xfal;
       znovo = 191 - zbase + x * zfal + g[x][z];
       line(xvelho,zvelho+100,xnovo,znovo+100);
       xvelho = xnovo; zvelho = znovo;
     }
   }
   for(x=1;x<tamanho;x++)
   {
     xbase = xfal * x + prof * xfal;
     zbase = altura/2 - x * zfal + prof * zfal + inicio * va;
     zvelho = 191 - zbase + zfal + g[x][prof-1];
     xvelho = xbase - xfal;
     for(z=0;z<=prof-1;z++)
     {
       xnovo = xbase - z * xfal;
       znovo = 191 - zbase + z * zfal + g[x][prof-z];
       line(xvelho,zvelho+100,xnovo,znovo+100);
       xvelho = xnovo;
       zvelho = znovo;
     }
   }
   getch();
}