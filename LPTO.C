#include <math.h>
#include<graphics.h>
#include<grafico.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
div_t x;
char chaves[]="0000000000000000";
void vsync( void )
{
  while( inp( 0x3da ) & 8 );   //Espera retra‡o Vertical,
  while( !(inp( 0x3da ) & 8) ); //Para que a tela nÆo pisque.
}
void apaga(int oct)
{
   setfillstyle(1,7);
//---------OCTETO 0---------------------------------------------------------
if(oct==0){
   fillellipse(92,100,10,10);
   fillellipse(116,100,10,10);
   fillellipse(139,100,10,10);
   fillellipse(162,100,10,10);
   fillellipse(185,100,10,10);
   fillellipse(208,100,10,10);
   fillellipse(231,100,10,10);
   fillellipse(254,100,10,10);}
};
void mostra(int oct,int val)
{
   char led[]="00000000";
   int i=7;
   vsync();
   apaga(oct);
   if(val==1)
      led[7]='1';
if(val>1)
 while(1)
 {
   x=div(val,2);
   led[i]=x.rem+48;
   i--;
   if(x.quot==1){
      led[i]=x.quot+48;
      break;}
   val=x.quot;
   gotoxy(40,12);
 }
setfillstyle(1,4);
//---------OCTETO 0---------------------------------------------------------
if(oct==0)
{
  vsync();
  if(led[0]=='1')
     fillellipse(92,100,10,10);
  if(led[1]=='1')
     fillellipse(116,100,10,10);
  if(led[2]=='1')
     fillellipse(139,100,10,10);
  if(led[3]=='1')
     fillellipse(162,100,10,10);
  if(led[4]=='1')
     fillellipse(185,100,10,10);
  if(led[5]=='1')
     fillellipse(208,100,10,10);
  if(led[6]=='1')
     fillellipse(231,100,10,10);
  if(led[7]=='1')
     fillellipse(254,100,10,10);
}
};
void main()
{
   int drive=DETECT,modo,lin,col,sta,stant;
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
    initgraph(&drive,&modo,"c:\\bc\\bgi");
    apaga(0);
while(!kbhit())
 {
      for(i=0;i<21;i++)
	 for(j=0;j<8;j++){
	     if(kbhit())
		break;
	     mostra(0,seq[i][j]);
	     outportb(0x378,seq[i][j]);
	     delay(100);
	     }

 }
    closegraph();
}