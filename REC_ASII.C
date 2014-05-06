#include<conio.h>
#include<stdio.h>
# define esc 0x1b
void main(void)
{
    char ch=1;
    clrscr();
    while((getch()!=esc))
     {
      clrscr();
      ch++;
      printf(" %3d %c",ch,ch);
      }
}

