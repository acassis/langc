#define com0       0x2f8
#define veloc      115200L
#define paridade   0
#define stop       1
#define bits_dados 8
#define true       1
void inicializa(unsigned int porta,long bps,int p,int stp,int bits_dado);
void recebe_arq(char *);
void envia_arq(char *);

#include <stdio.h>

void main(int argc,char **argv)
{
  if (argc<3)
  {
    clrscr();
    printf("\nModo de Recebimento:SERIAL  R <nomearq.ext>\n");
    printf("Modo de Enviamento :SERIAL  E <nomearq.ext>");
    exit();
  }
  if (argv[1] [0]=='r'|| argv[1] [0]=='R')
     recebe_arq(argv[2]);
  else if (argv[1] [0]=='e'|| argv[1] [0]=='E')
	  envia_arq(argv[2]);
  else
  {
    printf("\n Parƒmetro invalido.");
    printf("\n Digite R para receber arquivo");
    printf("\n Digite E para enviar arquivo");
    exit();
  }
}
void recebe_arq(char *nomearq)
{
  int status;
  FILE *f;
  unsigned char ch=0;
  union
  {
    unsigned long arq;
    unsigned char byte[4];
  } tamanho;
  unsigned long i=0;
  if ((f=fopen(nomearq,"wb"))==NULL)
  {
   printf("\n Acesso negado  %s",nomearq);
   exit();
  }
  inicializa(com0,veloc,paridade,stop,bits_dados);
  while (i<=5)
  {
    status=inport(com0+5);
    //printf("%s",status=inport(com0+5));
    if((status & 1))
    {
      tamanho.byte[i++]= inportb(com0);
      outportb(com0,'*');
      if (i==4){
	  printf("\n Iniciando copia do arquivo : %s...",nomearq);
	  break;}
    }
  }
  i=0L;
  while(i<tamanho.arq)
  {
    status=inport(com0+5);
    if ((status & 1))
    {
      ch=inportb(com0);
      putc(ch,f);
      outportb(com0,'*');
      i++;
     }
   }
   fclose(f);
   printf("\ncopia do arquivo %s concluida com sucesso...",nomearq);
}
void envia_arq(char *nomearq)
{
  FILE *f;
  unsigned int ch;
  int status,i=0;
  union
  {
     unsigned long arq;
     unsigned char byte[4];
  }
  tamanho;
  if((f=fopen(nomearq,"rb"))==NULL)
  {
    printf("\n Acesso negado %s",nomearq);
    exit();
  }
  fseek (f,0L,2);
  tamanho.arq=ftell(f);
  fseek (f,0L,0);
  inicializa(com0,veloc,paridade,stop,bits_dados);
  for(i=0;i<4;i++)
  {
    outportb(com0,tamanho.byte[i]);
    status=inport(com0+5);
    while(!(status & 1))
    status=inport(com0+5);
    ch=inportb(com0);
    if (ch!='*')
    {
      printf("\n ERRO NA COMUNICA€AO");
      exit();
    }
  }
  while ((ch=getc(f))!=(unsigned int) EOF)
  {
    outportb(com0,ch);
    status=inport(com0+5);
    while(!(status & 1))
      status=inport(com0+5);
      ch=inportb(com0);
      if(ch!='*')
      {
	printf("\n ERRO NA COMUNICA€AO3");
	exit();
      }
  }
  fclose(f);
  exit();
}
void inicializa(unsigned int porta,long bps,int p,int stp,int bits_dado)
{
  unsigned char byte_de_param;
  union
  {
    unsigned int nr;
    unsigned char hilo[2];
  }valor;
  valor.nr=(unsigned int)(1843200L/(bps*16L));
  outportb (porta+3,0x80);
  outportb(porta,valor.hilo[0]);
  outportb(porta+1,valor.hilo[1]);
  byte_de_param = bits_dado-5;
  byte_de_param |=(stp-1)<<2;
  if (p)
  {
    byte_de_param |= 0x08;
    byte_de_param |= p&0x10;
   }
   outportb(porta+3,byte_de_param);
}

