# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <dos.h>
# define xabs(x) ((x>0)?(x):-(x))
# define lim 1000
 int vetor[1000],cont;
 void zerar(void)
 {
  for(cont=0;cont<lim;cont++)
   vetor[cont]=0;
 }//fim de zerar
 void inicializa(void)
 {
  int i=0;
  randomize();
  for(;i<lim;i++)
   vetor[i]=(rand()%1000);
 }//fim de inicializa
 float media(void)
 {
  int i,soma=0;
  for(i=0;i<lim;i++)
   soma+=vetor[i];
  return(soma/lim);
 }
 void imprime(void)
 {
  int i;
  for (i=0;i<lim;i++)
   printf("%4d",vetor[i]);
 }//fim de imprime
 int localiza(int num)
 {
  int i;
  for(i=0;i<lim;i++){
   if (vetor[i]==num)
    return(1);
   }
   return(0);
 }//fim de localiza
 void organiza(void){
  int a,b,temp;
  for(a=0;a<cont;a++){
   for(b=a+1;b<lim;b++){
    temp=(vetor[a]<vetor[b])? vetor[a]:vetor[b];
    if (temp==vetor[b])
     vetor[b]=vetor[a];
    vetor[a]=temp;
   }
  }
 }//fim de organiza
 int localiza2(int num)
 {
  int i=0;
  do{
   if (vetor[i]==num)
    return(1);
   i++;
  }while((i<lim)&&(vetor[i]<=num));
  return(0);
 }//fim de localiza2
 int localiza3(int num)
 {
  int b=cont,c,n=0;
  if (b%2) b++;
  b/=2;
  c=b;
  do{
   if (b>cont) b--;
   if (vetor[b]==num){
    printf("\tValor localizado com %d procuras",n);
    return(1);
   }
   if (c==1)  break;
   if (c%2)   c++;
   c/=2;
   if (vetor[b]<num) b+=c;
   else              b-=c;
   n++;
  }while(1);
  return(0);
 }//fim de localiza3
 int numero(void)
 {
  int valor;
  printf("\nDigite um valor: ");
  scanf("%d",&valor);
  return(valor);
 }//fim de numero
 void main(void)
 {
  int valor,result;
  double med;
  textcolor(15);
  textbackground(12);
  clrscr();
  zerar();
  printf("\nVetor de %d elementos zerado.",lim);
  inicializa();
  printf("\nVetor inicializado com rand.");
  med=media();
  med=xabs(med);
  printf("\nMedia dos valores do vetor: %5.2lf",med);
  printf("\npressione alguma tecla para ver o vetor...");
  getch();  clrscr();
  imprime();
  printf("\n\n\tLocalizando um valor no vetor desorganizado");
  valor=numero();
  result=localiza(valor);
  if (result)  printf("\tValor localizado");
  else         printf("\tValor nÆo localizado.");
  printf("\npressione alguma tecla para ver o vetor organizado...");
  getch();  organiza();
  imprime();
  printf("\n\n\tLocalizando um valor no vetor organizado.");
  valor=numero(); result=localiza2(valor);
  if (result)  printf("\tValor localizado");
  else         printf("\tValor nÆo localizado");
  printf("\n\n\tLocalizando um valor com algoritmo binario.");
  valor=numero();  result=localiza3(valor);
  if (!(result))  printf("\tValor nÆo encontrado");
  printf("\n\nfinalizando programa...");
  delay(3000);
 }//fim de programa