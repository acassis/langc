//----------------------------------------------------------------------------
//Programa: Bit.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao:Exercicio de livros, maneira simples de acessar determinado bit de um byte
//-----------------------------------------------------------------------------

struct byte
{
  unsigned bit7:2;
  unsigned bit6:2;
  unsigned bit5:2;
  unsigned bit4:2;
  unsigned bit3:2;
  unsigned bit2:2;
  unsigned bit1:2;
  unsigned bit0:2;
}bit;
void main()
{
   unsigned char *val;
   val = (unsigned int) &bit;
   puts("Informe um numero:");
   scanf("%d",&val);
   printf("\n%d-%d-%d-%d-%d-%d-%d-%d\n\n",bit.bit7,bit.bit6,bit.bit5,bit.bit4,bit.bit3,bit.bit2,bit.bit1,bit.bit0);
   flushall();
   getch();
}
