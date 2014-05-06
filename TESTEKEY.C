void main()
{
   unsigned char ch,chant,lin=2,col=4,up=0,down=0,right=0,left=0;
   int far *key = (int far *)0x0040001A;
   while(ch!=1)
   {
      ch = inportb(0x60);
      gotoxy(1,1);
      *key = *(key+1);
      printf(" %d ",ch);

      if(ch==72)
	 up=1;
      if(ch==80)
	 down=1;
      if(ch==75)
	 left=1;
      if(ch==77)
	 right=1;

      if(ch==200)
	 up=0;
      if(ch==208)
	 down=0;
      if(ch==203)
	 left=0;
      if(ch==205)
	 right=0;

      if(ch==170)
       {
	  if(chant==72)
	     up=0;
	  else
	    if(chant==80)
	       down=0;
	     else
	       if(chant==75)
		  left=0;
	       else
		 if(chant==77)
		    right=0;
       }
      chant = ch;
      gotoxy(1,2);
      if(up)
	 printf("Tecla up pressionada!");
      else
	 printf("Tecla up liberada!   ");

      gotoxy(1,3);
      if(down)
	 printf("Tecla down pressionada!");
      else
	 printf("Tecla down liberada!   ");

      gotoxy(1,4);
      if(left)
	 printf("Tecla left pressionada!");
      else
	 printf("Tecla left liberada!   ");

      gotoxy(1,5);
      if(right)
	 printf("Tecla right pressionada!");
      else
	 printf("Tecla right liberada!   ");

    }
}