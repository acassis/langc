main()
{
 int x=0,y=0;
 char opc;
 clrscr();
 puts("entre com um operando um operador e outro operando");
 scanf("%d",&x);
 opc=getche();
 scanf("\n%d",&y);
 clrscr();
 if (opc=='+')
    printf("%d+%d=%d",x,y,x+y);
 if (opc=='-')
     printf("%d-%d=%d",x,y,x-y);
 if (opc=='*')
     printf("%d*%d=%d",x,y,x*y);
 if (opc=='/')
     printf("%d/%d=%d",y,x,x/y);
}
