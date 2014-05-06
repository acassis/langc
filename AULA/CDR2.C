#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
int main(int argc, char *argv[])
{  char no[]="cd\\",name[30];
   if( (argc > 2) && (argc <2) )
   {
   puts("numero de parametros invalidos");
   return 0;
   }
   if(strcmp(argv[1],"\\")==0)
     {
       system("cd\\");
       return 0;
      }

   strcpy(name,no);
   strcat(name,argv[1]);
   system(name);
   system("dir");
   getch();
   return 0;
}