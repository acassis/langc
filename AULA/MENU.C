/* menu que retorna inteiro*/
int menu(void)
{
  int op;
  printf("\n1-incluir\n2-alterar\n3-excluir\n4-sair");
  scanf("%d",&op);
  return(op);
}
main()
{
  printf("%d",menu());
  getch();
}