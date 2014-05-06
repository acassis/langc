/*
Cores v lida para textcolor() e textbackground()

0-BLACK      8- DARKGRAY
1-BLUE       9- LIGHTBLUE
2-GREEN     10- LIGHTGREEN
3-CYAN      11- LIGHTCYAN
4-RED       12- LIGHTRED
5-MAGENTA   13- LIGHTMAGENTA
6-BROWN     14- YELLOW
7-LIGHTGRAY 15- WHITE
*/
void posc(int lin, int col)
{
 gotoxy(col,lin);
}
void cor(int fr,int fu, int pisc)
{
 if(pisc==1)
   textcolor(fr+ BLINK );
 else
    textcolor(fr);
 textbackground(fu);
 }
void borda(int li, int ci,int lf, int cf)
 {
   int i;
   for(i=li;i<=lf;i++)
      {
       posc(i,ci);
      cprintf("²");
       posc(i,cf);
       cprintf("²");
       }
       for(i=ci;i<=cf;i++)
       {
	posc(li,i);
	cprintf("²");
	posc(lf,i);
	cprintf("²");
	}
}
void limpa(int li,int ci, int lf,int cf)
{
  int i,j;
  for(i=li;i<=lf;i++)
    for(j=ci;j<=cf;j++)
      {
	posc(i,j);
	cprintf(" ");
	}
}
