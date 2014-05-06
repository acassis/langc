#include <stdio.h>
#include <dos.h>

int main(void)
{
   struct fatinfo diskinfo;
   int flag = 0;

   printf("Coloque um diskete no drive A\n");
   getchar();

   getfat(1, &diskinfo);
/* le a informacoes do diskete */

   printf("\nDrive A: ");
   switch((unsigned char) diskinfo.fi_fatid)
   {
      case 0xFD:
	printf("360K\n");
	break;

      case 0xF9:
	printf("1.2 M\n");
	break;
      case 0xF0:
	printf("1.4 M\n");
	break;
      default:
	printf("nao formatado\n");
	flag = 1;
   }

   printf("  setores por cluster %5d\n",
	      diskinfo.fi_sclus);
   printf("   numer0 de clusters %5d\n",
	      diskinfo.fi_nclus);
   printf("     bytes por setores %5d\n",
	      diskinfo.fi_bysec);
   getch();
   return 0;
}

