#include<conio.h>
#include<stdio.h>
#include<dos.h>
void main()
{
   int i,j;
   int seq[21][8]={ {  1,  2,  4,  8, 16, 32, 64,128},
		    {128, 64, 32, 16,  8,  4,  2,  1},
		    {  1,  3,  7, 15, 31, 63,127,255},
		    {255,127, 63, 31, 15,  7,  3,  1},
		    {254,252,248,240,224,192,128,  1},
		    {129, 66, 36, 24, 24, 36, 66,129},
		    {129,195,231,255,255,231,195,129},
		    {129,195,231,255,127, 63, 31, 15},
		    {  7,  3,  1,  1,  7, 31,127,255},
		    {255,126, 60, 24, 24, 60,126,255},
		    {255,127, 63, 31, 15,  7,  3,  1},
		    {  1,  3,  7, 15, 31, 63,127,255},
		    {  1,  2,  4,  8, 16, 32, 64,128},
		    {  3,  6, 12, 24, 48, 96,192,128},
		    {  3, 14, 28, 56,112,224,192,128},
		    {129, 66, 36, 24, 24, 36, 66,129},
		    { 24, 66, 36,129,129, 66, 36, 24},
		    {195,102, 24,102,195,102, 24,195},
		    {255,  0, 15,240,  3,192,128,  1},
		    {170, 55,170, 55,170, 55,170, 55},
		    {219,109,219,109,219,109,219,109}};
   while(1)
      for(i=0;i<21;i++)
	 for(j=0;j<8;j++){
	     if(kbhit())
		return;
	     outportb(0x378,seq[i][j]);
	     delay(50);
	     }

}