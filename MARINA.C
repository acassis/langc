#include<dos.h>
#define _asm asm
int   Strlen(const  char *s)
{
     _asm push  es
     _asm push di
     _asm mov di,ds
     _asm mov es,di
     _DI = (unsigned int)s;
     _asm mov cx,-1
     _asm sub al,al
     _asm repne scasb
     _asm not cx
     _asm dec cx
     _asm mov ax,cx
     return _AX;
}
#include<stdio.h>
#include<conio.h>
void main (void)
{
  char nome[]="All“ Mundo!";
  clrscr();
  printf("%s = %d caractere(s)",nome,Strlen(nome));
  getch();
}
