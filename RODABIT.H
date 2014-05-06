/******************************************************************
  22/12/998  
  Autor:     Thiago dos Santos Prado
  E-mail:    thiagoprado@yahoo.com
  Arquivo:   joystick.h
  Descricao: rotinas que rotacionam um bitmap
******************************************************************/

#include <math.h>
#include <dos.h>

#define LARGURA 320
#define ALTURA 200

char far *tela = (char far*) MK_FP(0xa000, 0);

void setapaleta(char far*);
void limpa(char far*, char, unsigned int);
void setamodo(char);
void ponto(int, int, unsigned char);
void mostra_rot_sprite(char *, int, int, int, int, double, int);
void retraco(void);

void setapaleta(char far *cores)
{
   union REGS regs;
   struct SREGS sregs;
   unsigned int coroff = FP_OFF(cores),
		corseg = FP_SEG(cores);

     sregs.es = corseg;
     regs.h.ah = 0x10;
     regs.h.al = 0x12;
     regs.x.bx = 0;
     regs.x.cx = 0x100;
     regs.x.dx = coroff;
     int86x(0x10,&regs,&regs,&sregs);
}

void limpa(char far* memoria, char ch, unsigned int tamanho)
{
    unsigned int a;

    for (a = 0; a <= tamanho; a++)
    {
        memoria[a] = ch;
    }
}

void setamodo(char modo)
{
    union REGS r;
    r.h.ah = 0x00;
    r.h.al = modo;
    int86(0x10, &r, &r);
}

void ponto(int linha, int coluna, unsigned char cor)
{
    tela[linha*LARGURA + coluna] = cor;
}

int arred(float x)
{
    int maior, menor, retorno;
    float dif1, dif2;

    menor = (int) x;
    maior = menor + 1;
    dif1 = ((float) maior) - x;
    dif2 = x - ((float) menor);
    if (dif1 > dif2)
    {
        retorno = menor;
    }
    else
    {
        retorno = maior;
    }
    return (retorno);
}

void mostra_rot_sprite(char *sprite, int x, int y, int largura, int altura, double angulo, int cor_transparente)
{
    int linha, coluna, novo_x, novo_y;
    char *sprite_temp;

    sprite_temp = (char *) malloc (largura*altura*4);
    memset(sprite_temp,0, largura*altura*4);

    for (linha = 0; linha < altura; linha++)
        for (coluna = 0; coluna < largura; coluna++)
            if (sprite[linha * largura + coluna] != cor_transparente)
            {
                novo_x = arred(((coluna - (largura/2)) * cos(angulo) - (linha - (altura/2)) * sin(angulo)) + largura);
                novo_y = arred(((linha - (altura/2)) * cos(angulo) + (coluna - (largura/2)) * sin(angulo)) + altura);
                if ((novo_y >= 0) && (novo_y <= ALTURA) && (novo_x >= 0) && (novo_x <= ALTURA))
                    sprite_temp[novo_y*largura*2+novo_x] = sprite[linha * largura + coluna];
            }

    /*preencher os pontos que devido a matematica na tela, nao foram preenchidos*/
    /*para saber do que se trata, deixe sob a forma de comentario, os laços abaixo*/
    for (linha = 0; linha < altura * 2; linha++)
        for (coluna = 1; coluna < (largura * 2 - 1); coluna++)
            if (!sprite_temp[linha * largura * 2 + coluna])
                if (sprite_temp[linha * largura * 2 + coluna -1] && sprite_temp[linha * largura * 2 + coluna +1] && sprite_temp[(linha - 1) * largura * 2 + coluna] && sprite_temp[(linha + 1) * largura * 2 + coluna])
                   sprite_temp[linha * largura * 2 + coluna] = sprite_temp[linha * largura * 2 + coluna -1];

    /*mostrar na tela, o sprite*/
    for (linha = 0; linha < (altura * 2); linha++)
        for (coluna = 0; coluna < (largura * 2); coluna++)
        if (sprite_temp[linha * largura * 2 + coluna])
        {
            ponto(y + linha, x + coluna, sprite_temp[linha * largura * 2 + coluna]);
        }

    free(sprite_temp);
}

void retraco()
{
   const int porta = 0x3da;
   unsigned char lido;

   /*Espera retraco terminar*/
   do
   {
       lido = inportb(porta);
   } while (lido & 8);

   /*Espera retraco reiniciar*/
   do
   {
       lido = inportb(porta);
   } while (!(lido & 8));
}
