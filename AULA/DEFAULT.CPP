#include<iostream.h>
#include<conio.h>
void caixa(int li=1,int ci=1,int lf=20,int cf=78)
{
for(int l=li;l<lf;l++)
 for(int o=ci;o<cf;o++)
    {gotoxy(o,l);
     cout<<' ';
    }
for(int i=ci;i<=cf;i++)
{
  gotoxy(i,li);
  cout<<'Û';
  gotoxy(i,lf);
  cout<<'Û';
}
for(int j=li;j<lf;j++)
{
  gotoxy(ci,j);
  cout<<'Û';
  gotoxy(cf,j);
  cout<<'Û';
}
}
void main(void)
{
caixa(1,1,22,75);
}