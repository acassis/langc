# define ESC 0x1B
void main ()
{

 static int freq[]={

	    262, /*  C4  */
	    294, /*  D4  */
	    330, /*  E4  */
	    347, /*  F4  */
	    392, /*  G4  */
	    440, /*  A4  */
	    494, /*  B4  */
	    524,
	    1635,};/*  C0  */


 unsigned ch;
 while ((ch=getch())!=ESC)
  {
    ch=(ch-'0')%4;
    sound (freq[ch],9);
  }
sound(16.35);
}