/*

elabore um programa que abra um  diretorio
int remove(const char *nomearquivo);
*/
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <conio.h>
void main(void)
{   int status;
    opendir("\\windows");
    system("dir");
    getch();
}