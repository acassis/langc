main()
{
 int inicio=0,fim=0,i=0;
 puts("entre com o inicio:");
 scanf("%d",&inicio);
 puts("entre com o fim:");
 scanf("%d",&fim);
 if (inicio <fim)
 for (i=inicio;i<=fim;i++)
     printf("%d\n",i);
 else
 for (i=inicio;i>=fim;i--)
     printf("%d\n",i);
}
