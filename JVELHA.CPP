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
�� int done;
�� printf("Este e o jogo da velha.\n");
�� printf("Voce estara jogando contra o� computador.\n");
�� done = atoi(" ");
�� init_matrix( );
�� do {
����� disp_matrix( );
����� get_player_move( );
����� done = atoi(check( )); // Verifica se ha vencedor
����� if( done !=atoi(" "))
�������� break;
����� get_computer_move( );
����� done = atoi(check( ));
�� } while( done == atoi(" "));
�� if( done == atoi("X"))
���� printf("\nVoce ganhou!!\n");
�� else
���� printf( "\nEu ganhei!!\n");
�� disp_matrix( ); // Mostra as posi��es finais
�� return 0;
}




//---------------------------------------------------------------------------
// Inicializa a matriz
void init_matrix( void )
{
�� for( int i = 0; i < 3; i++ )
���� for( int j = 0; j < 3; j++ )
������ matrix[i][j] = ' ';
}

//---------------------------------------------------------------------------
// Obtem a sua jogada
void get_player_move( void )
{
�� int x, y;
�� printf( "Entre com a coordenada para o X:\n");
�� printf( " x = ";
�� scanf("%d",&x);�
�� printf( " y = ");
�� scanf("%d",&y);
�� x--;
�� y--;
�� if( matrix[x][y] != ' ' ) {
���� printf( "Posicao invalida. tente novamente.\n");
���� get_player_move( );
� } else
���� matrix[x][y] = 'X';
}

//---------------------------------------------------------------------------
// Obtem uma jogada do computador
void get_computer_move( void )
{
�� int i, j;
�� for( i = 0; i < 3; i++ ) {
���� for( j = 0; j < 3; j++ )
������ if( matrix[i][j] == ' ' )
��������� break;

���� if( matrix[i][j] == ' ' )
������ break;
�� }
�� if( i * j == 9 ) {
���� printf( "Empate\n");
���� getch( );
���� exit( 0 ); // Finaliza o programa
�� } else�
���� matrix[i][j] = 'O';
}

//---------------------------------------------------------------------------
// Mostra a matriz na tela
void disp_matrix( void )
{
�� int t;
�� printf( "\n\n");
�� for( t = 0; t < 3; t++ ) {
���� printf( " %c | %c | %c ", matrix[t][0],�
������������������ matrix[t][1], matrix[t][2] );
���� if( t != 2 )
������� printf( "\n---|---|---\n");�
�� }
�� printf( "\n\n");
}

//---------------------------------------------------------------------------
// Verifica se ha um vencedor
char check( void )
{
�� int i;
�� for( i = 0; i < 3; i++ ) // verifica as linhas
����� if( matrix[i][0] == matrix[i][1] &&
��������� matrix[i][0] == matrix[i][2] )
�������� return matrix[i][0];

��� for( i = 0; i < 3; i++ ) // verifica as colunas
����� if( matrix[0][i] == matrix[1][i] &&
��������� matrix[0][i] == matrix[2][i] )
������� return matrix[0][i];

��� // testa as diagonais
��� if( matrix[0][0] == matrix[1][1] &&
������� matrix[1][1] == matrix[2][2] )
����� return matrix[0][0];

��� if( matrix[0][2] == matrix[1][1] &&
������� matrix[1][1] == matrix[2][0] )
����� return matrix[0][2];
�
��� return ' ';
}