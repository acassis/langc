#include<graphics.h>
int menu(int li,int ci,char *s[])
{ int i=0,pos=0,cont,cor;
  char *p,*o,ch;
  cor=getcolor();

  while(*s[i]!='\0')
  {
   outtextxy(ci,li+i,s[i]);
   cont++; i++;
   }
   i=0;
   while( (ch!=27) && (ch!=13)   )
   {ch=getch();
    if(ch==27) break;
    if(ch==13) break;
    if(pos>i)  textattr(cor+((cor+1)<<4));
    if(ch==80)i+=15;
    if(ch==72)i-=15;
    if((li+i)==cont) i=0;
    if(i<0)          i=cont;
    outtextxy(ci,li+i,s[i]);
    setcolor(cor);
    }
    closegraph();
    if(ch==27) return 0;
    if(ch==13) return pos;

}
void main(void)
{
  int drive=DETECT,modo;
  char *m[]={"INCLUSAO","consulta","sair"};
  initgraph(&drive,&modo,"\\bc\\bgi");
  menu(10,10,m);
}