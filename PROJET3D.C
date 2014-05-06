#include<math.h>
#include<graphics.h>
#define PI 3.1415926535897932385

typedef struct coordenadas
{
   int x;
   int y;
   int z;
   int te_x;
   int te_y;
} vetor3d;

vetor3d caixa_orig[8] = {
			 { 40, 80, 60, 0,0},
			 { 40, 80,-60, 0,0},
			 { 40,-80, 60, 0,0},
			 { 40,-80,-60, 0,0},
			 {-40, 80, 60, 0,0},
			 {-40, 80,-60, 0,0},
			 {-40,-80, 60, 0,0},
			 {-40,-80,-60, 0,0}
			};
vetor3d caixa_girada[8];

void gira_ponto(int ponto,char rx, char ry, char rz);

void gira_caixa(char ang_x,char ang_y,char ang_z);

void projeta_ponto(int distancia,int ponto);

void mostra_caixa();

float seno(char angulo);

float coseno(char angulo);

void main()
{
     char x=0,y=0,z=0,ch=0;
     int drive=DETECT,modo;
     initgraph(&drive,&modo,"c:\\bc\\bgi");
     goto mostra;
     while(ch!=27)
     {
	 ch = 0;
	 if(kbhit())
	 {
	    ch = getch();
mostra:
	    if(ch=='6')
	       x++;
	    if(ch=='4')
	       x--;
	    gira_caixa(x,y,z);
	    mostra_caixa();
	 }
     }
}

float seno(char angulo)
{
   return sin((angulo * PI)/180);
}

float coseno(char angulo)
{
   return cos((angulo * PI)/180);
}

void projeta_ponto(int distancia,int ponto)
{
    caixa_girada[ponto].te_x = (256 * caixa_girada[ponto].x)/(caixa_girada[ponto].z + distancia) + 320;
    caixa_girada[ponto].te_y = (256 * caixa_girada[ponto].y)/(caixa_girada[ponto].z + distancia) + 240;
}

void gira_ponto(int ponto,char rx, char ry, char rz)
{
      //Gira sobre o eixo X
      caixa_girada[ponto].y = caixa_orig[ponto].y * coseno(rx) + caixa_orig[ponto].x * seno(rx);
      caixa_girada[ponto].z = caixa_orig[ponto].z * coseno(rx) - caixa_orig[ponto].z * seno(rx);

      //Gira sobre o eixo Y
      caixa_girada[ponto].x = caixa_orig[ponto].x * coseno(ry) + caixa_orig[ponto].x * seno(ry);
      caixa_girada[ponto].z = caixa_orig[ponto].z * coseno(ry) - caixa_orig[ponto].z * seno(ry);

      //Gira sobre o eixo Z
      caixa_girada[ponto].x = caixa_orig[ponto].x * coseno(rz) + caixa_orig[ponto].x * seno(rz);
      caixa_girada[ponto].y = caixa_orig[ponto].y * coseno(rz) - caixa_orig[ponto].y * seno(rz);

      caixa_orig[ponto] = caixa_girada[ponto];
}
void gira_caixa(char ang_x,char ang_y,char ang_z)
{
      int i;
      for(i=0;i<8;i++)
	 gira_ponto(i,ang_x,ang_y,ang_z);
}

void mostra_caixa()
{
      int i;
      for(i=0;i<8;i++)
      {
	  projeta_ponto(256,i);
	  putpixel(caixa_girada[i].te_x,caixa_girada[i].te_y,15);
      }
}
