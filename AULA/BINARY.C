#include <stdio.h>
void main(void)
{
  int j,num,bit;
  unsigned int mask;
  while(1)
  {  mask=0x8000;
     printf("\ndigite n£mero:");
     scanf("%x",&num);
     printf("\nbinario de %04x ‚: ",num);
     for(j=0;j<16;j++)
     {
       bit= (mask & num)?1:0;
	      printf("%d",bit);
       if(j==7)
	 printf("--");

       mask>>=1;
      }
    }
}


