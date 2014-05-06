main()
{
 char ch;
 int i;
 clrscr();
 puts("entre com um caracter maiusculo:");
 ch=getche();
 for(i=ch;i<='Z';i++)
     printf("\n%c",i);
}