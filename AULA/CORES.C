#include<graphics.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
main(){
 int gdriver=DETECT , gmod ,errorcode,i;
 initgraph(&gdriver,&gmod,"c:\\arquiv~1\\bc\\bgi");
 errorcode=graphresult();
 if(errorcode!=grOk)
  {
   printf("graphics error:%s\n",grapherrormsg(errorcode));
   printf("press any key  to halt:");
   getch();
   exit(1);
    }
/*
BLACK       DARKGRAY
BLUE        LIGHTBLUE
GREEN       LIGHTGREEN
CYAN        LIGHTCYAN
RED         LIGHTRED
MAGENTA     LIGHTMAGENTA
BROWN       YELLOW
LIGHTGRAY   WHITE
*/
   for(i=EMPTY_FILL;i<USER_FILL;i++){
    setfillstyle(i,DARKGRAY);
    bar(0,0,640,450);getch();}
   closegraph();
}
