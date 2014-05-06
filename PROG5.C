main()
{
 int valor,i,fat=1;
 clrscr();
 puts("este programa calcula o fatorial de um numero qualquer");
 puts("informe o numero");
 scanf("%d",&valor);
 for(i=valor;i>=1;i--)
	  fat=(fat*i);
	  printf("o fatorial de %d =%d\n",valor ,fat);
 puts ("fim");
 }
