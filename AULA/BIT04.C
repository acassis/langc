/* o operador complemento ~, troca os bits 1 do operando por 0 e os bits
0 por 1.
*/
main()
{
  char ch;
  do{
     ch=getch();
     printf("%c",~ch);
    }while(ch!='X');
}