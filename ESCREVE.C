#include <ansi.h>
void main (void)
{
 char a[20],b[20];
 int x=0,y=0;
 clrscr();
 puts("entre com seu nome");
 gets(a);
 gets(b);
 puts("entre com a linha e a coluna a posicionar");
 scanf("%d",&x);
 scanf("%d",&y);
 clrscr();
 gotoxy(x,y);
 printf("%s\n%s",a,b);
 getch();
}