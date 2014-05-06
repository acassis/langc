// converte string em maisculo
void strmai(char *s)
{
  int i,b=strlen(s);
  for(i=0;i<b;i++)
     s[i]=toupper(s[i]);
printf("%s",s);
}
//***************************************************************************
// conta quantos caracteres tem uma string
int strconte(char *s)
{
  int i=0;
  while(*s!='\0')
     i++;
  return i;
}
//***************************************************************************










