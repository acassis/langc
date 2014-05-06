int lin=1,col=1,h=0;
void teste()
{
      if(h==0)
	 col++;
      else
	 col--;
      if(col>78)
	 h=1;
      if(col<1)
	 h=0;
}
void main()
{
   clrscr();
inicio:
   for(;lin<23;lin++)
   {
      teste();
      gotoxy(col,lin);
      printf("Û");
      delay(200);
   }
   for(;lin>1;lin--)
   {
      teste();
      gotoxy(col,lin);
      printf("Û");
      delay(200);
   }
   goto inicio;

}