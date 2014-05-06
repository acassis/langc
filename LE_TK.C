void main()
{
  clrscr();
  while(1){
      gotoxy(40,12);
      printf("%d  ",inportb(0x60));}

}