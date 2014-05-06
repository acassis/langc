#include <stdlib.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

#define PI 3.1415926535897932385

void ret_vert( void )
{
  while( inp( 0x3da ) & 8 );   //Espera retra‡o Vertical,
  while( !(inp( 0x3da ) & 8) ); //Para que a tela nÆo pisque.
}

void main()
{
   int x = 235,v=235,y = 0,x2,y2,drive=DETECT,modo,s=0,cor=1;
   float ang=0;
   initgraph(&drive,&modo,"c:\\bc\\bgi");
   while(!kbhit())
   {
      ang+=0.001;
      x2 = x * cos((ang*PI)/180) - y * sin((ang*PI)/180);
      y2 = y * cos((ang*PI)/180) + x * sin((ang*PI)/180);
      x = x2;
      y = y2;
      if(x == 0 && y == 0)
	{
	   ret_vert( );
	   cleardevice();

	   y = 0;
	   if(v>-235 && v<240)
	      x = v--;
	   else
	      v = 235;
	}
	   cor=random(15)+1;
	   setcolor(cor);
      circle(x2+320,y2+240,3);
      //delay(1);
   }
}