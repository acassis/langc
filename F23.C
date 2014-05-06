char maior(char x, char y)
{
 clrscr();
 if (x<y)
     return y;
  else
     return x;
  if (x==y)
     return x;
}

void main()
{
 char a,b;
 clrscr();
 puts("entre com dois caracteres:");
 a=getche();
 b=getche();
 printf("o maior caracter informado e:\n%c",maior(a,b));
}