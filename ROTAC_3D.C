#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define PI 3.1415926535897932385

typedef struct vetor
{
int x;
int y;
int z;
int posx;
int posy;
} vetor;

vetor caixa[27] =  {                   //Define os pontos(vertices) da caixa.
		 { 40, 80, 60, 0,0},
		 { 40, 80,-60, 0,0},
		 { 40,-80, 60, 0,0},
		 { 40,-80,-60, 0,0},
		 {-40, 80, 60, 0,0},
		 {-40, 80,-60, 0,0},
		 {-40,-80, 60, 0,0},
		 {-40,-80,-60, 0,0},
		 {-35, 10,-60, 0,0},
		 {-35,-10,-60, 0,0},
		 {-25, 10,-60, 0,0},
		 {-25,-10,-60, 0,0},
		 {-35,  0,-60, 0,0},
		 {-25,  0,-60, 0,0},
		 {-15,-10,-60, 0,0},
		 {-15, 10,-60, 0,0},
		 {- 5, 10,-60, 0,0},
		 {  5,-10,-60, 0,0},
		 {  5, 10,-60, 0,0},
		 { 15,-10,-60, 0,0},
		 { 15, 10,-60, 0,0},
		 {  5,  0,-60, 0,0},
		 { 15,  0,-60, 0,0},
		 { 25,-10,-60, 0,0},
		 { 25, 10,-60, 0,0},
		 { 35,-10,-60, 0,0},
		 { 35, 10,-60, 0,0},
		 };

vetor cxa_rotacionada[27]; //Esta matriz guardar  os pontos da caixa rotacionada.
			 //A caixa original deve ser preservada.
char mostra=0;

void ret_vert( void )
{
  while( inp( 0x3da ) & 8 );   //Espera retra‡o Vertical,
  while( !(inp( 0x3da ) & 8) ); //Para que a tela nÆo pisque.
}

//Esta fun‡Æo rotaciona um ponto(vertice) da caixa.
void RotacionaPonto(vetor ponto, vetor *dest, char rx, char ry, char rz);

//Esta fun‡Æo chama a fun‡Æo anterior 8 vezes (Uma caixa tem oito vertices).
void RotacionaCaixa(char ang_x, char ang_y, char ang_z);

//Retorna o seno do angulo que a caixa dever  girar.
float seno(char ang);

//Retorna o coseno do angulo que a caixa dever  girar.
float coseno(char ang);

//Esta fun‡Æo projeta um ponto 3D (Eixos X,Y,Z) em um ponto 2D (Eixos X,Y),
//Pois a tela do seu monitor ‚ em 2D (X = Colunas e Y = Linhas).
void ProjetaPonto(int distancia, vetor ponto, vetor *dest);

//Esta funcÆo chama a fun‡Æo anterior que projeta os ponto em 2D,
//em seguida liga com linha todos os vertices da caixa e mostra na tela.
//Os parametros de entrada definem em qual ponto (X,Y,Z) estar  a caixa
void MostraCx_Rotacionada(int cenx, int ceny, int cenz);

int dist = 256;

void main(void)
{
  char x=0,y=0,z=0,ch=0;
  int gdriver = VGA, gmode = VGAHI;
  initgraph(&gdriver,&gmode,"c:\\bc\\bgi");

  goto mostra;
  while (ch!=27)
  {
    //ch = ' ';
    if(kbhit())
    {
      ret_vert();
      cleardevice();
      ch=getch();
      if(ch=='6')
	 y--;
      if(ch=='4')
	 y++;
      if(ch=='8')
	 x++;
      if(ch=='2')
	 x--;
      if(ch=='9')
	 z++;
      if(ch=='1')
	 z--;
      if(ch=='+')
	 dist-=2;
      if(ch=='-')
	 dist+=2;
      if(ch=='*')
	 mostra = ! mostra;
mostra:
    RotacionaCaixa(x,y,z);
    MostraCx_Rotacionada(0,0,0);
    delay(1);
   }
  }
}

float seno(char ang)
{
  return sin(ang*PI/128);
}

float coseno(char ang)
{
  return cos(ang*PI/128);
}

void RotacionaPonto(vetor ponto, vetor *dest, char rx, char ry, char rz)
{
  vetor temp;
  dest->x = ponto.x;
  dest->y = ponto.y;
  dest->z = ponto.z;

  /* RotacÆo sobre o eixo X */
  temp.y = dest->y*coseno(rx) - dest->z*seno(rx);
  temp.z = dest->z*coseno(rx) + dest->y*seno(rx);
  dest->y = temp.y;
  dest->z = temp.z;

  /* RotacÆo sobre o eixo Y */
  temp.z = dest->z*coseno(ry) - dest->x*seno(ry);
  temp.x = dest->x*coseno(ry) + dest->z*seno(ry);
  dest->z = temp.z;
  dest->x = temp.x;

  /* RotacÆo sobre o eixo Z */
  temp.x = dest->x*coseno(rz) - dest->y*seno(rz);
  temp.y = dest->y*coseno(rz) + dest->x*seno(rz);
  dest->x = temp.x;
  dest->y = temp.y;

}

void RotacionaCaixa(char ang_x, char ang_y, char ang_z)
{
  int cont;
  for (cont=0; cont<27; cont++)
  {
    RotacionaPonto(caixa[cont], &cxa_rotacionada[cont], ang_x, ang_y, ang_z);
  }
}

void ProjetaPonto(int distancia, vetor ponto, vetor *dest)
{
  if((distancia+ponto.z)>0)
  {
     dest->posx = (256 * ponto.x / (ponto.z + distancia)) + 320;
     dest->posy = (256 * ponto.y / (ponto.z + distancia)) + 240;
  }
}

void MostraCx_Rotacionada()
{
  int cont,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,x10,y10,x11,y11,x12,y12,x13,y13,x14,y14,x15,y15,x16,y16,x17,y17,x18,y18,x19,y19,x20,y20,x21,y21,x22,y22,x23,y23,x24,y24,x25,y25,x26,y26,x27,y27;

//Vamos achar a proje‡Æo (X,Y) dos 8 pontos(vertices) da caixa.
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[0], &cxa_rotacionada[0]);
     x1 = cxa_rotacionada[0].posx;
     y1 = cxa_rotacionada[0].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[1], &cxa_rotacionada[1]);
     x2 = cxa_rotacionada[1].posx;
     y2 = cxa_rotacionada[1].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[2], &cxa_rotacionada[2]);
     x3 = cxa_rotacionada[2].posx;
     y3 = cxa_rotacionada[2].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[3], &cxa_rotacionada[3]);
     x4 = cxa_rotacionada[3].posx;
     y4 = cxa_rotacionada[3].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[4], &cxa_rotacionada[4]);
     x5 = cxa_rotacionada[4].posx;
     y5 = cxa_rotacionada[4].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[5], &cxa_rotacionada[5]);
     x6 = cxa_rotacionada[5].posx;
     y6 = cxa_rotacionada[5].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[6], &cxa_rotacionada[6]);
     x7 = cxa_rotacionada[6].posx;
     y7 = cxa_rotacionada[6].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[7], &cxa_rotacionada[7]);
     x8 = cxa_rotacionada[7].posx;
     y8 = cxa_rotacionada[7].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[8], &cxa_rotacionada[8]);
     x9 = cxa_rotacionada[8].posx;
     y9 = cxa_rotacionada[8].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[9], &cxa_rotacionada[9]);
     x10 = cxa_rotacionada[9].posx;
     y10 = cxa_rotacionada[9].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[10], &cxa_rotacionada[10]);
     x11 = cxa_rotacionada[10].posx;
     y11 = cxa_rotacionada[10].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[11], &cxa_rotacionada[11]);
     x12 = cxa_rotacionada[11].posx;
     y12 = cxa_rotacionada[11].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[12], &cxa_rotacionada[12]);
     x13 = cxa_rotacionada[12].posx;
     y13 = cxa_rotacionada[12].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[13], &cxa_rotacionada[13]);
     x14 = cxa_rotacionada[13].posx;
     y14 = cxa_rotacionada[13].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[14], &cxa_rotacionada[14]);
     x15 = cxa_rotacionada[14].posx;
     y15 = cxa_rotacionada[14].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[15], &cxa_rotacionada[15]);
     x16 = cxa_rotacionada[15].posx;
     y16 = cxa_rotacionada[15].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[16], &cxa_rotacionada[16]);
     x17 = cxa_rotacionada[16].posx;
     y17 = cxa_rotacionada[16].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[17], &cxa_rotacionada[17]);
     x18 = cxa_rotacionada[17].posx;
     y18 = cxa_rotacionada[17].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[18], &cxa_rotacionada[18]);
     x19 = cxa_rotacionada[18].posx;
     y19 = cxa_rotacionada[18].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[19], &cxa_rotacionada[19]);
     x20 = cxa_rotacionada[19].posx;
     y20 = cxa_rotacionada[19].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[20], &cxa_rotacionada[20]);
     x21 = cxa_rotacionada[20].posx;
     y21 = cxa_rotacionada[20].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[21], &cxa_rotacionada[21]);
     x22 = cxa_rotacionada[21].posx;
     y22 = cxa_rotacionada[21].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[22], &cxa_rotacionada[22]);
     x23 = cxa_rotacionada[22].posx;
     y23 = cxa_rotacionada[22].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[23], &cxa_rotacionada[23]);
     x24 = cxa_rotacionada[23].posx;
     y24 = cxa_rotacionada[23].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[24], &cxa_rotacionada[24]);
     x25 = cxa_rotacionada[24].posx;
     y25 = cxa_rotacionada[24].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[25], &cxa_rotacionada[25]);
     x26 = cxa_rotacionada[25].posx;
     y26 = cxa_rotacionada[25].posy;
//--------------*---------------*--------------*-----------*------------*-
     ProjetaPonto(dist, cxa_rotacionada[26], &cxa_rotacionada[26]);
     x27 = cxa_rotacionada[26].posx;
     y27 = cxa_rotacionada[26].posy;
//--------------*---------------*--------------*-----------*------------*-


//Mostra meu nome!


if(mostra)
{
//--------------*---------------*--------------*-----------*------------*-
     setcolor(4);
     line(x9,y9,x10,y10);
//--------------*---------------*--------------*-----------*------------*-
     line(x10,y10,x12,y12);
//--------------*---------------*--------------*-----------*------------*-
     line(x11,y11,x12,y12);
//--------------*---------------*--------------*-----------*------------*-
     line(x13,y13,x14,y14);
//--------------*---------------*--------------*-----------*------------*-
     line(x15,y15,x16,y16);
//--------------*---------------*--------------*-----------*------------*-
     line(x16,y16,x17,y17);
//--------------*---------------*--------------*-----------*------------*-
     line(x18,y18,x19,y19);
//--------------*---------------*--------------*-----------*------------*-
     line(x18,y18,x20,y20);
//--------------*---------------*--------------*-----------*------------*-
     line(x20,y20,x21,y21);
//--------------*---------------*--------------*-----------*------------*-
     line(x22,y22,x23,y23);
//--------------*---------------*--------------*-----------*------------*-
     line(x24,y24,x25,y25);
//--------------*---------------*--------------*-----------*------------*-
     line(x24,y24,x27,y27);
//--------------*---------------*--------------*-----------*------------*-
     line(x26,y26,x27,y27);
//--------------*---------------*--------------*-----------*------------*-
}




/*
Agora que j  achamos a proje‡Æo dos 8 pontos vamos liga-los
Veja a figura e confira a liga‡Æo das doze linhas:

		1----------2
		| \        | \
		|   \      |   \
		|     3---------4
		|     |    |    |
		|     |    |    |
		|     |    |    |
		5-----|----6    |
		 \    |     \   |
		   \  |       \ |
		     \7---------8
*/
//--------------*---------------*--------------*-----------*------------*-
     setcolor(10);
     line(x1,y1,x2,y2);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(13);
     line(x1,y1,x3,y3);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(13);
     line(x5,y5,x7,y7);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(9);
     line(x2,y2,x6,y6);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(11);
     line(x2,y2,x4,y4);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(11);
     line(x6,y6,x8,y8);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(15);
     line(x5,y5,x6,y6);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(15);
     line(x7,y7,x8,y8);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(9);
     line(x4,y4,x8,y8);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(10);
     line(x3,y3,x4,y4);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(14);
     line(x1,y1,x5,y5);
//--------------*---------------*--------------*-----------*------------*-
     setcolor(14);
     line(x7,y7,x3,y3);

}





