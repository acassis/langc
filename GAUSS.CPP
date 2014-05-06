#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX 10
#define ERRO 0

int GaussSimples(float [MAX][MAX],float [MAX],int );
int GaussPivotamentoParcial(float [MAX][MAX],float [MAX],int );
int LeMatriz(float matriz[MAX][MAX]);
int GaussSeidel(float [MAX][MAX],float [MAX],int,float);
void ZeraMatriz(float matriz[MAX][MAX]);
void ZeraVetor(float vetor[MAX]);
float MaiorElemento(float vetor[MAX]);
void CopiaMatriz(float [MAX][MAX],float [MAX][MAX]);


void main()
 {
   float matriz[MAX][MAX],tempmatriz[MAX][MAX],resultado[MAX],precisao;
   int num_incognitas=4,i,retorno;
   char op; //Opcao de menu
   ZeraMatriz(matriz);
   ZeraMatriz(tempmatriz);
  do{
   clrscr();
   printf("\n\t\tMedodos de Gauss");
   printf("\n\n\t(1)Entrar com um novo sistema");
   printf("\n\n\t(2)Metodo Simples de Gauss");
   printf("\n\n\t(3)Metodo de Gauss com Pivotamento Parcial");
   printf("\n\n\t(4)Metodo de Gauss-Seidel");
   printf("\n\n\t(5)Sair");
   printf("\n\n\tEscolha uma opcao:");
   op=getche();
   retorno=0;
   switch(op){
       case '1' : num_incognitas=LeMatriz(matriz);
		  CopiaMatriz(tempmatriz,matriz); // faz um backup da matriz para que sejam restauradas
		  break;                          //as modificacoes feitas nos processos numericos
       case '2' : retorno=GaussSimples(matriz,resultado,num_incognitas);
		  break;
       case '3' : retorno=GaussPivotamentoParcial(matriz,resultado,num_incognitas);
		  break;
       case '4' : printf("\n\n\tDigite a precisao:");
		  scanf("%f",&precisao);
		  retorno=GaussSeidel(matriz,resultado,num_incognitas,precisao);
     }
    if(retorno){     //Se nao hover erro sera impresso o resultado
     printf("\n\n");
     for(i=0;i<num_incognitas;i++){
      printf("\n\tx[%d]:%8.4f",i+1,resultado[i]);
     }
     getch();
    }
   CopiaMatriz(matriz,tempmatriz);   //restaura matriz inicial
  }while(op!='5');

 }

//Funcao para leitura de Matrizes
//Parametros: uma matriz
//Retorno: numero de incognitas(coeficientes de um sistema
int LeMatriz(float matriz[MAX][MAX])
 {
  int num_incognitas,i,j,k;
  float  a;
  clrscr();
  printf("\n\n\tDados:");
  printf("\n\tNumero de incognitas:");
  scanf("%d",&num_incognitas);
  for(i=0;i<num_incognitas;i++)
   {
    printf("\n");
    for(j=0;j<num_incognitas;j++){
      printf("\tDigite o coeficiente [%d][%d]:",i+1,j+1);
      scanf("%f",&matriz[i][j]);
     }
    printf("\tDigite o termo independente:");
    scanf("%f",&matriz[i][j]);
   }
    return num_incognitas;
 }
 //Resolve o sistema pelo metodo de Gauss sem pivotamento
 //Parametros:sistema, vetor para resultados e numero de incognitas
 //Retorno: 1 em caso de sucesso e 0 em caso de Erro
 int GaussSimples(float matriz[MAX][MAX],float resultado[MAX],int num_incognitas)
   {
     int i,j,k;
     float a,aux;
     clrscr();
     for(i=0;i<num_incognitas;i++){ //Faz a troca se houver um elemento 0 no inicio da linha principal
	k=i+1;
	while(matriz[i][i]==0){
	   if(matriz[k][i]==0){
	      printf("\nSistema indeterminado!!!!!"); //em caso ca coluna estar zerada retorna erro
	      getch();
	      return ERRO;
	     }
	   for(j=0;j<=num_incognitas;j++){ //Efetua a troca da linha que comeca por 0 com outra
	      aux=matriz[i][j];
	      matriz[i][j]=matriz[k][j];
	      matriz[k][j]=aux;
	    }
	  k++;
	 }
	  //efetua o metodo de Gauss propriamente dito
	  for(j=i+1;j<num_incognitas;j++){
	    a=-matriz[j][i]/matriz[i][i];
	    for(k=i;k<=num_incognitas;k++){
	      matriz[j][k]=a*matriz[i][k]+matriz[j][k];
	     }
	     aux=0;
	    for(k=0;k<=num_incognitas;k++){ //Testa se a linha nao foi zerada
	      if(matriz[j][k]!=0)
		aux=1;
	      }
	    if(!aux){ //se a linha for zerada retorna erro
	     printf("\nSistema indeterminado!!!!!");
	     getch();
	     return ERRO;
	     }

	   }
       }

      printf("\n\tMatriz triangularizada:\n\n");
      for(i=0;i<num_incognitas;i++){
       for(j=0;j<=num_incognitas;j++){
	  printf(" %8.3f",matriz[i][j]);
	}
	printf("\n");
       }

      for(i=num_incognitas-1;i>=0;i--) //Efetua o calculo final das solucoes na matriz triangularizada
       {
	  resultado[i]=matriz[i][num_incognitas];
	  for(j=i+1;j<num_incognitas;j++){
	    resultado[i]=resultado[i]-matriz[i][j]*resultado[j];
	   }
	   resultado[i]=resultado[i]/matriz[i][i];
       }
   return 1;
   }

//Resolve o sistema pelo metodo de Gauss com Pivotamento parcial
//Parametros:sistema, vetor para resultados e numero de incognitas
//Retorno: 1 em caso de sucesso e 0 em caso de Erro
int GaussPivotamentoParcial(float matriz[MAX][MAX],float resultado[MAX],int num_incognitas)
   {
     int i,j,k,l,m;
     float a,aux;
     clrscr();
     for(i=0;i<num_incognitas;i++){
	// Metodo bolha para fazer o pivotamento
	for(l=i;l<num_incognitas;l++){
	  for(m=i;m<num_incognitas-1;m++){
	    if(matriz[m][i]<matriz[m+1][i]){
	      for(k=0;k<=num_incognitas;k++){
		aux=matriz[m][k];
		matriz[m][k]=matriz[m+1][k];
		matriz[m+1][k]=aux;
	       }
	    }
	  }
	}

	if(matriz[i][i]==0){  // Em caso da primeira coluna ser zero retorna erro
	  printf("Sistema Indeterminado!!!");
	  getch();
	  return ERRO;
	 }

	  for(j=i+1;j<num_incognitas;j++){

	    a=-matriz[j][i]/matriz[i][i];
	    for(k=i;k<=num_incognitas;k++){
	      matriz[j][k]=a*matriz[i][k]+matriz[j][k];
	     }
	     aux=0;
	    for(k=0;k<=num_incognitas;k++){
	      if(matriz[j][k]!=0)
		aux=1;
	      }
	    if(!aux){
	     printf("\nSistema indeterminado!!!!!");
	     getch();
	     return ERRO;
	     }

	   }
       }

      printf("\n\tMatriz triangularizada:\n\n");
      for(i=0;i<num_incognitas;i++){
       for(j=0;j<=num_incognitas;j++){
	  printf(" %8.3f",matriz[i][j]);
	}
	printf("\n");
       }

      for(i=num_incognitas-1;i>=0;i--)
       {
	  resultado[i]=matriz[i][num_incognitas];
	  for(j=i+1;j<num_incognitas;j++){
	    resultado[i]=resultado[i]-matriz[i][j]*resultado[j];
	   }
	   resultado[i]=resultado[i]/matriz[i][i];
       }
   return 1;
   }

void ZeraMatriz(float matriz[MAX][MAX])
 {
   int i,j;
    for(i=0;i<MAX;i++)
     for(j=0;j<MAX;j++)
       matriz[i][j]=0;
 }

void CopiaMatriz(float matriz1[MAX][MAX],float matriz2[MAX][MAX])
 {
   int i,j;
    for(i=0;i<MAX;i++)
     for(j=0;j<MAX;j++)
       matriz1[i][j]=matriz2[i][j];
 }


 //Resolve o sistema pelo metodo iterativo de Gauss-Siedel
 //Parametros:sistema, vetor para resultados e numero de incognitas
 //Retorno: 1 em caso de sucesso e 0 em caso de Erro
 int GaussSeidel(float matriz[MAX][MAX],float resultado[MAX],int num_incognitas,float precisao)
   {
     int i,j,k;
     float a,aux[MAX],VetorPrecisao[MAX],coefdivisor,oldprec;
     clrscr();
     for(i=0;i<num_incognitas;i++){
      coefdivisor=matriz[i][i];  //retira o coef. divisor do elemento a ser isolado
      for(j=0;j<=num_incognitas;j++){
	if(i==j){
	  matriz[i][j]=0;  //Coloca 0 no local do da variavel isolada
	 }
	 else{
	  matriz[i][j]=-matriz[i][j]/coefdivisor;//Faz o recalculo dos membros isolados
	  if(j==num_incognitas)
	     matriz[i][j]=matriz[i][j]*(-1);  //Retorna o sinal original para os membros isolados do sistema
	 }
       }
     }
     for(i=0;i<num_incognitas;i++){
      resultado[i]=matriz[i][num_incognitas]; //inicializa o vetor de solucoes com os membros isolados
      }
    k=0;
    oldprec=100000000; //inicializa uma variavel auxiliar de precisao; para manter a memoria da precisao anterior
    ZeraVetor(VetorPrecisao);
    do{
      for(i=0;i<num_incognitas;i++)
       aux[i]=resultado[i];    //inicializa uma matriz auxiliar com as solucoes
      for(i=0;i<num_incognitas;i++){
       resultado[i]=0; //zera o correspondente valor das solucoes
       for(j=0;j<num_incognitas;j++){
	resultado[i]=resultado[i]+matriz[i][j]*aux[j];
	}
	resultado[i]=resultado[i]+matriz[i][j];
	VetorPrecisao[i]=fabs(aux[i]-resultado[i]);
	aux[i]=resultado[i];
	printf("   %10.5f",resultado[i]); //imprime os resultados das iteracoes
       }
       printf("\n");
       if(VetorPrecisao[0]>oldprec){
	 printf("\n\n\tSistema Divergente para o metodo");//Testa convergencia
	 getch();
	 return 0;
	}
       oldprec=VetorPrecisao[0];
     k++;
    }while(MaiorElemento(VetorPrecisao)> precisao);
    return 1;
   }

 void ZeraVetor(float vetor[MAX]){
   int i;
   for(i=0;i<MAX;i++)
     vetor[i]=0;
  }

 float MaiorElemento(float vetor[MAX]){
     int i;
     float maior=vetor[0];
     for(i=1;i<MAX;i++)
      {
       if(vetor[i]>maior)
	 maior=vetor[i];
      }
      return maior;
     }