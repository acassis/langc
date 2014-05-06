#include<dos.h>
#define SETA_ESQ 75
#define SETA_DIR 77
#define SETA_SOBE 72
#define SETA_DESCE 80
int tecla,x=1,y=1;
void interrupt (far *AntInt9)(void);//Funcao endeco da Int 9 verdadeira.
void interrupt far Funcao() //Esta funcao sera executada toda vez que
{                           //a int 9 for chamada!
asm sti       //Abilita as interrupcoes!
asm in al,60h //Le a porta da teclado
tecla = _AL;
asm mov	al,20h
asm out	20h,al
if(tecla==SETA_ESQ)
   if(x>1) x--;
if(tecla==SETA_DIR)
   if(x<80) x++;
if(tecla==SETA_SOBE)
   if(y>1) y--;
if(tecla==SETA_DESCE)
   if(y<25) y++;
puttext(x,y,x,y,"*\7");
AntInt9();    //chama o processamento correto da int 9
}
void main()
{
AntInt9=getvect(9);//Le o endereco da Antiga Int 9 e guarda.
setvect(9,Funcao); // Instala ISR na memoria para monitorar o teclado
keep(0, (_SS + (_SP/16) - _psp));//retorna ao dos,mas recidente.
return;
}
