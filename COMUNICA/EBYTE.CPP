//---------------------------------------------------------------------------
#include <string.h>
#include <vcl\vcl.h>
#pragma hdrstop
#include "ebyte.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
#define com0       0x2f8
#define veloc      115200L
#define paridade   0
#define stop       1
#define bits_dados 8
#define true       1
//---------------------------------------------------------------------------
unsigned int inportb(int porta);
void inicializa(unsigned int porta,long bps,int p,int stp,int bits_dado);
void outportb(int porta,int dado);
char caixa[]="";
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  unsigned char ch;
  int status=inportb(com0+5);
  if(status & 1)
  {
   ch=inportb(com0);
   if(ch==8)
     {
     int tam;
     char *p;
     tam = remoto->GetTextLen();
     p = remoto->Text.c_str();
     *(p + (tam-1))='\0';
     remoto->Text = p;
     }
   else
    if(ch==13)
      remoto->Lines->Add("");
    else
     {
       remoto->Text = remoto->Text + (char)ch;
     }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 inicializa(com0,veloc,paridade,stop,bits_dados);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
  unsigned char ch;
  int status=inportb(com0+5);
  outportb(com0,Key);
}
//---------------------------------------------------------------------------
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

unsigned int inportb(int porta)
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
