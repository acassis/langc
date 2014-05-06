/*Sirene.c*/
#define PORTA_SOM 0x61
#define TIMER2_INIT 0x43
#define TIMER2_VAL 0x42
#define ESC 27
main ()
{
  int i;
  char ch;
  unsigned char byte;
  union  {
	   unsigned int nr;
	   unsigned char hilo[2];
	 }valor;

	valor.nr=0x500;
	outportb ( TIMER2_INIT, 0xB6);
	byte = inportb (PORTA_SOM);
	byte =byte | 55;
	while(1)
	{
	  outportb (TIMER2_VAL,valor.hilo[0]);
	  outportb (TIMER2_VAL,valor.hilo[1]);
	  outportb (PORTA_SOM,byte);
	  for (i=0;i<200;i++);
	  ch=getch();
	  switch (ch)
	   {

	     case '1':
		     valor.nr+=valor.nr/0x100;
		     break;
	     case '2':
		     valor.nr-=valor.nr/0x100;
		     break;
	     case '9':
		     byte=byte | 3;
		     break;
	     case '0':
		     byte=byte & 0xfc;
		     break;
	     case ESC :
		     outportb(PORTA_SOM,byte & 0xfd);
		     exit();
	   }
	}
}