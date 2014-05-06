main()
{
 int inicio, fim,soma=0;
 clrscr();
 puts("este programa calcula o somatorio dos inteirode um intervalo crescente");
 puts("informe o inicio e o fim");
 scanf("%d",&inicio);
 scanf("%d",&fim);
 for(;inicio<=fim;inicio++)
	  soma=(soma+inicio);
	  printf("%d\n",soma);
 puts ("fim");
 }
