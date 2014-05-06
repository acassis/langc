#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>

#include "d:\lixo\roda\rotspr.h"

#define LARGSPRITE 32
#define ALTSPRITE 32

int main()
{
    FILE *s;
    int a, b, c=1;
    double angulo = 0;
    char sprite[LARGSPRITE*ALTSPRITE];
    if ((s=fopen("c:\\windows\\egito.bmp","rb"))==NULL)
    {
	puts("Arquivo n∆o encontrado!");
	exit(1);
    }

    //fseek(s, 0x3058, SEEK_SET);

    memcpy(sprite, s, LARGSPRITE*ALTSPRITE);


    //memset(sprite, 0, LARGSPRITE*ALTSPRITE);
    /*preencher sprite*/
    /*for (a = 0; a < ALTSPRITE; a++)
    //{
    //	if (a > (ALTSPRITE/3)) c = 2;
    //	if (a > (ALTSPRITE/3 * 2)) c = 3;
    //	//if (a != 4 && a != 5) - preenchimento alternativo*/
    //	for (b = 0; b < LARGSPRITE; b++)
    //	{
    //	    //if (b != 4 && b != 5) - preenchimento alternativo*/
    //	    sprite[a * LARGSPRITE + b] = c;
    //	}
    //}

    setamodo(0x13); /*Modo de video 320x200x256*/
    limpa(tela, 0, LARGURA*ALTURA);

    while (/*(angulo < 10) &&*/ !kbhit())
    {
        retraco();
        mostra_rot_sprite(sprite, 100, 80, LARGSPRITE, ALTSPRITE, angulo, 50);
        delay(150);
        limpa(tela, 0, LARGURA*ALTURA);
        angulo += 0.1;
    }

    setamodo(0x3); /*modo de video DOS*/
    return 0;
}
