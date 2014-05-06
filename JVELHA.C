
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <iostream.h>

char matrix[3][3]; // Matriz bidimensional global

char check( void );
void init_matrix( void );
void get_player_move( void );
void get_computer_move( void );
void disp_matrix( void );
//---------------------------------------------------------------------------

int main()
{
ÿÿ int done;
ÿÿ printf("Este e o jogo da velha.\n");
ÿÿ printf("Voce estara jogando contra oÿ computador.\n");
ÿÿ done = atoi(" ");
ÿÿ init_matrix( );
ÿÿ do {
ÿÿÿÿÿ disp_matrix( );
ÿÿÿÿÿ get_player_move( );
ÿÿÿÿÿ done = atoi(check( )); // Verifica se ha vencedor
ÿÿÿÿÿ if( done !=atoi(" "))
ÿÿÿÿÿÿÿÿ break;
ÿÿÿÿÿ get_computer_move( );
ÿÿÿÿÿ done = atoi(check( ));
ÿÿ } while( done == atoi(" "));
ÿÿ if( done == atoi("X"))
ÿÿÿÿ printf("\nVoce ganhou!!\n");
ÿÿ else
ÿÿÿÿ printf( "\nEu ganhei!!\n");
ÿÿ disp_matrix( ); // Mostra as posi‡äes finais
ÿÿ return 0;
}
//---------------------------------------------------------------------------
// Inicializa a matriz
void init_matrix( void )
{
ÿÿ for( int i = 0; i < 3; i++ )
ÿÿÿÿ for( int j = 0; j < 3; j++ )
ÿÿÿÿÿÿ matrix[i][j] = ' ';
}

//---------------------------------------------------------------------------
// Obtem a sua jogada
void get_player_move( void )
{
ÿÿ int x, y;
ÿÿ printf( "Entre com a coordenada para o X:\n");
ÿÿ printf( " x = ";
ÿÿ scanf("%d",&x);ÿ
ÿÿ printf( " y = ");
ÿÿ scanf("%d",&y);
ÿÿ x--;
ÿÿ y--;
ÿÿ if( matrix[x][y] != ' ' ) {
ÿÿÿÿ printf( "Posicao invalida. tente novamente.\n");
ÿÿÿÿ get_player_move( );
ÿ } else
ÿÿÿÿ matrix[x][y] = 'X';
}

//---------------------------------------------------------------------------
// Obtem uma jogada do computador
void get_computer_move( void )
{
ÿÿ int i, j;
ÿÿ for( i = 0; i < 3; i++ ) {
ÿÿÿÿ for( j = 0; j < 3; j++ )
ÿÿÿÿÿÿ if( matrix[i][j] == ' ' )
ÿÿÿÿÿÿÿÿÿ break;

ÿÿÿÿ if( matrix[i][j] == ' ' )
ÿÿÿÿÿÿ break;
ÿÿ }
ÿÿ if( i * j == 9 ) {
ÿÿÿÿ printf( "Empate\n");
ÿÿÿÿ getch( );
ÿÿÿÿ exit( 0 ); // Finaliza o programa
ÿÿ } elseÿ
ÿÿÿÿ matrix[i][j] = 'O';
}

//---------------------------------------------------------------------------
// Mostra a matriz na tela
void disp_matrix( void )
{
ÿÿ int t;
ÿÿ printf( "\n\n");
ÿÿ for( t = 0; t < 3; t++ ) {
ÿÿÿÿ printf( " %c | %c | %c ", matrix[t][0],ÿ
ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ matrix[t][1], matrix[t][2] );
ÿÿÿÿ if( t != 2 )
ÿÿÿÿÿÿÿ printf( "\n---|---|---\n");ÿ
ÿÿ }
ÿÿ printf( "\n\n");
}

//---------------------------------------------------------------------------
// Verifica se ha um vencedor
char check( void )
{
ÿÿ int i;
ÿÿ for( i = 0; i < 3; i++ ) // verifica as linhas
ÿÿÿÿÿ if( matrix[i][0] == matrix[i][1] &&
ÿÿÿÿÿÿÿÿÿ matrix[i][0] == matrix[i][2] )
ÿÿÿÿÿÿÿÿ return matrix[i][0];

ÿÿÿ for( i = 0; i < 3; i++ ) // verifica as colunas
ÿÿÿÿÿ if( matrix[0][i] == matrix[1][i] &&
ÿÿÿÿÿÿÿÿÿ matrix[0][i] == matrix[2][i] )
ÿÿÿÿÿÿÿ return matrix[0][i];

ÿÿÿ // testa as diagonais
ÿÿÿ if( matrix[0][0] == matrix[1][1] &&
ÿÿÿÿÿÿÿ matrix[1][1] == matrix[2][2] )
ÿÿÿÿÿ return matrix[0][0];

ÿÿÿ if( matrix[0][2] == matrix[1][1] &&
ÿÿÿÿÿÿÿ matrix[1][1] == matrix[2][0] )
ÿÿÿÿÿ return matrix[0][2];
ÿ
ÿÿÿ return ' ';
}