#include<stdio.h>
void main()
{
  int m,n,k,j,i,col=20,r=0;
  char *ta;
  clrscr();
  puts("Este Programa calcula o maximo divisor comum entre dois n�!");
  printf("\nInforme um n�:");
  scanf("%d",&m);
  printf("\nInforme outro n�:");
  scanf("%d",&n);
  clrscr();
  while(n!=0)
  {
    itoa(m,ta,10);
    i = strlen(ta);
    gotoxy(col,11);
    printf("%s",ta);
    gotoxy(col,13);
    printf("%d",m%n);
    if(m<r)
     {
      itoa(r,ta,10);
      i = strlen(ta);
     }
    for(j=0;j<i;j++)
     {
       gotoxy(col,10);
       printf("�");
       gotoxy(col,12);
       printf("�");
       col++;
     }
    gotoxy(col,9);
    printf("�");
    gotoxy(col,10);
    printf("�");
    gotoxy(col,11);
    printf("�");
    gotoxy(col,12);
    printf("�");
    gotoxy(col,13);
    printf("�");
    col++;
    gotoxy(col,9);
    printf("%d",m/n);
    r = m/n;
    gotoxy(col,11);
    printf("%d",n);
   k = (m%n);
   m = n;
   n = k;
  }
  itoa(m,ta,10);
  i = strlen(ta);
  if(m<r)
  {
    itoa(r,ta,10);
    i = strlen(ta);
  }
  for(j=0;j<i;j++)
   {
     gotoxy(col,10);
     printf("�");
     gotoxy(col,12);
     printf("�");
     col++;
   }
  gotoxy(20,24);
  printf("O maximo divisor comum e : %d",m);
  getch();
}