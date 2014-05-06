#include <conio.h>
#include <stdio.h>
#include <dos.h>
int colmouse();
int linmouse();
int status(void);
void mouse (void);
char confm(int nu);
char confn(int nu);
int m1[6],m2[6],m3[6],m4[6],m5[6],m6[6],i,ct=0,num=0,n1[6],n2[6],n3[6],n4[6],n5[6],n6[6],sta=0,pl=0,pc=0,num1,lx,cx;
char tes,res,nu[2],nu1,nu2;
void main(void)
{
  for(i=0;i<6;i++)
   {  m1[i]=0; m6[i]=0; m2[i]=0;m3[i]=0;m4[i]=0;m5[i]=0;}
  for (i=0;i<6;i++)
   {  n1[i]=0; n6[i]=0; n2[i]=0;n3[i]=0;n4[i]=0;n5[i]=0;}
  clrscr();
  gotoxy(20,7);
  printf("зддбддбддбдд©");
  gotoxy(20,8);
  printf("Ё<>Ё  Ё  Ё  Ё");
  gotoxy(20,9);
  printf("цддеддеддедд╢");
  gotoxy(20,10);
  printf("Ё  Ё  Ё  Ё  Ё");
  gotoxy(20,11);
  printf("цддеддеддедд╢");
  gotoxy(20,12);
  printf("Ё  Ё  Ё  Ё  Ё");
  gotoxy(20,13);
  printf("цддеддеддедд╢");
  gotoxy(20,14);
  printf("Ё  Ё  Ё  Ё  Ё");
  gotoxy(20,15);
  printf("юддаддаддадды");
  gotoxy(48,7);
  printf("зддбддбддбдд©");
  gotoxy(48,8);
  printf("Ё<>Ё  Ё  Ё  Ё");
  gotoxy(48,9);
  printf("цддеддеддедд╢");
  gotoxy(48,10);
  printf("Ё  Ё  Ё  Ё  Ё");
  gotoxy(48,11);
  printf("цддеддеддедд╢");
  gotoxy(48,12);
  printf("Ё  Ё  Ё  Ё  Ё");
  gotoxy(48,13);
  printf("цддеддеддедд╢");
  gotoxy(48,14);
  printf("Ё  Ё  Ё  Ё  Ё");
  gotoxy(48,15);
  printf("юддаддаддадды");
  ct=0;
  tes='n';
  while(ct<15)
   {
     res='n';
     if(ct==0)
      { gotoxy(24,8);
	nu1=getche();
	gotoxy(25,8);
	nu2=getche();
	nu[1]=nu1;nu[2]=nu2;
	gets(nu);num=atoi(nu);

	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m2[2]=num;
	 }
      }
     if(ct==1)
      { gotoxy(27,8);
	scanf("%c",nu1);
	gotoxy(28,8);
	scanf("%c",nu2);
	nu[1]=nu1;nu[2]=nu2;
	num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m2[3]=num;
	 }
       }
      if(ct==2)
      { gotoxy(30,8);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m2[4]=num;
	 }
       }
      if(ct==3)
      { gotoxy(21,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m3[1]=num;
	 }
       }
      if(ct==4)
      /*alan*/
      { gotoxy(24,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m3[2]=num;
	 }
       }
      if(ct==5)
      { gotoxy(27,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m3[3]=num;
	 }
       }
      if(ct==6)
      { gotoxy(30,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m3[4]=num;
	 }
       }
      if(ct==7)
      { gotoxy(21,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m4[1]=num;
	 }
       }
       if(ct==8)
      { gotoxy(24,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m4[2]=num;
	 }
       }
       if(ct==9)
      { gotoxy(27,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m4[3]=num;
	 }
       }
       if(ct==10)
      { gotoxy(30,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m4[4]=num;
	 }
       }
      if(ct==11)
      { gotoxy(21,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m5[1]=num;
	 }
       }
      if(ct==12)
      { gotoxy(24,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m5[2]=num;
	 }
       }
      if(ct==13)
      { gotoxy(27,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m5[3]=num;
	 }
       }
      if(ct==14)
      { gotoxy(30,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confm(num);
	   if(res=='s')
	      m5[4]=num;
	 }
       }
      if(res=='s')
	ct++;
   }
  tes='n';
  ct=0;
  res='n';
  while(ct<15)
   {
     if(res=='s')
	   ct++;
     if(ct==0)
      {
	gotoxy(52,8);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n2[2]=num;
	 }
      }
     if(ct==1)
      { gotoxy(55,8);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n2[3]=num;
	 }
       }
      if(ct==2)
      { gotoxy(58,8);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n2[4]=num;
	 }
       }
      if(ct==3)
      { gotoxy(49,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n3[1]=num;
	 }
       }
      if(ct==4)
      { gotoxy(52,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n3[2]=num;
	 }
       }
      if(ct==5)
      { gotoxy(55,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n3[3]=num;
	 }
       }
      if(ct==6)
      { gotoxy(58,10);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n3[4]=num;
	 }
       }
      if(ct==7)
      { gotoxy(49,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n4[1]=num;
	 }
       }
       if(ct==8)
      { gotoxy(52,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n4[2]=num;
	 }
       }
       if(ct==9)
      { gotoxy(55,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n4[3]=num;
	 }
       }
       if(ct==10)
      { gotoxy(58,12);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n4[4]=num;
	 }
       }
      if(ct==11)
      { gotoxy(49,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n5[1]=num;
	 }
       }
      if(ct==12)
      { gotoxy(52,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n5[2]=num;
	 }
       }
      if(ct==13)
      { gotoxy(55,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n5[3]=num;
	 }
       }
      if(ct==14)
      { gotoxy(58,14);
	gets(nu);num=atoi(nu);
	if(num!=0)
	 {
	   res=confn(num);
	   if(res=='s')
	      n5[4]=num;
	 }

       }
  }
  mouse();
  ct=0;
  sta=0;
  while(ct<30)
   {
     res='s';
     if(ct%2==0)
     {
      while(sta==0)
	 {
	   sta=status();
	   if(pl==0 && pc==0){
	      if(colmouse()==7 || colmouse()==9)
		if(linmouse()==20||linmouse()==21||linmouse()==23||linmouse()==24)
		  { cx=linmouse();
		    lx=colmouse();}}
	   else if(pl==7&&pc==23||pl==7&&pc==24||pl==9&&pc==20||pl==9&&pc==21||pl==9&&pc==23||pl==9&&pc==24){
		   if(colmouse()==7||colmouse()==9||colmouse()==11)
		     if(linmouse()==20||linmouse()==21||linmouse()==23||linmouse()==24||linmouse()==26||linmouse()==27||linmouse()==29||linmouse()==30){
			 cx=linmouse();
			 lx=colmouse();}}
	 }
      while(sta!=0)
	    sta=status();
	   pl=lx;
	   pc=cx;
	   if(pl==7 && pc==23 || pl==7 &&pc==24)
		num1=m2[2];
	   else if(pl==7 && pc==26 || pl==7 &&pc==27)
	     num1=m2[3];
	   else if(pl==7 && pc==30 || pl==7 &&pc==29)
	     num1=m2[4];
	   else if(pl==9 && pc==20 || pl==9 &&pc==21)
	     num1=m3[1];
	   else if(pl==9 && pc==24 || pl==9 &&pc==23)
	     num1=m3[2];
	   else if(pl==9 && pc==27 || pl==9 &&pc==26)
	     num1=m3[3];
	   else if(pl==9 && pc==30 || pl==9 &&pc==29)
	     num1=m3[4];
	   else if(pl==11 && pc==21 || pl==11 &&pc==20)
	     num1=m4[1];
	   else if(pl==11 && pc==24 || pl==11 &&pc==23)
	     num1=m4[2];
	   else if(pl==11 && pc==27 || pl==11 &&pc==26)
	     num1=m4[3];
	   else if(pl==11 && pc==30 || pl==11 &&pc==29)
	     num1=m4[4];
	   else if(pl==13 && pc==21 || pl==13 &&pc==20)
	     num1=m5[1];
	   else if(pl==13 && pc==24 || pl==13 &&pc==23)
	     num1=m5[2];
	   else if(pl==13 && pc==27 || pl==13 &&pc==26)
	     num1=m5[3];
	   else if(pl==13 && pc==30 || pl==13 &&pc==29)
	     num1=m5[4];
	   else res='n';
	   printf("AQUI:%d",num1);
	   }
       if(res=='s')
	   ct++;
  }
}
int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx/8);

  }

int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx/8);
  }
void mouse (void)
  { union REGS regs;
   regs.h.ah=0x00;
   regs.h.al=4;
   regs.x.ax=1;
   int86 (0x33,&regs,&regs);
  }
int status(void)
{
     union REGS regs;
     regs.x.ax=3;
     int86(0x33,&regs,&regs);
     return(regs.x.bx);
}
char confm(int nu)
{
  if(nu>0 && nu<16)
   { for(i=0;i<6;i++)
      if(m1[i]==nu || m2[i]==nu || m3[i]==nu || m4[i]==nu || m5[i]==nu || m6[i]==nu)
	return 'n';
      return 's';
   }
   return 'n';
}
char confn(int nu)
{
  if(nu>0 && nu<16)
   { for(i=0;i<6;i++)
      if(n1[i]==nu || n2[i]==nu || n3[i]==nu || n4[i]==nu || n5[i]==nu || n6[i]==nu)
	return 'n';
      return 's';
   }
   return 'n';
}
