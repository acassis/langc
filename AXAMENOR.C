#include <stdio.h>
#include <dir.h>
int main(void)
{
   struct ffblk ffblk;
   unsigned int done,tamanho=0;
   char nome[13];
   clrscr();
   printf("Directory listing of *.*\n");
   done = findfirst("*.exe",&ffblk,0);
   strcpy(nome,ffblk.ff_name);
   tamanho=ffblk.ff_fsize;
   while (!done)
   {
      printf("  %s %d\n", ffblk.ff_name,tamanho);
      done = findnext(&ffblk);
      if(tamanho>ffblk.ff_fsize)
      {
	 strcpy(nome,ffblk.ff_name);
	 tamanho=ffblk.ff_fsize;
      }
      delay(250);
   }
   printf(" O menor arquivo e': %s ",nome);
   getch();
   return 0;
}