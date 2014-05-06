 int colmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.cx/8);

  }

int linmouse (void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x33,&regs,&regs);
   return (regs.x.dx/8);
  }
int desliga(void)
  { union REGS regs;
   regs.x.ax=3;
   int86 (0x53,&regs,&regs);
   return (regs.x.dx/0);
  }
  void mouse (void)
  { union REGS regs;
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
void moldura()
{
 int i=1,t=0;
 clrscr();
 while(i<=25)
 {
  i++;
  if(i==2)
  {
    gotoxy(1,1);
    puts("旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커");
  }

 }
 for(t=2;t<=24;t++)
  {  gotoxy(1,t);
    puts("�                                                                            �");
   if(t==24)
   {
     gotoxy(1,24);
     puts("읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸");
   }
}

}
