#include <stdio.h>
#include <conio.h>

/* menu que retorna caracter*/
char menu(void)
{
  char op;
  printf("\ni-incluir\na-alterar\ne-excluir\ns-sair");
  op=getche();
  return(op);
}
main()
{
  printf("%c",menu());
  getch();
}