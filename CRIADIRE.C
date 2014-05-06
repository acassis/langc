#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <dir.h>

int main(void)
{
  int status;
  char diret[8];
     clrscr();
   puts("Informe o nome do diretorio a ser criado:");
   gets(diret);
   status = mkdir(diret);
   (!status) ? (printf("Diretorio criado\n")) :
	       (printf("Unable to create directory\n"));

   getch();
   system("dir");
   getch();
   return 0;
}
