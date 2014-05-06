#include <dos.h>
#include <graphics.h>
#define ATTR 0x0200
void interrupt ( *oldhandler)(void);
char chant,tek,tekant;
int i=0,l=0;
char mtz[80][25];
extern unsigned _heaplen = 1024;
extern unsigned _stklen  = 512;
unsigned int (far *screen)[80];
void interrupt handler(void)
{
  char ch;
  int j,x,y;
  ch=inportb(0x60);
  if(ch!=chant && ch!=14){
   if(ch==2)
     tek='1';
   if(ch==3)
     tek='2';
   if(ch==4)
     tek='3';
   if(ch==5)
     tek='4';
   if(ch==6)
     tek='5';
   if(ch==7)
     tek='6';
   if(ch==8)
     tek='7';
   if(ch==9)
     tek='8';
   if(ch==10)
     tek='9';
   if(ch==11)
     tek='0';
   if(ch==12)
     tek='-';
   if(ch==13)
     tek='=';
   if(ch==43)
     tek=92;

   if(ch==16)
     tek='q';
   if(ch==17)
     tek='w';
   if(ch==18)
     tek='e';
   if(ch==19)
     tek='r';
   if(ch==20)
     tek='t';
   if(ch==21)
     tek='y';
   if(ch==22)
     tek='u';
   if(ch==23)
     tek='i';
   if(ch==24)
     tek='o';
   if(ch==25)
     tek='p';

   if(ch==30)
     tek='a';
   if(ch==31)
     tek='s';
   if(ch==32)
     tek='d';
   if(ch==33)
     tek='f';
   if(ch==34)
     tek='g';
   if(ch==35)
     tek='h';
   if(ch==36)
     tek='j';
   if(ch==37)
     tek='k';
   if(ch==38)
     tek='l';
   if(ch==39)
     tek=';';

   if(ch==44)
     tek='z';
   if(ch==45)
     tek='x';
   if(ch==46)
     tek='c';
   if(ch==47)
     tek='v';
   if(ch==48)
     tek='b';
   if(ch==49)
     tek='n';
   if(ch==50)
     tek='m';
   if(ch==51)
     tek=',';
   if(ch==52)
     tek='.';
   if(ch==53)
     tek='/';
   if(ch==57)
     tek=' ';
     i=i+1;}
   if(i>160){
      i=-1;
      //strcpy(hora," \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2 \2");
      }
   j=i;
   screen = MK_FP(0xB800,0);
   if(i%2!=0)
      j=i+1;
   if(tek!=tekant){
     mtz[j/2][l]=tek;
     tek=0;}
   if(j/2>79){
      i=-1;
      l++;}
   if(ch==1)
     for(y=0;y<25;y++)
      for(x=0;x<80;x++)
	  screen[y][x] = mtz[x][y] + ATTR;

   if(ch==28)
      system("cls");
   tekant=tek;
   chant=ch;
   oldhandler();
}

int main(void)
{
      //int drive=DETECT,modo;

      //initgraph(&drive,&modo,"c:\\bc\\bgi");

      oldhandler = getvect(28);

      setvect(28, handler);

      keep(0, (_SS + (_SP/16) - _psp));
return 0;
}
