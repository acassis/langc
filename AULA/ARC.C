 #include <graphics.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <conio.h>
 int main(void)
 {
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy;
    int stangle =0, endangle = 360;
    int radius = 100,i=1;
    initgraph(&gdriver, &gmode, "\\bc\\bgi");
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
    setcolor(getmaxcolor());
    while(!kbhit())
    {i++;
     i=((i>=15)?1:i);
     setfillstyle(SOLID_FILL,i);
     arc(midx, midy, stangle, endangle, radius);
     floodfill(midx+3,midy+3,15);
     delay(500);
     }
     getch();
    closegraph();
    return 0;
 }

