int fat(int n)
{
printf("%d",n);
getch();
if (n == 1)
	return 1;
else
	return fat(n-1) * n;
}
void main()
{
int j;
printf("Digite um numero: ");
scanf("%d",&j);
printf("O fatorial de %d e' %d",j,fat(j));
getch();
}

