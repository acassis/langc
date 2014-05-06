main()
{
 char c[20];
 int i=0;
 clrscr();
 puts("entre 20 caracteres:");
 gets(c);
 for (i=0;c[i]!='\0';i++)
     if (c[i]>='A'&& c[i]<='Z')
	printf("%c",c[i]);
}