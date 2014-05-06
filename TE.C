#include<dos.h>
void main()
{
    int ct=0;
    while(!kbhit())
    {
       outport(0x3c0,ct);
       ct++;
    }
}
