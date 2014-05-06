//----------------------------------------------------------------------------
//Programa: Display.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Este programa serve p/ mostra a horas e minutos em 4 displays de
//sete(7) segmentos ligados `a porta paralela.
//A logica e a seguinte:nos 4 bits menos significativos da porta paralela temos
//um digito BCD(0 a 9) que ligados ao CI-4511 acende um dos 4 display's (ligados
//em paralelo) com o digito correspondente(0 a 9) e os 4 bits mais significativos
//estao cada um ligados ao comum de um dos 4 display's.
//-----------------------------------------------------------------------------
#include<dos.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int hora,minu,segu;
char tempo[11];
struct  time t;
void main()
{
   while(!kbhit()){
    gettime(&t);
    hora = t.ti_hour;
    minu=t.ti_min;
    segu=t.ti_sec;
    sprintf(tempo,"%02d:%02d:%02d",hora,minu,segu);
    gotoxy(36,12);
    printf("   %s   ",tempo);
    outportb(0x378,224 + (tempo[4]-48));     //display1-> 224 + N§
    delay(1);
    outportb(0x378,208 + (tempo[3]-48));     //display2-> 208 + N§
    delay(1);
    outportb(0x378,176 + (tempo[1]-48));     //display3-> 176 + N§
    delay(1);
    outportb(0x378,112 + (tempo[0]-48));     //display4-> 112 + N§
    delay(1);
  }
}
