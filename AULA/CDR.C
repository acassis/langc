#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
int main(int argc, char *argv[])
{  char *name;
   if( (argc > 2) && (argc <2) )
   {
   puts("numero de parametros invalidos");
   return 0;
   }
   strcpy(name,"cd\\");
   strcat(name,argv[1]);
   system(name);
   system("dir");
   getch();
   return 0;
}