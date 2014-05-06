//----------------------------------------------------------------------------
//Programa: Alan_asm.c
//Autor: Alan Carvalho de Assis
//Compilador:Borland C++ Versao 2.0 ou 3.0
//Descricao: Efito com caracteres formando meu nome.
//-----------------------------------------------------------------------------
void main()
{
_setcursortype(0);
asm mov     ax,3h
asm int     10h
asm mov ah,2h
asm mov al,0h
asm mov bh,0h
asm mov dh,9h
asm mov dl,9h
asm mov ch,0h
asm mov bl,0h
incre:
asm push dx
asm push ax
asm mov dx,60h
asm in  al,dx
asm cmp al,60h
asm jae vaine
asm mov ah,4ch
asm int 21h
vaine:
asm pop ax
asm pop dx
asm inc dh
asm inc dl
asm mov cx,3278
delay:
asm       loop delay
compara:
asm      cmp dh,24
asm	 ja verif1
continua:
asm	 cmp dl,79
asm	 jae verif2
asm	 jmp eposic
continua2:
asm	 mov ah,2h
asm	 int 10h
asm	 mov cl,dl
asm	 mov dl,32
asm	 int 21h
asm	 mov dl,cl
asm	 jmp incre
verif1:
asm       mov dh,0h
asm       jmp continua
verif2:
asm       mov dl,0h
asm       jmp continua2
eposic:
asm       cmp dl,10
asm       jne posc1
asm       cmp dh,8
asm       jb  posc1
asm       cmp dh,16
asm       jae posc1
asm       jmp escv
posc1:
asm	  cmp dl,18
asm       jne posc2
asm       cmp dh,8
asm       jb  posc2
asm       cmp dh,16
asm       jae  posc2
asm       jmp escv
posc2:
asm       cmp dl,18
asm       ja  posc3
asm       cmp dl,10
asm       jb  posc3
asm       cmp dh,8
asm       jne  posc21
asm       jmp escv
posc21:
asm	 cmp dh,12
asm	 je esci
asm	 jmp nada
esci:
asm	 jmp escv
posc3:
asm	 cmp dh,8
asm	 jb posc4
asm	 cmp dh,16
asm	 jae posc4
asm	 cmp dl,26
asm	 jne posc4
asm	 jmp escv
posc4:
asm	 cmp dl,26
asm	 jb posc5
asm	 cmp dl,34
asm	 ja  posc5
asm	 cmp dh,15
asm	 jne posc5
asm	 jmp escv
posc5:
asm       cmp dl,42
asm       jne posc12
asm       cmp dh,8
asm       jb  posc12
asm       cmp dh,16
asm       jae posc12
asm       jmp escv
posc12:
asm       cmp dl,50
asm       jne posc22
asm       cmp dh,8
asm       jb  posc22
asm       cmp dh,16
asm       jae  posc22
asm       jmp escv
posc22:
asm       cmp dl,50
asm       ja  posc6
asm       cmp dl,42
asm       jbe nada
asm       cmp dh,8
asm       je  escv
asm       jmp posc212
posc212:
asm	 cmp dh,12
asm	 je  escv
posc6:
asm	 cmp dl,58
asm	 jne posc7
asm	 cmp dh,8
asm	 jb  posc7
asm	 cmp dh,16
asm	 jae posc7
asm	 jmp escv
posc7:
asm	 cmp dl,67
asm	 jne posc8
asm	 cmp dh,8
asm	 jb  posc8
asm	 cmp dh,16
asm	 jae posc8
asm	 jmp escv
posc8:
asm	 cmp dh,8
asm	 jb  nada
asm	 cmp dh,15
asm	 ja  nada
asm	 mov al,dh
asm	 add al,51
asm	 cmp al,dl
asm	 jne nada
asm	 jmp escv
nada:
asm	 jmp continua2
escv:
asm	 int 10h
asm	 push dx
asm	 inc dl
asm	 inc bl
asm	 mov ah,02h
asm	 int 10h
asm	 mov ah,09h
asm	 mov al,219
asm	 mov bh,0h
asm	 mov bl,15
asm	 mov cx,1
asm	 int 10h
asm	 inc dl
asm	 mov ah,02h
asm	 int 10h
asm	 mov ah,09h
asm	 mov al,219
asm	 mov bh,0h
asm	 mov bl,9
asm	 mov cx,1
asm	 int 10h
asm	 pop dx
asm	 jmp continua2
}