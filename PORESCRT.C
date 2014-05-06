char valesc[40];
void unidade(int i)
{
   if(i==0)
     strcat(valesc,"zero");
   if(i==1)
     strcat(valesc,"um");
   if(i==2)
     strcat(valesc,"dois");
   if(i==3)
     strcat(valesc,"tres");
   if(i==4)
     strcat(valesc,"quatro");
   if(i==5)
     strcat(valesc,"cinco");
   if(i==6)
     strcat(valesc,"seis");
   if(i==7)
     strcat(valesc,"sete");
   if(i==8)
     strcat(valesc,"oito");
   if(i==9)
     strcat(valesc,"nove");
}
void dezena1(int i)
{
   if(i==1)
     strcat(valesc,"vinte");
   if(i==2)
     strcat(valesc,"trinta");
   if(i==3)
     strcat(valesc,"quarenta");
   if(i==4)
     strcat(valesc,"cinquenta");
   if(i==5)
     strcat(valesc,"sessenta");
   if(i==6)
     strcat(valesc,"setenta");
   if(i==7)
     strcat(valesc,"oitenta");
   if(i==8)
     strcat(valesc,"noventa");
}
void dezena2(int i)
{
   if(i==10)
     strcat(valesc,"dez");
   if(i==11)
     strcat(valesc,"onze");
   if(i==12)
     strcat(valesc,"doze");
   if(i==13)
     strcat(valesc,"treze");
   if(i==14)
     strcat(valesc,"quatorze");
   if(i==15)
     strcat(valesc,"quinze");
   if(i==16)
     strcat(valesc,"dezesseis");
   if(i==17)
     strcat(valesc,"dezessete");
   if(i==18)
     strcat(valesc,"dezoito");
   if(i==19)
     strcat(valesc,"dezenove");
}
void centena(int i)
{
   if(i==1)
     strcat(valesc,"cento");
   if(i==2)
     strcat(valesc,"duzentos");
   if(i==3)
     strcat(valesc,"trezentos");
   if(i==4)
     strcat(valesc,"quatrocentos");
   if(i==5)
     strcat(valesc,"quinhentos");
   if(i==6)
     strcat(valesc,"seiscentos");
   if(i==7)
     strcat(valesc,"setecentos");
   if(i==8)
     strcat(valesc,"oitocentos");
   if(i==9)
     strcat(valesc,"novecentos");
}
void main()
{
    int i,j=0,cont=1;
    clrscr();
    printf("Informe um numero (-9999 ~ 9999): ");
    scanf("%d",&i);
    if(i<0)
    {
       strcat(valesc,"menos ");
       i=i*(-1);
    }
    if(i>=1000 && i<10000)
    {
     cont=2;
     while(i>=1000)
     {
	 i-=1000;
	 j++;
     }
     if(j>1)
       unidade(j);
     strcat(valesc," mil ");
    }
    j=0;
    if(i>=100 && i<1000)
    {
     cont=3;
     while(i>=100)
     {
	 i-=100;
	 j++;
     }
       if(j!=1)
       {
	centena(j);
	if(i!=0)
	   strcat(valesc," e ");
       }
       else
	 if(i==0)
	   strcat(valesc,"cem");
	 else
	 {
	   centena(j);
	   strcat(valesc," e ");
	 }
    }
    j=0;
    if(cont==2 && (i%10!=0))
	   strcat(valesc,"e ");
    if(i>=20 && i<100)
    {
     while(i>=20)
     {
	 i-=10;
	 j++;
     }
     dezena1(j);
     if(i!=10)
     {
	  i-=10;
	  strcat(valesc," e ");
     }
    }
    if(j==0)
       dezena2(i);
    if(i>0 && i<10)
       unidade(i);
    if(cont==1 && i==0)
       unidade(i);
    printf("Voce digitou o numero: %s",valesc);
    getch();
}