#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
int lin=240,col=320,cco,cli,cor;

void diagonal()
{
  int dcol,dlin,col1=466,lin1=166,lin2=330,col2=530,i,colt,lint;
  float erro=0.0;
  dcol=(col2-col1);
  dlin=(lin2-lin1);
 for(i=0;i<=dlin;i++)
  {
    if(col>=col1 && col<=col1+14 && lin<=lin1 && lin>=lin1-15){
	 putpixel(col,lin,cor);
	 //putpixel(col-1,lin,1);
	 //putpixel(col+1,lin,cor+1);
	 //putpixel(col,lin-1,2);
	 //putpixel(col,lin+1,cor+2);
	 break;}
    lin1++;
    erro=erro+(float)dcol/(float)dlin;
    if(erro>0.5)
    {
      erro=erro-1.0;
      col1++;
     }
  }
}


void compara()
{
	 if(col>100 && col<120 && lin>150 && lin<330 ||
	 col>100 && col<190 && lin>150 && lin<170 ||
	 col>170 && col<190 && lin>150 && lin<330 ||
	 col>100 && col<190 && lin>240 && lin<260 ||
	 col>220 && col<240 && lin>150 && lin<330 ||
	 col>220 && col<310 && lin>310 && lin<330 ||
	 col>340 && col<360 && lin>150 && lin<330 ||
	 col>340 && col<430 && lin>150 && lin<170 ||
	 col>410 && col<430 && lin>150 && lin<330 ||
	 col>340 && col<430 && lin>240 && lin<260 ||
	 col>460 && col<480 && lin>150 && lin<330 ||
	 col>530 && col<550 && lin>150 && lin<330 ){
	 putpixel(col,lin,cor+3);
	 //putpixel(col-1,lin,3);
	 //putpixel(col+1,lin,cor+4);
	 //putpixel(col,lin-1,4);
	 //putpixel(col,lin+1,cor+5);
	 }

}

void main()
{
  int drive=DETECT,modo;
  initgraph(&drive,&modo,"c:\\bc\\bgi");

while(!kbhit())
{
inicio:
  cco=random(2);
  cli=random(2);
  cor=random(15);
  if(cco==0 && col<570)
    col++;
  else
  if(cco==1 && col>80)
    col--;
  if(cli==0 && lin<350)
    lin++;
  else
  if(cli==1 && lin>120)
    lin--;
  setcolor(1);
  //line(col,lin,320,240);
  putpixel(col,lin,15);
  putpixel(col-1,lin,15);
  putpixel(col+1,lin,15);
  putpixel(col,lin-1,15);
  putpixel(col,lin+1,15);
  compara();
  diagonal();
 }
 closegraph();
}
