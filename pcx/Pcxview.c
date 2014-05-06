#include <stdlib.h>
#include <dos.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <graphics.h>

void UnpackSvgaPcx(FILE *fh, char *Buffer, int Width, int Height);

void Text_Mode();

#include "d:\bc\ling_c\pcx\vesa.h"

//Translated in Rome, 20 March '97 by Konstantin Driblinov

void main(int argc, char *argv[])
{
char *pcxfile,p;

strcpy(pcxfile,"d:\\bc\\ling_c\\pcx\\casal.pcx");
question:
printf("\n\nWhat video resolution:\n\t\t1)640x480 256 col\n\t\t2)800x600 256 col\n\t\t3)1024x768 256 col\n\n\t\t4) Exit\n");
flushall();
p=getch();
if (p!='1' && p!='2' && p!='3'&& p!='4') goto question;
if (p=='1') {Pcx_vars.ScreenMode = 0x0101;Pcx_vars.DHeight = 480;Pcx_vars.DWidth = 640;}
if (p=='2') {Pcx_vars.ScreenMode = 0x0103;Pcx_vars.DHeight = 600;Pcx_vars.DWidth = 800;}
if (p=='3') {Pcx_vars.ScreenMode = 0x0105;Pcx_vars.DHeight = 768;Pcx_vars.DWidth = 1024;}
if (p=='4') {exit(1);}


VESA_SetMode(Pcx_vars.ScreenMode);
Open_SvgaPcx(pcxfile);
SetPcxPalette((char *)Pcx_vars.Palette);

VESA_UpdateScreen( Pcx_vars.ScreenMode, Pcx_vars.PcxBuffer,
		      Pcx_vars.DWidth, Pcx_vars.DHeight);
getch();
Text_Mode();
}


VESA_UpdateScreen(int ScreenMode, char *Buffer, int Width, int Height)
{

int j;
unsigned char far *tela;
tela = (unsigned char far *)0xA0000000;
for (j = 0; j < Pcx_vars.PageNumber; j++)
	{
	VESA_SetPage(j);
	memmove(tela,Buffer, 65536);
	Buffer += 65536;
	}

if (Pcx_vars.LastPage != 0)
	{
	VESA_SetPage(j);
	memmove(tela,Buffer,Pcx_vars.LastPage);
	}

return;
}
