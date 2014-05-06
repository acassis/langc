int i,j;
char mt[3][3];

struct seq
{
   int v;
   int e;
   int d;
}res[9];

void exibi()
{
	gotoxy(34,10);
	puts("   Ё   Ё  ");
	gotoxy(34,11);
	puts("дддедддеддд");
	gotoxy(34,12);
	puts("   Ё   Ё  ");
	gotoxy(34,13);
	puts("дддедддеддд");
	gotoxy(34,14);
	puts("   Ё   Ё ");

	for(j=0;j<3;j++)
	 for(i=0;i<3;i++)
	 {
	   gotoxy(4*i+35,2*j+10);
	   printf("%c",mt[i][j]);
	 }
}
void main()
{
   int p[9],tmp[9],x,y;
   clrscr();
   for(j=0;j<3;j++)
     for(i=0;i<3;i++)
     {
       mt[i][j]=' ';
       p[3*j + i]=0;
       res[3*j + i].v = res[3*j + i].e = res[3*j + i].d = 0;
     }
   exibi();

 while(1)
 {
   puts("\nInforme um posicao: coluna  linha");
   scanf("%d %d",&x,&y);
   x--;
   y--;
   mt[x][y] = 'X';
   p[3*y + x]=1;
   res[3*y + x].v = res[3*y + x].e = res[3*y + x].d = 2;
   exibi();
   for(j=0;j<3;j++)
    for(i=0;i<3;i++)
    {
      tmp[3*j + i] = p[3*j + i];
      if(tmp[3*j + i] == 1 || tmp[3*j + i] == 2)
	 continue;

    }
 }
}