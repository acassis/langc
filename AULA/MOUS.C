/* programa p ativar mouse*/
#include <process.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
void main()
{
   union REGS p;
   p.x.ax=1; // p/desativa basta ax=0
   int86(0x33,&p,&p);
}