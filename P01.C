void troca(int *x, int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}

void main(void)
{
 int a=10,b=20;
 clrscr();
 printf ("%d %d\n",a,b);
 troca(&a,&b);
 printf("\n%d %d",a,b);
}

