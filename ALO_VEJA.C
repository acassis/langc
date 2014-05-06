#include <process.h>
#include<dos.h>
union REGS regs;
void apresenta ()
{
clrscr();
puts ("*********************************************************");
puts ("*             J O G O     A L O - V E J A               *");
puts ("************* ( A P R E S E N T A C A O ) ***************");
puts ("* - JOGO ENTRE O MICRO E VOCE. O MICRO IRA' ESCOLHER UM *");
puts ("*   NUMERO E VOCE OUTRO NUM INTERVALO ENTRE 1 E 1023.   *");
puts ("* - CADA UM IRA' TENTAR DESCOBRIR O NUMERO DO OPONENTE, *");
puts ("*   ATE' QUE UM DOS JOGADORES ADIVINHE O NUMERO DO OUTRO*");
puts ("* - O MICRO IRA' INFORMAR SE O SEU PALPITE FOI CORRETO, *");
puts ("*   BAIXO OU ALTO.                                      *");
puts ("* - VOCE DEVERA' FAZER O MESMO, INFORMANDO:             *");
puts ("*   (1) PARA UM CHUTE BAIXO;                            *");
puts ("*   (2) PARA UM CHUTE ALTO;                             *");
puts ("*   (3) PARA CERTO.                                     *");
puts ("*********************************************************");
}

void main()
{
   int me=0,ma=1023,numm,numh,rh,paph,papm,i,contador,resp=0;
   char nome[35],hora[10];
   apresenta();
   printf("Informe seu nome:");
   gets(nome);
inicio:
   regs.h.ah=0;
   int86(26,&regs,&regs);
   contador = regs.x.cx - regs.x.dx;
   for(i=0;i<contador;i++)
   {
     numm = rand()/32;
     numh = rand()/32;
   }
   if(numm<1 || numm>1023)
      goto inicio;
teste:
   if(numh>1023)
      numh-=numm;
   if(numh<1)
      numh+=numm;
   if(numh<1 || numh>1023)
      goto teste;
   while(1)
   {
     clrscr();
     apresenta();
     gotoxy(0,11);
     printf("Tente adivinhar o numero que eu escolhi:");
     scanf("%d",&paph);
     printf("O resultado sera divulgado apos a jogada do micro\n");
     if(resp==0)
	papm=numh;
     else
       papm=(me+ma+1)/2;
     printf ("%s, acho que voce pensou no numero %d\n",nome,papm);
     printf ("Digite (1) baixo, (2) alto ou (3) certo : ");
     scanf  ("%d",&rh);
     if(numm>paph)
	printf("Seu palpite foi baixo!\n");
     else if(numm<paph)
	    printf("Seu palpite foi alto!\n");
	  else
	    printf("Seu palpite esta correto! Parabens!\n");
      if(rh==1)
	me = papm;
      if(rh==2)
	ma = papm;
      if(rh==3)
	{
	printf("Meu palpite esta correto!");
	if(numm!=paph)
	   printf("\nVocˆ perdeu! Eu escolhi o n§ %d",numm);
	}
     if(rh==3 || numm==paph)
	goto fim;
     else
	getch();
     resp=1;
  }
 fim:
     printf("\nPressione qualquer tecla para sair!");
     getch();
     return;
}