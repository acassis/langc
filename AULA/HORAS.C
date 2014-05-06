#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include <string.h>
struct  time t;
/*
struct time {
  unsigned char  ti_min;
  unsigned char  ti_hour;
  unsigned char  ti_hund;
  unsigned char  ti_sec;
};
*/
main()
{
   gettime(&t);
   printf("\n%02d:%02d:%02d",t.ti_hour,t.ti_min,t.ti_sec);
   printf("\n%d",t.ti_hund);
}