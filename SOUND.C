void main()
{
  int val=0,ct=0;
  char ch;
  clrscr();
  while(1)
  {
   gotoxy(32,12);
   clrscr();
   printf("Informe um valor: %d   ",val);
   //scanf("%f",&val);
 if(!(val>199 && val<203 || val>455 && val<459 || val>711 && val<715))
 {
   outportb(0x220,val);
   outportb(0x221,val);
   outportb(0x222,val);
   outportb(0x223,val);
   outportb(0x224,val);
   outportb(0x225,val);
   outportb(0x226,val);
   outportb(0x227,val);
   outportb(0x228,val);
   outportb(0x229,val);
   outportb(0x22a,val);
   outportb(0x22b,val);
   outportb(0x22c,val);
   outportb(0x22d,val);
   outportb(0x22e,val);
   outportb(0x22f,val);
   //ch=getch();
 }
  //if(ch==72)
  if(ct==0)
     val++;
  ct++;
  if(ct>35)
     ct=0;
  //if(ch==80)
    // val--;
  if(val==200)
     val=410;
  if(val>450)
     val=150;
  delay(1);
  }
}