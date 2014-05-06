void main()
{
 int x,y,opc;
 clrscr();
 puts("entre com dois inteiros");
 scanf("%d",&x);
 scanf("%d",&y);
 puts("informe uma opcao:\n1-adicao\n2-subtracao\n3-multiplicacao");
 scanf("%d",&opc);
 if (opc==1)
    printf("%d+%d=%d",x,y,x+y);
 if (opc==2)
    printf("%d-%d=%d",x,y,x-y);
    if (opc==3)
    printf("%d*%d=%d",x,y,x*y);


 }