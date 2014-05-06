//---------------------------------------------------------------------------
#include <vcl\condefs.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>

#pragma hdrstop
//---------------------------------------------------------------------------
USERES("Server.res");
//----------------------------------------------------------------------------

unsigned int inportb(int porta)
{
  _DX = porta;
  __emit__(0xEC);
  return (_AL);
}
//----------------------------------------------------------------------------

int main(int argc, char **argv)
{
    SOCKADDR_IN sin;
    SOCKET s;
    SOCKET sClient;
    WORD wVersionRequested;
    WSADATA wsaData;
    char ch='A';
    char cha;
    unsigned char tecla;
    int err;

    printf("Inicio ...\n");
    wVersionRequested = MAKEWORD(1, 1);
    err = WSAStartup(wVersionRequested, &wsaData);

    s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("socket ...\n");

    u_short alport = 2000;

    sin.sin_family = PF_INET;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port = htons(alport);

    err = bind(s, (LPSOCKADDR)&sin, sizeof (sin));
    printf("bind ...\n");

    err = listen( s, 5);
    printf("listen ...\n");

    sClient = accept( s, (LPSOCKADDR)&sin, NULL);
    printf("accept ...\n");

    err = send( s, &ch, 2, MSG_OOB);
    if(err != -1)
       printf("send ...\n");

    printf("Digite algo...\n");
    while(1)
    {
        printf("Esperando!");
	err = recv( s, &cha, 2, MSG_OOB);
        if(err != -1)
           printf("caracter:%c",cha);
        else
           printf("\nNão");
    }

    return 0;
}
//---------------------------------------------------------------------------
