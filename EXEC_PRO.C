#include <process.h>
#include <stdio.h>
#include <errno.h>

void main(int argc, char *argv[])
{
   int i;
   clrscr();
   printf("Command line arguments:\n");
   for (i=0; i<argc; i++)
      printf("[%2d] : %s\n", i, argv[i]);

   printf("About to exec child with arg1 arg2 ...\n");
   execv("d:\\proga\\lixo\\coratest.exe",argv);

   perror("exec error");

   exit(1);
}
