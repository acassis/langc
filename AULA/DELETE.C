/*
elabore um programa que apague arquivos
int remove(const char *nomearquivo);
*/
#include <stdio.h>
void main(int argc,char **argv)
{ int i=1;
 if(argc==2)
  {
    while(*argv++)
      {
	if(remove(*argv))
	   printf("error ao apagar arquivo %s\n",*argv);
	else
	  printf("\napagando %s",*argv);
      }
   }
   else
       printf("parametros invalidos");
}