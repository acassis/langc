void troca(int x, int y);
void main (void)
{
 int a=10,b=20;
 clrscr();
 printf("%d %d\n",a,b);
 troca(a,b);
 printf("%d %d",a,b);
}

void troca(int x,int y)
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}