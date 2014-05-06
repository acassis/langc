//----------------------------------------------------------------------------
//Programa: Cmos.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Apaga a cmos onde fica guardadas informacoes da BIOS
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <dos.h>

int main(void)
{
  int porta=0x70;
  clrscr();
  outportb(porta++,74);
  outportb(porta,240);
  return 0;
}
