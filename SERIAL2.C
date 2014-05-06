void main()
{
   char ch;
   clrscr();
   while(!kbhit())
   {
      ch=inportb(0x3f8);
      //gotoxy(40,12);
      printf("\n  %c  ",ch);
      delay(50);
   }
}