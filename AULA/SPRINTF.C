 #include <stdio.h>
 #include <math.h>
 #include <conio.h>
 #include <graphics.h>

 int main(void)
 {
    char buffer[80];
   int gdriver = DETECT, gmode, errorcode;
   int x, y,t,f;


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\arquiv~1\\bc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
    cleardevice();
    setcolor(2);
    sprintf(buffer,"An approximation of Pi is %f",M_PI);
    outtextxy(240,340,buffer);
    getch();
    return 0;
 }

