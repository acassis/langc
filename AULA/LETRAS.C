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

strcpy(G[0][0],"������ ");
strcpy(G[0][1],"�    � ");
strcpy(G[0][2],"������ ");
strcpy(G[0][3],"�    � ");
strcpy(G[0][4],"�    � ");

strcpy(G[1][0],"������ ");
strcpy(G[1][1],"�    � ");
strcpy(G[1][2],"�����  ");
strcpy(G[1][3],"�    � ");
strcpy(G[1][4],"������ ");

strcpy(G[2][0],"������ " );
strcpy(G[2][1],"�      " );
strcpy(G[2][2],"�      " );
strcpy(G[2][3],"�      " );
strcpy(G[2][4],"������ " );


strcpy(G[3][0],"������ " );
strcpy(G[3][1],"�    � " );
strcpy(G[3][2],"�    � " );
strcpy(G[3][3],"�    � " );
strcpy(G[3][4],"������ " );

strcpy(G[4][0],"������ " );
strcpy(G[4][1],"�      " );
strcpy(G[4][2],"�����  " );
strcpy(G[4][3],"�      " );
strcpy(G[4][4],"������ " );

strcpy(G[5][0],"������ " );
strcpy(G[5][1],"�      " );
strcpy(G[5][2],"���    " );
strcpy(G[5][3],"�      " );
strcpy(G[5][4],"�      " );

strcpy(G[6][0],"������ " );
strcpy(G[6][1],"�    � " );
strcpy(G[6][2],"�  ��� " );
strcpy(G[6][3],"�    � " );
strcpy(G[6][4],"������ " );

strcpy(G[7][0],"�    � " );
strcpy(G[7][1],"�    � " );
strcpy(G[7][2],"������ " );
strcpy(G[7][3],"�    � " );
strcpy(G[7][4],"�    � " );

strcpy(G[8][0],"  ���  " );
strcpy(G[8][1],"   �   " );
strcpy(G[8][2],"   �   " );
strcpy(G[8][3],"   �   " );
strcpy(G[8][4],"  ���  " );

strcpy(G[9][0],"     � ");
strcpy(G[9][1],"     � ");
strcpy(G[9][2],"     � ");
strcpy(G[9][3],"�    � ");
strcpy(G[9][4],"������ ");

strcpy(G[10][0],"�    � ");
strcpy(G[10][1],"�  ��  ");
strcpy(G[10][2],"���    ");
strcpy(G[10][3],"�  ��  ");
strcpy(G[10][4],"�    � ");

strcpy(G[11][0],"�      ");
strcpy(G[11][1],"�      ");
strcpy(G[11][2],"�      ");
strcpy(G[11][3],"�    � ");
strcpy(G[11][4],"������ ");

strcpy(G[12][0],"������ ");
strcpy(G[12][1],"� �� � ");
strcpy(G[12][2],"� �� � ");
strcpy(G[12][3],"� �� � ");
strcpy(G[12][4],"�    � ");

strcpy(G[13][0],"��   � ");
strcpy(G[13][1],"� �  � ");
strcpy(G[13][2],"�  � � ");
strcpy(G[13][3],"�   �� ");
strcpy(G[13][4],"�    � ");

strcpy(G[14][0],"������ ");
strcpy(G[14][1],"�    � ");
strcpy(G[14][2],"�    � ");
strcpy(G[14][3],"�    � ");
strcpy(G[14][4],"������ ");

strcpy(G[15][0],"������ ");
strcpy(G[15][1],"�    � ");
strcpy(G[15][2],"������ ");
strcpy(G[15][3],"�      ");
strcpy(G[15][4],"�      ");

strcpy(G[16][0],"������ ");
strcpy(G[16][1],"�    � ");
strcpy(G[16][2],"�    � ");
strcpy(G[16][3],"�    � ");
strcpy(G[16][4],"������ ");

strcpy(G[17][0],"������ ");
strcpy(G[17][1],"�    � ");
strcpy(G[17][2],"������ ");
strcpy(G[17][3],"�  ��� ");
strcpy(G[17][4],"�    � ");

strcpy(G[18][0],"������ ");
strcpy(G[18][1],"�      ");
strcpy(G[18][2],"������ ");
strcpy(G[18][3],"     � ");
strcpy(G[18][4],"������ ");

strcpy(G[19][0],"������ ");
strcpy(G[19][1],"  ��   ");
strcpy(G[19][2],"  ��   ");
strcpy(G[19][3],"  ��   ");
strcpy(G[19][4],"  ��   ");

strcpy(G[20][0],"�    � ");
strcpy(G[20][1],"�    � ");
strcpy(G[20][2],"�    � ");
strcpy(G[20][3],"�    � ");
strcpy(G[20][4],"������ ");

strcpy(G[21][0],"�    � ");
strcpy(G[21][1],"�    � ");
strcpy(G[21][2],"�    � ");
strcpy(G[21][3]," �  �  ");
strcpy(G[21][4],"  ��   ");

strcpy(G[22][0],"�    � ");
strcpy(G[22][1]," �  �  ");
strcpy(G[22][2],"  ��   ");
strcpy(G[22][3]," �  �  ");
strcpy(G[22][4],"�    � ");

strcpy(G[23][0],"�    � ");
strcpy(G[23][1],"�    � ");
strcpy(G[23][2]," �  �  ");
strcpy(G[23][3],"  ��   ");
strcpy(G[23][4],"  ��   ");

strcpy(G[24][0],"�    � ");
strcpy(G[24][1],"� �� � ");
strcpy(G[24][2],"� �� � ");
strcpy(G[24][3],"� �� � ");
strcpy(G[24][4],"������ ");

strcpy(G[25][0],"������ ");
strcpy(G[25][1],"     � ");
strcpy(G[25][2],"������ ");
strcpy(G[25][3],"�      ");
strcpy(G[25][4],"������ ");

strcpy(G[26][0],"  ��   ");
strcpy(G[26][1],"   �   ");
strcpy(G[26][2],"   �   ");
strcpy(G[26][3],"   �   ");
strcpy(G[26][4],"  ���  ");

strcpy(G[27][0],"������ ");
strcpy(G[27][1],"     � ");
strcpy(G[27][2],"������ ");
strcpy(G[27][3],"�      ");
strcpy(G[27][4],"������ ");

strcpy(G[28][0],"������ ");
strcpy(G[28][1],"     � ");
strcpy(G[28][2],"�����  ");
strcpy(G[28][3],"     � ");
strcpy(G[28][4],"������ ");

strcpy(G[29][0],"�    � ");
strcpy(G[29][1],"�    � ");
strcpy(G[29][2],"������ ");
strcpy(G[29][3],"     � ");
strcpy(G[29][4],"     � ");

strcpy(G[30][0],"������ ");
strcpy(G[30][1],"�      ");
strcpy(G[30][2],"������ ");
strcpy(G[30][3],"     � ");
strcpy(G[30][4],"������ ");

strcpy(G[31][0],"��     ");
strcpy(G[31][1],"�      ");
strcpy(G[31][2],"������ ");
strcpy(G[31][3],"�    � ");
strcpy(G[31][4],"������ ");

strcpy(G[32][0],"������ ");
strcpy(G[32][1],"     � ");
strcpy(G[32][2],"     � ");
strcpy(G[32][3],"     � ");
strcpy(G[32][4],"     � ");

strcpy(G[33][0],"������ ");
strcpy(G[33][1],"�    � ");
strcpy(G[33][2],"������ ");
strcpy(G[33][3],"�    � ");
strcpy(G[33][4],"������ ");

strcpy(G[34][0],"������ ");
strcpy(G[34][1],"�    � ");
strcpy(G[34][2],"������ ");
strcpy(G[34][3],"     � ");
strcpy(G[34][4],"    �� ");

strcpy(G[35][0],"������ ");
strcpy(G[35][1],"�  � � ");
strcpy(G[35][2],"� �  � ");
strcpy(G[35][3],"��   � ");
strcpy(G[35][4],"������ ");

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
