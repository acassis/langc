

#define limpatela      clrscr();
#define imprimir(x)    printf(x);
#define escreve(f)      printf("%d",f);
#define linha(x,y)      gotoxy(y,x);
#define say(w)          puts(w);
#define get(r)          scanf("%d",&r);
#define gets(t)         gets(t);
#define inicio         main(){
#define fim            }
#define inteiro(y)      int y;
#define caracter(g)     char *g;
#define buffer          flushall();
inicio
inteiro(a)
caracter(b)
limpatela
linha(10,10)
imprimir("entre com um numero")
get(a)
buffer
linha(11,10)
imprimir("entre com uma string")
gets(b)
linha(12,10)
say(b)
linha(13,10)
escreve(a)
fim