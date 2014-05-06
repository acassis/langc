/*
OS OPERADORES BIT-A-BIT
Os 6 operadores bit-a-bit:

opera‡Æo                s¡mbolo

E(and)                    &
ou(or)                    |
ou exclusivo (xor)        &
deslocamento … direita    >>
deslocamento … esquerda   <<
complemento                ~

	Os operadores bit-a-bit podem ser aplicados somente a vari veis dos tipos
char ou int(com ou sem sinal), mas nÆo a n£meros em ponto flutuante, double, long
double, void ou outros tipos mais complexos.

O  OPERADOR AND (&) BIT-A-BIT

	Testa se um bit est  ligado.
*/

#include <stdio.h>
main()
{
  unsigned int a1,a2;
  while(1)
  {  printf("\ndigite dois n£meros hexa (ff ou menor): p/ calcular AND ");
     scanf("%x",&a1);
     scanf("%x",&a2);
     printf("\n%x & %x =%x",a1,a2,(a1 & a2));
    }
}