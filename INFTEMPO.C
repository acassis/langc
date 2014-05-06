#include <stdio.h>
#include <time.h>
#include <conio.h>

int main(void)
{
   time_t t;
   clrscr();
   time(&t);
   printf("Today's date and time: %s\n", ctime(&t));
   getch();
   return 0;
}

