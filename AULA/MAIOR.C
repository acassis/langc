#include <stdio.h>
#include <conio.h>
/* programa que retorna o maior*/
int maior(void)
{ int x,y;
  printf("\ndigite dois numeros");
  scanf("%d%d",&x,&y);
  return(x>y)?x:y;
  }
main()
{ clrscr();
  printf("%d",maior());
  getch();
}
