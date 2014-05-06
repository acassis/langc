void main()
{
   int num,i=2;
   clrscr();
   printf("Informe um numero: ");
   scanf("%d",&num);
   while(i<=num)
   {
     if((num%i)==0)
     {
	 printf("\n                                 %5.0d³%d",num,i);
	 num=num/i;
     }
     else
       i++;
   }
   printf("\n                                     1³");
   getch();
}