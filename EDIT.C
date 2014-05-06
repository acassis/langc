#include <conio.h>
#include <string.h>

unsigned char far *tela = (unsigned char far *)0xB8000000;
int ct=0,fin,ver=0,coli,lini,colf,linf,cxa=0;
char ch;

typedef struct items
{
   char item[80];
}items;

items menu_arq[5],menu_edt[4],menu_hlp[3],info[7];
items *focu;

void menu()
{
  textcolor(7);
  textbackground(1);
  clrscr();
  gotoxy(1,1);
  cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
  textcolor(0);
  textbackground(7);
  gotoxy(3,1);
  cprintf("Arquivo");
  gotoxy(12,1);
  cprintf("Editar");
  gotoxy(20,1);
  cprintf("Help");
  textcolor(4);
  gotoxy(3,1);
  cprintf("A");
  gotoxy(12,1);
  cprintf("E");
  gotoxy(20,1);
  cprintf("H");
}
void inicia()
{
  menu();
  //Items do Menu Arquivo
  strcpy(menu_arq[0].item,"Novo   Ctrl+N");
  strcpy(menu_arq[1].item,"Abrir  Ctrl+A");
  strcpy(menu_arq[2].item,"Salvar Ctrl+S");
  strcpy(menu_arq[3].item,"Sair   Alt+F4");
  strcpy(menu_arq[4].item,"");
  //Items do Menu Editar
  strcpy(menu_edt[0].item,"Copiar   Ctrl+Ins");
  strcpy(menu_edt[1].item,"Recortar Ctrl+Del");
  strcpy(menu_edt[2].item,"Colar    Shift+Ins");
  strcpy(menu_edt[3].item,"");
  //Items do Menu Help
  strcpy(menu_hlp[0].item,"Comandos F1");
  strcpy(menu_hlp[1].item,"Sobre...");
  strcpy(menu_hlp[2].item,"");
  //Informacao Sobre o Programa
  strcpy(info[0].item,"EDITOR Versao 0.1");
  strcpy(info[1].item,"Em construcao por Alan");
  strcpy(info[2].item,"Mega-Logica Software");
  strcpy(info[3].item," ");
  strcpy(info[4].item,"Maiores Informacoes:");
  strcpy(info[5].item,"Ligue (0xx31)822-8819");
  strcpy(info[6].item,"");

}

void caixa(int coli,int lini, int colf, int linf, items *menu, int selec)
{
   int i=coli,j=lini;
   textcolor(0);
   textbackground(7);
   for(;j<=linf;j++)
     for(i=coli;i<=colf;i++)
       {
	 if(j==lini || j==linf)
	   {
	     gotoxy(i,j);
	     cprintf("%c",196);
	   }
	 else
	 if(i==coli || i==colf)
	   {
	     gotoxy(i,j);
	     cprintf("%c",179);
	   }
	   else
	   {
	     gotoxy(i,j);
	     cprintf(" ");
	   }
       }

    gotoxy(coli,lini);
    cprintf("%c",218);
    gotoxy(coli,linf);
    cprintf("%c",192);
    gotoxy(colf,lini);
    cprintf("%c",191);
    gotoxy(colf,linf);
    cprintf("%c",217);

    for(i=0;menu[i].item[0]!='\0';i++)
    {
       gotoxy(coli+1,lini+1+i);
       cprintf("%s",menu[i].item);
    }
    fin = i-1;
    if(ver!=0)
    for(i=2*(coli-1)+1;i<2*(colf-1)-1;i+=2)
       *(tela + 80*(2*(lini-1)+(2*selec+2)) + i + 2) = 32;
}

void alterna()
{
	 ct=0;
	 if(cxa==0)
	 {
	      focu=menu_arq;
	      coli=2;
	      lini=2;
	      colf=17;
	      linf=7;
	 }
	 else
	 if(cxa==1)
	 {
	      focu=menu_edt;
	      coli=12;
	      lini=2;
	      colf=31;
	      linf=6;
	 }
	 else
	 if(cxa==2)
	 {
	      focu=menu_hlp;
	      coli=20;
	      lini=2;
	      colf=32;
	      linf=5;
	 }

}

void main()
{
  char fim=0;
  inicia();
  while(!fim)
  {
   if(kbhit())
      ch=getch();

   if(ch=='A' || ch=='a')
    if(ver==0)
     {
      cxa=0;
      ver = 1;
      focu=menu_arq;
      coli=2;
      lini=2;
      colf=17;
      linf=7;
      caixa(coli,lini,colf,linf,menu_arq, ct);
     }
   if(ch=='E' || ch=='e')
    if(ver==0)
     {
      cxa=1;
      ver = 1;
      focu=menu_edt;
      coli=12;
      lini=2;
      colf=31;
      linf=6;
      caixa(coli,lini,colf,linf,menu_edt, ct);
     }
   if(ch=='H' || ch=='h')
    if(ver==0)
     {
      cxa=2;
      ver = 1;
      focu=menu_hlp;
      coli=20;
      lini=2;
      colf=32;
      linf=5;
      caixa(coli,lini,colf,linf,menu_hlp, ct);
     }
   if(ver==1 && ch==72)
   {
	 ct--;
	 if(ct<0)
	    ct = fin;
	 caixa(coli,lini,colf,linf,focu, ct);
	 ch = 0;
   }

   if(ver==1 && ch==80)
   {
	 ct++;
	 if(ct>fin)
	    ct = 0;
	 caixa(coli,lini,colf,linf,focu, ct);
	 ch = 0;
   }
   if(ver==1 && ch==27)
   {
      menu();
      ver=0;
      ct=0;
   }

   if(ver==1 && ch==75)
   {
	 cxa--;
	 if(cxa<0)
	    cxa=2;
	 menu();
	 alterna();
	 caixa(coli,lini,colf,linf,focu, ct);
	 ch = 0;
   }

   if(ver==1 && ch==77)
   {
	 cxa++;
	 if(cxa>2)
	    cxa=0;
	 menu();
	 alterna();
	 caixa(coli,lini,colf,linf,focu, ct);
	 ch = 0;
   }

   if(ver==1 && ch==13 && ct==3 && cxa==0)
      return;
   if(ver==1 && ch==13 && ct==1 && cxa==2)
    {
      caixa(30,8,53,16,info,25);
      ch=0;
    }
  }
}
