#include <math.h>

int modo(int Mode)
{

asm mov ax,0x4F02
asm mov bx,Mode
asm int 10h

}
void pagina(short int Page)
{
asm mov ax,0x4F05
asm mov bx,0
asm mov dx, Page
asm int 10h
}
void main()
{
    unsigned char far *tela;
    int ct=0;
    int col,lin;
    tela = (unsigned char far *)0xA0000000;
    modo(0x101);

 asm CLI
 asm MOV DX,3c4h
 asm MOV AX,604h // Unchain VGA
 asm OUT DX,AX
 asm MOV AX,0F02h // All planes
 asm OUT DX,AX

 asm MOV DX,3D4h
 asm MOV AX,14h // Disable dword mode
 asm OUT DX,AX
/* asm MOV AX,0E317h // Enable byte mode.
// asm OUT DX,AX
 asm MOV AL,0
 asm OUT DX,AL
 asm INC DX
 asm IN  AL,DX
 asm AND AL,0E0h // Duplicate each scan 8 times.
 asm ADD AL,0
 asm OUT DX,AL*/

   while(!kbhit())
   {
    for(lin=0;lin<480;lin++)
    {

     for(col=0;col<640;col++)
     {
      *(tela + 640*lin + col) = cos((col-320.12)/(lin+1)) * (lin+ct);
      //*(tela + 640*lin + col) = col;
     }
     ct++;
     delay(10);
    }
   }
   asm mov ax,3
   asm int 10h

}