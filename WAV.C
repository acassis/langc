#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <alloc.h>
#include <dos.h>
#include <io.h>

#define DEF_FREQ 16000
#define DEF_VELC 1
#define DEF_MUDO 1

typedef struct {
	char filename[64];
	char huge *data;
	long frequency;
	long file_length;
	long sample_length;
}	WAVFILE;


/* Funcoes que estavam em assembler em outro arquivo */

void interrupt far NewInt8Function( void );
void PlaySound( char huge *data, int countdown, int os);

/*Ponteiro Interrupcao para lembrar onde a velha rotina int 8 estava */

void interrupt (*OldInt8Function)();

/* Variaveis globais com valores padrao */

long frequency = DEF_FREQ;
int mudo = DEF_MUDO;
int velocidade = DEF_VELC;
char filename[64] = "\0";
unsigned char value=0;

/* Load_Voc abre e le arquivos WAV ou VOC, e retorna um ponteiro para uma
estrutura WAVFILE que estara preenchida com aquele. Se o arquivo nao puder
ser aberto, ou nao houver memoria disponivel, Load_Voc returna NULL */

WAVFILE *Load_Voc( char *filename )
{
	WAVFILE *vf;
	FILE	*f;
	long	fl, cfl;
	char	ch;
	char	huge *fptr;
	int	cnt;

/* Aloca memoria p/ uma estrutura WAVFILE*/

	vf = malloc( sizeof(WAVFILE) );
	if ( vf == NULL )
	   return ( (WAVFILE *)NULL );

	strcpy( vf->filename, filename );

/* Abre o arquivo VOC ou WAV*/

	f = fopen( filename, "rb" );
	if ( f == NULL ) {
		free( vf );
		printf("O arquivo: \"%s\" nao foi encontrado!",filename);
		return ( (WAVFILE *)NULL );
		}

/* Pega o tamanho, e alloca memoria p/ o arquivo*/

	fl = filelength( fileno(f) ) - 26;
	fptr = farmalloc( fl+1 );

/* Se alocacao de memoria OK, lemos o arquivo e preenchemos a memoria */

	if ( fptr != NULL ) {
		vf->data = fptr;
		vf->file_length = fl;
		vf->frequency = frequency;

		fseek( f, 26, SEEK_SET );
		cfl = fl;

		while ( cfl-- > 0 )
		  *fptr++ = (fgetc(f) >> mudo);

		*fptr = 0xFF;  /* Indica fim do som! */
		vf->sample_length = 1 + (fptr-vf->data);
		}

/* Fecha o arquivo e sai! */

	fclose(f);
	return( vf );
}

void	Play_Voc( WAVFILE *vf )
{
       //Aqui achamos o valor real que teremos que enviar ao contador p/ que
       //gere a frequencia esperada!
	int countdown=(int)(1193180L / vf->frequency);

	printf( "Arquivo: %s\n\n", vf->filename );

	OldInt8Function = getvect( 0x08 );
	setvect( 0x08, NewInt8Function );
	PlaySound(vf->data, countdown, velocidade);
	setvect( 0x08, OldInt8Function );
}

/* Delete_Voc e usada pra liberar a memoria alocada p/ o arquivo*/

void Delete_Voc( WAVFILE *vf )
{
	if ( vf )
	{
	   free(vf);
	}
}

void main( int argc, char **argv )
{
	WAVFILE *vf;
	int pc;
	printf("\nEste programa toca WAV ou VOC de 8bits no pc speaker!\n\r");
	printf("Caso o WAV ou VOC nao forem de 8bits, converta-o!\n\n");
	if ( argc < 1 )
	{
		printf("Informe um nome de arquivo WAV ou VOC!\n");
		printf("WAV nome_do_arquivo.wav\n");
		return;
	}

	strcpy(filename,argv[1]);

	if ( strlen(filename) == 0 ) {
		printf( "Voce precisa informar um nome de arquivo WAV ou VOC!\n" );
		return;
		}

	vf = Load_Voc( filename );
	if ( vf ) {
		Play_Voc( vf );
		Delete_Voc( vf );
		}
	else
		printf( "\n\nNao consegui ler o arquivo: \"%s\" por alguma razao..\n\n",filename);
}

void interrupt far NewInt8Function( void )
{
    outportb(0x20,0x20);
}

void PlaySound( char huge *data, int countdown, int os)
{
	unsigned char valor=0;
	int porta;
	union
	{
	   int contador;
	   unsigned char cont[2];
	}contagem;

	// Set up timer 2 to only expect 1 byte countdown values, and to only
	//generate one pulse
	outportb(0x43,0x90);

	//Connect timer 2 to the speaker
	valor = inportb(0x61);
	outportb(0x61,valor | 3);

	// Set timer 0 up with the specified playback frequency
	outportb(0x43,0x36);
	contagem.contador = countdown;
	outportb(0x40,contagem.cont[2]);
	outportb(0x40,contagem.cont[1]);

	while(valor != 0xFF)
	{
	   int i;
	   for(i=0;i<os;i++)
	     valor = ((unsigned char) *data++);
	   asm hlt
	   outportb(0x42,valor);
	}

	//Set the timer back to its original settings (18.2Hz)
	outportb(0x43,0x36);
	outportb(0x40,0);
	outportb(0x40,0);

	//Set timer 2 back to its original settings
	outportb(0x43,0xB6);

	//Disconnect timer 2 from the speaker
	valor = inportb(0x61);
	outportb(0x61,valor&0xFC);
}
