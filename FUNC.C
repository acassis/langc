void main(void)
{
  float col,lin,coli=320,lini=240,r=70,ch;

while((ch=getch())!=27){
clrscr();
puts("informe o valor da coluna");
scanf("%f",& col);
if(col>coli)
 printf("O resultado em func∆o da coluna Ç : col+(%3.3f * r)",(col-coli)/r);
else
 if(col<coli)
  printf("O resultado em func∆o da coluna Ç : col-(%3.3f * r)",(coli-col)/r);
 else
  printf("O resultado em func∆o da coluna Ç : col");
puts("\ninforme o valor da linha");
scanf("%f",& lin);
if(lin>lini)
 printf("O resultado em func∆o da linha Ç : lin+(%3.3f * r)",(lin-lini)/r);
else
 if(lin<lini)
  printf("O resultado em func∆o da linha Ç : lin-(%3.3f * r)",(lini-lin)/r);
 else
  printf("O resultado em func∆o da linha Ç : lin");}
 }
