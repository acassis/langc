void main (void)
{
 int x=10,y=12,*p1=&x,*p2=&y;
 clrscr();
 printf("%d*%d=%d",*p1,*p2,*p1**p2);
}