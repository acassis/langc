 #include <graphics.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <conio.h>
 char *hjust[] = { "LEFT_TEXT",
		   "CENTER_TEXT",
		   "RIGHT_TEXT"
		 };
 char *vjust[] = { "LEFT_TEXT",
		   "CENTER_TEXT",
		   "RIGHT_TEXT"
		 };
 int main(void)
 {
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy, hj, vj;
    char msg[80];
    initgraph(&gdriver, &gmode, "\\arquiv~1\\bc\\bgi");
    errorcode = graphresult();
    if (errorcode != grOk)
    {
       printf("Graphics error: %s\n", grapherrormsg(errorcode));
       printf("Press any key to halt:");
       getch();
       exit(1);
    }

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    for(hj=LEFT_TEXT; hj<=RIGHT_TEXT; hj++)
       for (vj=LEFT_TEXT; vj<=RIGHT_TEXT; vj++)
       {
	  cleardevice();
	  settextstyle(2,VERT_DIR,5);
	  settextjustify(hj, vj);
	  sprintf(msg,"%s  %s",hjust[hj], vjust[vj]);
	  outtextxy(midx, midy, msg);
	  getch();
	  settextstyle(2,HORIZ_DIR,5);
	  settextjustify(hj, vj);
	  sprintf(msg,"%s  %s",hjust[hj], vjust[vj]);
	  outtextxy(midx, midy, msg);
	  getch();

       }
       getch();
    closegraph();
    return 0;
 }


