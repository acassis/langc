void imp_dados(struct inf_car);

struct inf_car
{
  char nome[30],cor[6],fabricante[10],modelo[4];
  int preco,ano;
};


f_carro(void)
{
  struct inf_car carro[2];
  char op='t',nom[30], co[6] , fa[10], mo[4];
  int i,pre,an;
  for(i=0;i<2;i++)
     {
      clrscr();
      flushall();
      gotoxy(15,12);
      printf("entre com o nome do carro :");
      gets(carro[i].nome);
      gotoxy(15,13);
      printf("entre com a cor do carro :");
      gets(carro[i].cor);
      gotoxy(15,14);
      printf("entre com o nome do fabricante :");
      gets(carro[i].fabricante);
      gotoxy(15,15);
      printf("entre com o modelo do carro :");
      gets(carro[i].modelo);
      gotoxy(15,16);
      printf("entre com o preco do carro :");
      scanf("%d", &carro[i].preco);
      gotoxy(15,17);
      printf("entre com o ano do carro :");
      scanf("%d", &carro[i].ano);
      }
      while(op!='S')
      {
      clrscr();
      flushall();
      gotoxy(15,12);
      puts("escolha a opcao atraves de uma letra");
      gotoxy(15,13);
      puts(" N - pequisa nome       ");
      gotoxy(15,14);
      puts(" C - pequisa cor        ");
      gotoxy(15,15);
      puts(" M - pequisa modelo     ");
      gotoxy(15,16);
      puts(" A - pequisa ano        ");
      gotoxy(15,17);
      puts(" P - pequisa preco      ");
      gotoxy(15,18);
      puts(" F - pequisa fabricante ");
      gotoxy(15,19);
      puts(" S - para finalizar o programa");
      gotoxy(15,20);
      op=toupper(getche());
      flushall();
      switch(op)
      {

	case 'N':
		 gotoxy(15,21);
		 printf("digite o nome do carro");
		 gets(nom);
		 for(i=0;i<2;i++)
		     if(strcmp(nom,carro[i].nome)==0)
			imp_dados(carro[i]);
		 break;

	case 'P':
		 gotoxy(15,21);
		 printf("digite o preco do carro");
		 scanf("%d", &pre);
		 for(i=0;i<2;i++)
		     if(pre==carro[i].preco)
			imp_dados(carro[i]);
		 break;
	case 'F':
		 gotoxy(15,21);
		 printf("digite o nome do fabricante do carro");
		 gets(fa);
		 for(i=0;i<2;i++)
		     if(strcmp(fa,carro[i].fabricante)==0)
			imp_dados(carro[i]);
		 break;

	case 'C':
		 gotoxy(15,21);
		 printf("digite a cor do carro");
		 gets(co);
		 for(i=0;i<2;i++)
		     if(strcmp(co,carro[i].cor)==0)
			imp_dados(carro[i]);
		 break;
	case 'M':
		 gotoxy(15,21);
		 printf("digite o modelo do carro");
		 gets(mo);
		 for(i=0;i<2;i++)
		     if(strcmp(mo,carro[i].modelo)==0)
			imp_dados(carro[i]);
		 break;
	case 'A':
		 {  int an;
		 }
		 gotoxy(15,21);
		 printf("digite o ano do carro");
		 scanf("%d", &an);
		 for(i=0;i<2;i++)
		     if(an==carro[i].ano)
			imp_dados(carro[i]);
		 break;

	dafault:
		printf("%c",  7);
		gotoxy(15,21);
		printf("opcao invalida");
		getch();
	}
     }
}




void imp_dados(struct inf_car a)
{
  clrscr();
  gotoxy(12,12);
  printf("%s",a.nome);
  gotoxy(12,13);
  printf("%s",a.cor);
  gotoxy(12,14);
  printf("%s",a.modelo);
  gotoxy(12,15);
  printf("%s",a.fabricante);
  gotoxy(12,16);
  printf("%d",a.preco);
  gotoxy(12,17);
  printf("%d",a.ano);
  getch();

}















