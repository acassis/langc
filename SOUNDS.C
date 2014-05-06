#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#define ESPERE 500
void liga_speaker( void ) {
	asm {
		in al,0x61
		or al,3
		out 0x61,al
		}
}
void desliga_speaker( void ) {
	asm {
		in al,0x61
		and al,252
		out 0x61,al
		}
}
void habilita_contador( unsigned int countdown ) {
	char countlo, counthi;

	counthi = countdown/256;
	countlo = countdown-counthi;

	asm {
		mov dx,0x43   //Habilita o contador p/ gerar frequencias
		mov al,0xB6   //para o speaker
		out dx,al

		mov dx,0x42
		mov al,countlo
		out dx,al

		mov al,counthi
		out dx,al
		}
}

void gera_frequencia( long freq ) {
	unsigned int countdown;

	countdown = (unsigned int) (1193280L / freq);
	habilita_contador( countdown );
}

void teclou( void ) {
	if ( kbhit() ) {
		desliga_speaker();
		getch();
		exit(0);
		}
}

void main( void ) {
	int c;
	long f;
	clrscr();
	printf( "\nPressione ESCAPE p/ sair, ou outra tecla para continuar ...\n\n" );
	if ( getch() == 27 ) exit(0);

	printf( "A oitava de C4 (metade C) para C5 ..." );

	liga_speaker();

	gera_frequencia( 261 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 293 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 329 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 349 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 392 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 440 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 494 );
	teclou();
	delay(ESPERE);

	gera_frequencia( 523 );
	teclou();
	delay(ESPERE);

	desliga_speaker();

	delay(1000);

	printf( "\n\nAlarme ..." );
	liga_speaker();

	for ( c = 0; c < 5; c++ ) {
		teclou();
		gera_frequencia( 349 );
		delay(ESPERE);
		gera_frequencia( 261 );
		delay(ESPERE);
		}
	desliga_speaker();

	delay(1000);

	printf( "\n\nAlarme diferente ..." );
	liga_speaker();

	for ( c = 0; c < 5; c++ ) {
		teclou();
		for ( f = 200; f <= 800; f+=10 ) {
			gera_frequencia( f );
			delay(10);
			}
		teclou();
		for ( f = 800; f >= 200; f-=10 ) {
			gera_frequencia( f );
			delay(10);
			}
		}
	desliga_speaker();

	delay(1000);

	printf( "\n\nTiro de Laser ..." );

	for ( c = 0; c < 5; c++ ) {
	liga_speaker();
		teclou();
		for ( f = 2700; f >= 2000; f-=10 ) {
			gera_frequencia( f );
			delay(6);
			}
		desliga_speaker();
		delay(400);
		}

	printf( "\n\nAgora faca o seu!!\n\n" );
	getch();
}



