//---------------------------------------------------------------------------
#define com0       0x2f8     //Porta serial usada (COM2)
#define veloc      115200L   //Velocidade da comunicacao 
#define paridade   0         //Havera checagem de paridade (0 | 1)
#define stop       1         //Stop byte
#define bits_dados 8         //Quantos bits serao usados na comunicacao 
#define true       1
#include <vcl\vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "Serial1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;

void outportb(int porta,int dado); //Funcao p/ enviar aa porta
unsigned char inportb(int porta);  //Funcao p/ ler a porta
                                   //Agradecimentos ao Wenderson Teixeira
                                   //por disponibiliza-la p/ CBuilder
void inicializa(unsigned int porta,long bps,int p,int stp,int bits_dado);
                                   //Funcao p/ inicializar a porta serial
void recebe_arq();                 //Esta funcao recebe o arquivo
void envia_arq();                  //Esta funcao envia um arquivo
HANDLE testehw;
DWORD testeid;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
     testehw = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)envia_arq, NULL, 0, &testeid);
                                   //Thread da funcao envia_arq() 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     testehw = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)recebe_arq, NULL, 0, &testeid);
                                   //Thread da funcao recebe_arq()
}
//---------------------------------------------------------------------------
void recebe_arq()
{
  char *nomearq;
  int status;
  FILE *f;
  unsigned char ch=0;
  union
  {
    unsigned long arq;
    unsigned char byte[4];
  } tamanho;
  unsigned long i=0;
  nomearq = Form1->Edit2->Text.c_str();
  if ((f=fopen(nomearq,"wb"))==NULL)
  {
   ShowMessage("Acesso negado!");
   return;
  }
  inicializa(com0,veloc,paridade,stop,bits_dados);
  while (i<=5)
  {
    status=inportb(com0+5);
    if((status & 1))
    {
      tamanho.byte[i++] = inportb(com0);
      outportb(com0,'*');
      if (i==4)
       {
	      ShowMessage("Iniciando copia do arquivo :!");
	      break;
       }
    }
  }
  i=0L;
  while(i<tamanho.arq)
  {
    status=inportb(com0+5);
    if ((status & 1))
    {
      ch = inportb(com0);
      putc(ch,f);
      outportb(com0,'*');
      i++;
      Form1->ProgressBar1->Position = ((i*100)/(tamanho.arq));
      Form1->Label4->Caption = IntToStr((i*100)/(tamanho.arq)) + "%";
     }
   }
   fclose(f);
   ShowMessage("Copia do arquivo concluida com sucesso...");
   Form1->ProgressBar1->Position = 0;
   Form1->Label4->Caption = "";
}
//-----------------------------------------------------------------------------
void envia_arq()
{
  char *nomearq;
  FILE *f;
  unsigned int ch;
  int status,i=0;
  union
  {
     unsigned long arq;
     unsigned char byte[4];
  }
  tamanho;
  nomearq = Form1->Edit1->Text.c_str();
  if((f=fopen(nomearq,"rb"))==NULL)
  {
    ShowMessage("Acesso negado !");
    return;
  }
  fseek (f,0L,2);
  tamanho.arq=ftell(f);
  fseek (f,0L,0);
  inicializa(com0,veloc,paridade,stop,bits_dados);
  for(i=0;i<4;i++)
  {
    outportb(com0,tamanho.byte[i]);
    status=inportb(com0+5);
    while(!(status & 1))
          status=inportb(com0+5);
    ch=inportb(com0);
    if (ch!='*')
    {
      ShowMessage("ERRO NA COMUNICAÇÃO!");
      return;
    }
  }
  while ((ch=getc(f))!=(unsigned int) EOF)
  {
    outportb(com0,ch);
    status=inportb(com0+5);
    while(!(status & 1))
      status=inportb(com0+5);
    ch=inportb(com0);
    if(ch!='*')
     {
         ShowMessage("ERRO NA COMUNICAÇÃO3");
         return;
     }
  }
  fclose(f);
  return;
}
//-------------------------------------------------------------------------------
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
  byte_de_param = (unsigned char)(bits_dado-5);
  byte_de_param |= (unsigned char)((stp-1)<<2);
  if (p)
  {
    byte_de_param |= 0x08;
    byte_de_param |= (unsigned char)(p&0x10);
   }
   outportb(porta+3,byte_de_param);
}
//----------------------------------------------------------------------------

unsigned char inportb(int porta)
{
  _DX = porta;
  __emit__(0xEC);
  return (_AL);
}
//----------------------------------------------------------------------------
void outportb(int porta,int dado)
{
    _DX = porta;
    _AX = dado;
    __emit__(0xEE);
}
//----------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
           Edit1->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
