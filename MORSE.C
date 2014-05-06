#include <string.h>
void main()
{

    long ct=0,cnt=0;
    char frase[80], *mai, mor[300],ch,morse[40][6]={{".-"   },{"-..." },{"-.-." },{"-.."  },{"."    },{"..-." },{"--."  },{"...." },{".."   },{".---" },{"-.-"  },{".-.." },{"--"   },{"-."   },{"---"  },{".--." },{"--.-" },{".-."  },{"..."  },{"-"    },{"..-"  },{"...-" },{".--"  },{"-..-" },{"-.--" },{"--.." },{"-----"},{".----"},{"..---"},{"...--"},{"....-"},{"....."},{"-...."},{"--..."},{"---.."},{"----."}};
     clrscr();
     puts("Digite uma frase para ser transformada em codigo morse!(max. 80 caracteres.):");
     gets(frase);
     mai = strupr(frase);
     for(;*mai!='\0';mai++)
      {
	 int i=0;
	 ch = *mai;
	 if(ch>='A' && ch<='Z')
	 {
	  for(i=0;morse[(*mai)-65][i]!='\0';i++)
	   {
	      *(mor + ct++) = morse[(*mai)-65][i];
	   }
	 }
	 else
	 {
	    if(ch>='0' && ch<='9')
	     {
		  for(i=0;morse[(*mai)-22][i]!='\0';i++)
		   {
		     *(mor + ct++) = morse[(*mai)-22][i];
		   }
	     }
	 }
      }
      *(mor + ct) = '\0';
      printf("\n %s ",mor);
      while(cnt<ct)
      {
	  ch = *(mor+cnt);
	  if(ch=='.')
	   {
	     sound(300);
	     delay(50);
	     nosound();
	   delay(100);
	   }
	  else
	   if(ch=='-')
	   {
	     sound(300);
	     delay(500);
	     nosound();
	     delay(100);
	   }
	   cnt++;
      }
}

