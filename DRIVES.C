void main()
{
   clrscr();
   while(!kbhit())
     outport(0x3f0,255);
}