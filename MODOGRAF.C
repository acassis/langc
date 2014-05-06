#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
/*   request auto detection*/
   int gdriver = DETECT, gmode, errorcode;

/*   initialize graphics mode*/
   initgraph(&gdriver, &gmode, "c:\\bc\\bgi");

/*   read result of initialization*/
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }

   printf("Modo grafico iniciado com sucesso");
   getch();
   closegraph();
   return 0;
}

