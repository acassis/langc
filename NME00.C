#include <dos.h>
/* The clock tick interrupt */
#define INTR 0x1C
/* Screen attribute (blue on grey) */
#define ATTR 0x7900

/* reduce heaplength and stacklength
to make a smaller program in memory */
extern unsigned _heaplen = 1024;
extern unsigned _stklen  = 512;

void interrupt ( *oldhandler)(void);

void interrupt handler(void)
{
   unsigned int (far *screen)[80];
   static int count;

/* For a color screen the video memory
   is at B800:0000.  For a monochrome
   system use B000:000 */
   screen = MK_FP(0xB800,0);

/* increase the counter and keep it
   within 0 to 9 */
   count++;
   count %= 10;

/* put the number on the screen */
   screen[0][79] = count + '0' + ATTR;

/* call the old interrupt handler */
   oldhandler();
}

int main(void)
{

/* get the address of the current clock
   tick interrupt */
oldhandler = getvect(INTR);

/* install the new interrupt handler */
setvect(INTR, handler);

/* _psp is the starting address of the
   program in memory.  The top of the stack
   is the end of the program.  Using _SS and
   _SP together we can get the end of the
   stack.  You may want to allow a bit of
   saftey space to insure that enough room
   is being allocated ie:
   (_SS + ((_SP + safety space)/16) - _psp)
*/
keep(0, (_SS + (_SP/16) - _psp));
return 0;
}

