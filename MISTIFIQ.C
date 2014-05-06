#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>

void main()
{
 int li1=1,co1=1,li2=479,co2=320,li3=1,co3=500,li4=240,co4=639;
 int lc1=0,cc1=0,lc2=1,  cc2=0,  lc3=0,  cc3=1,  lc4=1,  cc4=1;

 int drive=DETECT, modo;

 initgraph(&drive,&modo,"c:\\bc\\bgi");

 while(!kbhit()){

 if(lc1==0)
    li1++;
 else
    li1--;

 if(cc1==0)
    co1++;
 else
    co1--;

 if(lc2==0)
    li2++;
 else
    li2--;

 if(cc2==0)
    co2++;
 else
    co2--;

 if(lc3==0)
    li3=li3+2;
 else
    li3=li3-2;

 if(cc3==0)
    co3--;
 else
    co3++;

 if(lc4==0)
    li4++;
 else
    li4--;

 if(cc4==0)
    co4=co4+2;
 else
    co4=co4-2;

 if(li1>479)
    lc1=1;
 if(li1<0)
    lc1=0;

 if(co1>639)
    cc1=1;
 if(co1<0)
    cc1=0;

 if(li2>479)
    lc2=1;
 if(li2<0)
    lc2=0;

 if(co2>639)
    cc2=1;
 if(co2<0)
    cc2=0;

 if(li3>409)
    lc3=1;
 if(li3<0)
    lc3=0;

 if(co3>639)
    cc3=0;
 if(co3<0)
    cc3=1;

 if(li4>479)
    lc4=1;
 if(li4<0)
    lc4=0;

 if(co4>639)
    cc4=1;
 if(co4<0)
    cc4=0;
 setcolor(1);
 line(co1,li1,co4,li4);
 line(co1+6,li1+6,co4+6,li4+6);
 line(co1+12,li1+12,co4+12,li4+12);

 setcolor(2);
 line(co4,li4,co3,li3);
 line(co4+6,li4+6,co3+6,li3+6);
 line(co4+12,li4+12,co3+12,li3+12);

 setcolor(4);
 line(co3,li3,co2,li2);
 line(co3+6,li3+6,co2+6,li2+6);
 line(co3+12,li3+12,co2+12,li2+12);

 setcolor(6);
 line(co2,li2,co1+12,li1+12);
 line(co2+6,li2+6,co1+6,li1+6);
 line(co2+12,li2+12,co1,li1);

 delay(5);
 cleardevice();
 }
}