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
}vetor;

vetor a[18]={{-100, -100},
	   {  100, -100},
	   { -100,  100},
	   {  100,  100},
	   {  -50,  -50}, //p1
	   {  -50,   50}, //p2
	   {   50,   50}, //p3
	   {   50,  -50}, //...
	   {  -25,  -50},
	   {  -25,   25},
	   {   25,   25},
	   {   25,  -25},
	   {    0,  -25}, //p9
	   {    0,    0},//p10
	   {    0, -100},
	   {  100,    0},
	   {    0,  100},
	   { -100,    0}};

vetor temp[18];

float seno(char ang)
{
  return sin(ang*PI/128);
}

float coseno(char ang)
{
  return cos(ang*PI/128);
}

void rotaciona(char ang)
{
  int i;

  for(i=0;i<18;i++)
  {
     temp[i].x = a[i].x*coseno(ang) + a[i].y*seno(ang);
     temp[i].y = a[i].y*coseno(ang) - a[i].x*seno(ang);
  }
}
void mostra()
{
   //------------desenha a borda---------------------------------
   line(temp[0].x+320,temp[0].y+240,temp[1].x+320,temp[1].y+240);
   line(temp[0].x+320,temp[0].y+240,temp[2].x+320,temp[2].y+240);
   line(temp[1].x+320,temp[1].y+240,temp[3].x+320,temp[3].y+240);
   line(temp[2].x+320,temp[2].y+240,temp[3].x+320,temp[3].y+240);
   //------------------------------------------------------------

   //-------desenha o labirinto----------------------------------
   line(temp[4].x+320,temp[4].y+240,temp[5].x+320,temp[5].y+240);
   line(temp[5].x+320,temp[5].y+240,temp[6].x+320,temp[6].y+240);
   line(temp[6].x+320,temp[6].y+240,temp[7].x+320,temp[7].y+240);
   line(temp[7].x+320,temp[7].y+240,temp[8].x+320,temp[8].y+240);
   line(temp[8].x+320,temp[8].y+240,temp[9].x+320,temp[9].y+240);
   line(temp[9].x+320,temp[9].y+240,temp[10].x+320,temp[10].y+240);
   line(temp[10].x+320,temp[10].y+240,temp[11].x+320,temp[11].y+240);
   line(temp[11].x+320,temp[11].y+240,temp[12].x+320,temp[12].y+240);
   line(temp[12].x+320,temp[12].y+240,temp[13].x+320,temp[13].y+240);
   //----------------------------------------------------------------
   line(temp[14].x+320,temp[14].y+240,temp[15].x+320,temp[15].y+240);
   line(temp[15].x+320,temp[15].y+240,temp[16].x+320,temp[16].y+240);
   line(temp[16].x+320,temp[16].y+240,temp[17].x+320,temp[17].y+240);
   line(temp[17].x+320,temp[17].y+240,temp[14].x+320,temp[14].y+240);
   //----------------------------------------------------------------
}

void main()
{
   int gdriver = VGA, gmode = VGAHI;
   char ch,angulo=0;

   initgraph(&gdriver,&gmode,"d:\\bc\\bgi");
   rotaciona(0);
   mostra();
   while(ch!=27)
   {

     ch=getch();
     if(ch==77)
	angulo--;
     if(ch==75)
	angulo++;
     rotaciona(angulo);
     cleardevice();
     mostra();
   }
}