/*

elabore um programa que um  arquivo
int remove(const char *nomearquivo);
*/
#include <stdio.h>
void main(void)
{
    if(remove("delet.obj"))
      printf("error ao apagar arquivo \n");
}