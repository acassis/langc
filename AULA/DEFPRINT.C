/*
A diretiva #define tem a habilidade de usar argumentos. Uma diretiva #define
com argumentos ‚ chamada macro e ‚ bastante semelhante a uma fun‡Æo.
*/
#define PRN(n) printf("%.2f\n",n);
main()
{
 float n1=10;
 float n2=1.0/3.0;
 PRN(n1);
 PRN(n2);
}