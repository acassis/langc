#include<stdio.h>
void main(void)
{
FILE *a,*p,*s;
int ch;
puts("\niniciando copia de arquivos\n aguarde algums segundos...");
if((a=fopen("d:\\p1.exe","rb"))==NULL)
{
  puts("\nERRO !!!  p1");
  return;
}
if((p=fopen("d:\\p2.exe","rb"))==NULL)
{
  puts("\nERRO !!!   p2");
  return;
}
if((s=fopen("d:\\exe.exe","wb"))==NULL)
{
  puts("\nERRO  !!!    exe");
  return;
}
while((ch=fgetc(a))!=EOF)
  fputc(ch,s);
while((ch=fgetc(p))!=EOF)
  fputc(ch,s);
fcloseall();
puts("\ncopia realizada com sucesso");
}