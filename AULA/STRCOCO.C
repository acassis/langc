#include <conio.h>
#include <stdio.h>
// converte string em maisculo
void strmai1(char *s)
{
  int i,b=strlen(s);
  for(i=0;i<b;i++)
     s[i]=toupper(s[i]);
}
//***************************************************************************
// converte string em maisculo
void strmai(char *s)
{
  for(;*s!='\0';)
     if(*s>='a'&& *s<='z')
	*s++=*s-32;


}
//***************************************************************************

// conta quantos caracteres tem uma string
int strconte(char *s)
{
  int i=0;
  while(*s++!='\0')
     i++;
  return i;
}
//***************************************************************************
void main(void)
{
 char ch[30];
 puts("entre com string");
 gets(ch);
 strmai(ch);
 printf("%s  strlen=%d    strconte=%d",ch,strlen(ch),strconte(ch));
}


