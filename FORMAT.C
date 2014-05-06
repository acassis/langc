#define  DISK                   0x13
#define  DSK                    0
#define  N_FACES                2
#define  N_TRILHAS              80
#define  SETORES_POR_TRILHAS    15
#define  BYTES_POR_SETOR        512
#define  CODIGO_DE_AJUSTE       0
#define  N_TENTATIVAS           1
#define  INICIO_FAT1            2
#define  INICIO_FAT2            9
#include <dos.h>
#include "boot_def.h"
struct boot buff_boot;
char buff[512];
int formatar(unsigned char trilha,unsigned char face,unsigned char drv,unsigned char setores_por_trilha,unsigned int byte_por_setor)
{
  struct disco
  {
	 unsigned char trilha,face,setor,bytes_por_setor;
  };
  struct disco *tab;
  union REGS regs;
  struct SREGS sregs;
  int i;
  tab=(struct disco *)
  malloc(sizeof(struct disco) * setores_por_trilha);
  for(i=1;i<=setores_por_trilha ;i++);
  {
    tab[i].trilha                 =trilha;
    tab[i].face                   =face;
    tab[i].setor                  =i;
    tab[i].bytes_por_setor        =byte_por_setor /256;
  }
    segread(&sregs);
    sregs.es=sregs.ds;
    regs.h.ah=0x05;
    regs.h.al=setores_por_trilha;
    regs.h.ch=trilha;
    regs.h.dl=drv;
    regs.x.bx=(unsigned int)tab;
    int86x(DISK,&regs,&regs,&sregs);
    return(regs.x.cflag ? regs.h.ah:0);
} ;
void far *tpb (char drv)
{
   union REGS regs ;
   struct SREGS sregs;
   union {
	  unsigned hilo[2];
	  unsigned long v;
	 }end;
	 regs.h.ah=0x08;
	 regs.h.dl=drv;
	 int86x(0x13,&regs,&regs,&sregs);
	 end.hilo[1]=sregs.es;
	 end.hilo[0]=regs.x.di;
	 return ((void far *)end.v);
}
int init_error(char drv)
{
  union REGS regs;
  regs.h.ah=0;
  regs.h.dl=drv;
  int86(DISK,&regs,&regs);
  return(regs.x.cflag ? regs.h.ah: 0);
}
void ajusta_disk(char drv,char cod)
{
   union REGS regs;
   regs.h.ah=0x17;
   regs.h.al=cod;
   regs.h.dl=drv;
   int86(DISK,&regs,&regs);
}
int grava_setor(unsigned char nsetor,unsigned seg,unsigned desloc,unsigned char trilha,unsigned char setor,unsigned char faces,unsigned char drv)
{
   union REGS regs;
   struct SREGS sregs;
   regs.h.ah=0x03;
   regs.h.al=nsetor;
   sregs.es=seg;
   regs.h.ch=trilha;
   regs.h.cl=setor;
   regs.h.dh=faces;
   regs.h.dl=drv;
   regs.x.bx=desloc;
   int86x(DISK,&regs,&regs,&sregs);
   return(regs.x.cflag ? regs.h.ah: 0);
}
void main(void)
{
   unsigned char far *p;
   unsigned char p1;
   struct SREGS sregs ;
   int trilha,setor,face,i,k;
   p=(unsigned char far *)getvect(0x1e);
   setvect(0x1e,(void interrupt(*) ())tpb(DSK));
   segread(&sregs);
   sregs.es=sregs.ds;
   if(init_error(DSK))
     printf("\nErro na inicializacÆo da controladora");
   ajusta_disk(DSK,CODIGO_DE_AJUSTE);
   for(trilha=0;trilha<N_TRILHAS;trilha++)
      for(face=0;face<N_FACES;face++)
	 formatar(trilha,face,DSK,SETORES_POR_TRILHAS,BYTES_POR_SETOR);
   for(trilha=0;trilha<2;trilha++)
     for(face=0;face<N_FACES;face++)
      for(setor=1;setor<=SETORES_POR_TRILHAS;setor++)
       for(k=0;k<N_TENTATIVAS;k++)
	 /*if(grava_setor(1,sregs.es,atoi(buff),trilha,setor,face,DSK))
	    printf("\nErro : trilha=%d setor =%d face=%d",trilha,setor,face);
	 else*/ break;
    buff[0]=0xf9;buff[1]=buff[2]=0xff;
    for(k=0;k<N_TENTATIVAS;k++)
       if(grava_setor(1,sregs.es,atoi(buff),0,INICIO_FAT1,0,DSK))
	   printf("\nErro:trilhas = 0 setor = 9 face=0");
       else break;
	 buff_boot.jump                     =0x3CEB;
	 buff_boot.nop                      =0x90;
	 strcpy(buff_boot.fabr,"A L  A N");
	 buff_boot.b_por_setor              =0x0200;
	 buff_boot.sets_por_cluster         =0x01;
	 buff_boot.sets_Reserv              =0x0001;
	 buff_boot.num_Fats                 =0x02;
	 buff_boot.entrs_em_root            =0x00E0;
	 buff_boot.sets_total               =0x0960;
	 buff_boot.ID_disco                 =0xF9;
	 buff_boot.sets_Fat                 =0x0007;
	 buff_boot.sets_Trilha              =0x000F;
	 buff_boot.faces                    =0x0002;
	 buff_boot.reserv1                  =0x00000000;
	 buff_boot.d_rigido                 =0x00000000;
	 buff_boot.reserv2                  =0x0000;
	 buff_boot.assinatura               =0x29;
	 buff_boot.ID_volume                =0xAABBCCDD;
	 strcpy(buff_boot.volume,"ALAN CARVAL");
	 strcpy(buff_boot.reserv3,"ALAN    CARVALHO");
	 strcpy(buff_boot.prog_boot,"DISCO DE ALAN SEM PROGRAMA DE BOOT");
	 buff_boot.fim1=0x55;
	 buff_boot.fim2=0xAA;
	 for(k=0;k<N_TENTATIVAS;k++)
	   if(grava_setor(1,sregs.es,atoi(&buff_boot),0,1,0,DSK))
	     printf("\Erro : trilha=0 setor=1 face=0");
	   else break;
	 strcpy(buff,"VOLUME-ALAN");
	 buff[0x0b]=0x28;
	 for(k=0;k<N_TENTATIVAS;k++)
	   if(grava_setor(1,sregs.es,atoi(buff),0,1,1,DSK))
	     printf("\Erro trilha 0 setor 1 face 1");
	   else break;
	 setvect(0x1e,(void interrupt(*)( ))p);
}