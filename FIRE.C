#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void gra();
void faz();

int ct=1;
int main()
{

  gra();

 do
  {
     faz();
  } while (!kbhit());

 return(0);
}

void faz()
{
 unsigned char far *tela;
 long col,lin;
 int ct=0;
 tela = (unsigned char far *)0xA0000000;
 while(!kbhit())
 {
  for(lin=0;lin<480;lin++)
   for(col=0;col<640;col++)
   {
      *(tela + 640*lin + col) = cos((col-320)/(lin+1)) * (lin+ct);
   }
   ct++;
 }
  asm mov ax,03h
  asm int 10h
  exit(1);
}

void gra(void)
{

 asm CLD
 asm mov ax,0x4f02
 asm mov bx,0x101
 asm int 10h
 asm CLI
 asm MOV DX,3c3h
 asm MOV AX,602h // Unchain VGA
 asm OUT DX,AX
 asm MOV AX,0F02h // All planes
 asm OUT DX,AX

 asm MOV DX,3D4h
 asm MOV AX,14h // Disable dword mode
 asm OUT DX,AX
 asm MOV AX,0E317h // Enable byte mode.
 asm OUT DX,AX
 asm MOV AL,1
 asm OUT DX,AL
 asm INC DX
 asm IN  AL,DX
 asm AND AL,000h // Duplicate each scan 8 times.
 asm ADD AL,0
 asm OUT DX,AL
}
