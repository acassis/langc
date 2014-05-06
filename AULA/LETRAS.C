#ifndef __STRING_H
  #include <string.h>
#endif

#ifndef __STDIO_H
 #include <stdio.h>
#endif

#ifndef __CONIO_H
 #include<conio.h>
#endif
int caracter(char ch)
{
if((ch=='a') || (ch=='A')) return 0;

if((ch=='b') || (ch=='B')) return 1;

if((ch=='c') || (ch=='C')) return 2;

if((ch=='d') || (ch=='D')) return 3;

if((ch=='e') || (ch=='E')) return 4;

if((ch=='f') || (ch=='F')) return 5;

if((ch=='g') || (ch=='G')) return 6;

if((ch=='h') || (ch=='H')) return 7;

if((ch=='i') || (ch=='I')) return 8;

if((ch=='j') || (ch=='J')) return 9;

if((ch=='k') || (ch=='K')) return 10;

if((ch=='l') || (ch=='L')) return 11;

if((ch=='m') || (ch=='M')) return 12;

if((ch=='n') || (ch=='N')) return 13;

if((ch=='o') || (ch=='O')) return 14;

if((ch=='p') || (ch=='P')) return 15;

if((ch=='q') || (ch=='Q')) return 16;

if((ch=='r') || (ch=='R')) return 17;

if((ch=='s') || (ch=='S')) return 18;

if((ch=='t') || (ch=='T'))  return 19;

if((ch=='u') || (ch=='U')) return 20;

if((ch=='v') || (ch=='V')) return 21;

if((ch=='x') || (ch=='X')) return 22;

if((ch=='y') || (ch=='Y')) return 23;

if((ch=='w') || (ch=='W')) return 24;

if((ch=='z') || (ch=='Z')) return 25;

if(ch=='1') return 26;

if(ch=='2') return 27;

if(ch=='3') return 28;

if(ch=='4') return 29;

if(ch=='5') return 30;

if(ch=='6') return 31;

if(ch=='7') return 32;

if(ch=='8') return 33;

if(ch=='9') return 34;

if(ch=='0') return 35;

if(ch==' ') return 36;

return -1;
}




void letras(int l,int c,char *ch)
{
int letra,j,i,p=0;
char G[38][5][7];

strcpy(G[0][0],"мллллм ");
strcpy(G[0][1],"л    л ");
strcpy(G[0][2],"лллллл ");
strcpy(G[0][3],"л    л ");
strcpy(G[0][4],"л    л ");

strcpy(G[1][0],"лллллм ");
strcpy(G[1][1],"л    л ");
strcpy(G[1][2],"ллллл  ");
strcpy(G[1][3],"л    л ");
strcpy(G[1][4],"лллллп ");

strcpy(G[2][0],"лллллл " );
strcpy(G[2][1],"л      " );
strcpy(G[2][2],"л      " );
strcpy(G[2][3],"л      " );
strcpy(G[2][4],"лллллл " );


strcpy(G[3][0],"лллллм " );
strcpy(G[3][1],"л    л " );
strcpy(G[3][2],"л    л " );
strcpy(G[3][3],"л    л " );
strcpy(G[3][4],"лллллп " );

strcpy(G[4][0],"лллллл " );
strcpy(G[4][1],"л      " );
strcpy(G[4][2],"ллллл  " );
strcpy(G[4][3],"л      " );
strcpy(G[4][4],"лллллл " );

strcpy(G[5][0],"лллллл " );
strcpy(G[5][1],"л      " );
strcpy(G[5][2],"ллл    " );
strcpy(G[5][3],"л      " );
strcpy(G[5][4],"л      " );

strcpy(G[6][0],"лллллл " );
strcpy(G[6][1],"л    п " );
strcpy(G[6][2],"л  ллл " );
strcpy(G[6][3],"л    л " );
strcpy(G[6][4],"лллллл " );

strcpy(G[7][0],"л    л " );
strcpy(G[7][1],"л    л " );
strcpy(G[7][2],"лллллл " );
strcpy(G[7][3],"л    л " );
strcpy(G[7][4],"л    л " );

strcpy(G[8][0],"  ллл  " );
strcpy(G[8][1],"   л   " );
strcpy(G[8][2],"   л   " );
strcpy(G[8][3],"   л   " );
strcpy(G[8][4],"  ллл  " );

strcpy(G[9][0],"     л ");
strcpy(G[9][1],"     л ");
strcpy(G[9][2],"     л ");
strcpy(G[9][3],"л    л ");
strcpy(G[9][4],"лллллл ");

strcpy(G[10][0],"л    л ");
strcpy(G[10][1],"л  мп  ");
strcpy(G[10][2],"ллл    ");
strcpy(G[10][3],"л  пм  ");
strcpy(G[10][4],"л    л ");

strcpy(G[11][0],"л      ");
strcpy(G[11][1],"л      ");
strcpy(G[11][2],"л      ");
strcpy(G[11][3],"л    л ");
strcpy(G[11][4],"лллллл ");

strcpy(G[12][0],"лллллл ");
strcpy(G[12][1],"л лл л ");
strcpy(G[12][2],"л лл л ");
strcpy(G[12][3],"л лл л ");
strcpy(G[12][4],"л    л ");

strcpy(G[13][0],"лл   л ");
strcpy(G[13][1],"л л  л ");
strcpy(G[13][2],"л  л л ");
strcpy(G[13][3],"л   лл ");
strcpy(G[13][4],"л    л ");

strcpy(G[14][0],"лллллл ");
strcpy(G[14][1],"л    л ");
strcpy(G[14][2],"л    л ");
strcpy(G[14][3],"л    л ");
strcpy(G[14][4],"лллллл ");

strcpy(G[15][0],"лллллм ");
strcpy(G[15][1],"л    л ");
strcpy(G[15][2],"лллллп ");
strcpy(G[15][3],"л      ");
strcpy(G[15][4],"л      ");

strcpy(G[16][0],"лллллл ");
strcpy(G[16][1],"л    л ");
strcpy(G[16][2],"л    л ");
strcpy(G[16][3],"л    л ");
strcpy(G[16][4],"пппппл ");

strcpy(G[17][0],"лллллм ");
strcpy(G[17][1],"л    л ");
strcpy(G[17][2],"лллллп ");
strcpy(G[17][3],"л  ллм ");
strcpy(G[17][4],"л    л ");

strcpy(G[18][0],"лллллл ");
strcpy(G[18][1],"л      ");
strcpy(G[18][2],"лллллл ");
strcpy(G[18][3],"     л ");
strcpy(G[18][4],"лллллл ");

strcpy(G[19][0],"лллллл ");
strcpy(G[19][1],"  лл   ");
strcpy(G[19][2],"  лл   ");
strcpy(G[19][3],"  лл   ");
strcpy(G[19][4],"  лл   ");

strcpy(G[20][0],"л    л ");
strcpy(G[20][1],"л    л ");
strcpy(G[20][2],"л    л ");
strcpy(G[20][3],"л    л ");
strcpy(G[20][4],"лллллл ");

strcpy(G[21][0],"л    л ");
strcpy(G[21][1],"л    л ");
strcpy(G[21][2],"л    л ");
strcpy(G[21][3]," л  л  ");
strcpy(G[21][4],"  лл   ");

strcpy(G[22][0],"л    л ");
strcpy(G[22][1]," л  л  ");
strcpy(G[22][2],"  лл   ");
strcpy(G[22][3]," л  л  ");
strcpy(G[22][4],"л    л ");

strcpy(G[23][0],"л    л ");
strcpy(G[23][1],"л    л ");
strcpy(G[23][2]," л  л  ");
strcpy(G[23][3],"  лл   ");
strcpy(G[23][4],"  лл   ");

strcpy(G[24][0],"л    л ");
strcpy(G[24][1],"л лл л ");
strcpy(G[24][2],"л лл л ");
strcpy(G[24][3],"л лл л ");
strcpy(G[24][4],"лллллл ");

strcpy(G[25][0],"лллллл ");
strcpy(G[25][1],"     л ");
strcpy(G[25][2],"лллллп ");
strcpy(G[25][3],"л      ");
strcpy(G[25][4],"лллллл ");

strcpy(G[26][0],"  лл   ");
strcpy(G[26][1],"   л   ");
strcpy(G[26][2],"   л   ");
strcpy(G[26][3],"   л   ");
strcpy(G[26][4],"  ллл  ");

strcpy(G[27][0],"лллллл ");
strcpy(G[27][1],"     л ");
strcpy(G[27][2],"лллллл ");
strcpy(G[27][3],"л      ");
strcpy(G[27][4],"лллллл ");

strcpy(G[28][0],"лллллм ");
strcpy(G[28][1],"     л ");
strcpy(G[28][2],"ллллл  ");
strcpy(G[28][3],"     л ");
strcpy(G[28][4],"лллллп ");

strcpy(G[29][0],"л    л ");
strcpy(G[29][1],"л    л ");
strcpy(G[29][2],"лллллл ");
strcpy(G[29][3],"     л ");
strcpy(G[29][4],"     л ");

strcpy(G[30][0],"лллллл ");
strcpy(G[30][1],"л      ");
strcpy(G[30][2],"лллллл ");
strcpy(G[30][3],"     л ");
strcpy(G[30][4],"лллллл ");

strcpy(G[31][0],"лл     ");
strcpy(G[31][1],"л      ");
strcpy(G[31][2],"лллллл ");
strcpy(G[31][3],"л    л ");
strcpy(G[31][4],"лллллл ");

strcpy(G[32][0],"лллллл ");
strcpy(G[32][1],"     л ");
strcpy(G[32][2],"     л ");
strcpy(G[32][3],"     л ");
strcpy(G[32][4],"     л ");

strcpy(G[33][0],"лллллл ");
strcpy(G[33][1],"л    л ");
strcpy(G[33][2],"лллллл ");
strcpy(G[33][3],"л    л ");
strcpy(G[33][4],"лллллл ");

strcpy(G[34][0],"лллллл ");
strcpy(G[34][1],"л    л ");
strcpy(G[34][2],"лллллл ");
strcpy(G[34][3],"     л ");
strcpy(G[34][4],"    лл ");

strcpy(G[35][0],"лллллл ");
strcpy(G[35][1],"л  л л ");
strcpy(G[35][2],"л л  л ");
strcpy(G[35][3],"лл   л ");
strcpy(G[35][4],"лллллл ");

strcpy(G[36][0],"       ");
strcpy(G[36][1],"       ");
strcpy(G[36][2],"       ");
strcpy(G[36][3],"       ");
strcpy(G[36][4],"       ");

while(*ch)
{
 letra=caracter(*ch);
 for(j=0;j<5;j++)
  for(i=0;i<7;i++)
  {
   gotoxy(p+i+c,l+j);
   printf("%c",G[letra][j][i]);
  }
 p=p+8;
 ch++;
}
}

void main(void)
{
  clrscr();
  letras(1,1,"Alan");
  letras(8,1,"Carvalho");
  letras(15,1,"Assis");
}
