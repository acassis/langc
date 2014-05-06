



CLEAR
A:=ARRAY(52,2)
DO WHILE .T.
   CLEAR
   DECLARA()
   X=1
   DO WHILE CONT<=52
      A[CONT,1]:=X
      B[CONT]:=1
      IF EMB>4
         EMB=1
      ENDIF
      A[CONT,2]:=EMB
      CONT:=CONT+1
      EMB++
      X++
      IF X>13
         X=1
      ENDIF
   ENDDO
   @ 00,00 TO 24,79 DOUBLE
   @ 10,05 TO 12,73
   @ 11,06 SAY "NUMERO DE VEZES A EMBARALHAR" GET EMB PICTURE "999"
   READ
   *EMB=SECONDS()
   @ 5,2 CLEAR TO 20,70
   IF LASTKEY()=27
      CLEAR
      RETURN
   ENDIF
   PARA=EMB
   J=(EMB%125)
   TELA()
DO WHILE CONT<=PARA
   ULT=52
   J=EMB
   P1=1
   DO WHILE EMB< ULT
      AUX1=A[ULT,1]
      AUX2=A[ULT,2]
      A[ULT,1]=A[EMB,1]
      A[ULT,2]=A[EMB,2]
      A[EMB,1]=AUX1
      A[EMB,2]=AUX2
      AUX1=A[P1,1]
      AUX2=A[P1,2]
      A[P1,1]=A[J,1]
      A[P1,2]=A[J,2]
      A[J,1]=AUX1
      A[J,2]=AUX2
      IF J>P1
         J=J-1
      ENDIF
      EMB=EMB+1
      ULT=ULT-1
      P1=P1+1
   ENDDO
   EMB=(EMB+ULT)+AUX1
   EMB=(EMB%30)+1
   CONT=CONT+1
ENDDO
CLEAR
@ 00,00 TO 24,79 DOUBLE
@ 09,01 TO 9,78 DOUBLE
@ 16,01 TO 16,78 DOUBLE
Y=2
FOR CONT=1 TO 26
   @ 11,Y SAY CHR(1)
   @ 13,Y SAY CHR(1)
   Y=Y+3
NEXT
X=10
C:=Y:=DIV:=1
I:=2
P1X=17
P1Y=31
PARA=0
DO WHILE PARA<>-1
  @1,1 SAY ALLTRIM(STR(C))  
   FORA()
   INKEY(0)
   @ X+1,Y+1 SAY CHR(1)

   IF LASTKEY()=4
      DIV=1
      Y=Y+3
      C=C+1
      IF C>26
         C=1
      ENDIF
      IF Y>76
         Y:=1
      ENDIF
   ENDIF
   IF LASTKEY()=19
      DIV=-1
      Y=Y-3
      C=C-1
      IF C<1
         C=26
      ENDIF
      IF Y<1
         Y=76
      ENDIF
   ENDIF
   IF LASTKEY()=5
      X=X-2
      IF I=1
         C=C-26
         I=2
      ELSE
         C=C+26
         I=1
      ENDIF
      IF X<10
         X=12
      ENDIF
   ENDIF
   IF LASTKEY()=24
      X=X+2
      IF X>12
         X=10
      ENDIF
   ENDIF
   IF LASTKEY()=8
      PARA=-1
      P1:=MAX
      P2:=MAX%3
   ENDIF 
   IF LASTKEY()=13
      IF C<=52 .AND. C>=1
         @ X+1,Y+1 SAY CHR(0) 
         AUX1=A[C,1]
         AUX2=A[C,2]
         IF AUX1<>0
            X=P1X
            Y=P1Y
   
            IMPRIMIR()
            CALCULAR()
            MAX=MAX+AUX1
            b[c]=2
            @ 17,5 SAY "PONTOS " + ALLTRIM(STR(MAX))
            C:=Y:=1
            X=10
            IF MAX>=28
               PARA:=-1
               P1:=P2:=35
            ENDIF
         ENDIF
      ENDIF
   ENDIF
ENDDO
P1X=1
P1Y=31
C:=Y:=1
X=10
DIV=1
PARA=16
MAXIMO=0
DO WHILE MAXIMO<=PARA
   IF MAX>21
      PARA=10
   ENDIF
   ULTJOGO:=P1+P2+5
   DO WHILE ULTJOGO>0
    @1,1 SAY ALLTRIM(STR(C))  
      Y=Y+3
      C=C+1
      IF C>52
         C=1
      ENDIF
      IF Y>76
         X=X+2
         Y=1
         IF I=1          
            C=1
            I=2
         ELSE
            C=27
            I=1
         ENDIF
         IF X>12
            X=10
            C:=Y:=1
         ENDIF
      ENDIF
      ULTJOGO=ULTJOGO-1
      FORA()
      INKEY(1/100)
      @ X+1,Y+1 SAY CHR(1)
   ENDDO
   P1=P2+AUX1
   P2=P1+AUX2
   IF C<=52
      AUX1=A[C,1]
      AUX2=A[C,2]
      @ X+1,Y+1 SAY CHR(0)
   ENDIF
   IF AUX1<>0
      X=P1X
      Y=P1Y
      IMPRIMIR()
      X=10
      CALCULAR()
      MAXIMO=MAXIMO+AUX1
      B[C]:=2
      @ 8,Y SAY  ALLTRIM(STR(B[C]))  
      @ 8,5 SAY "PONTOS " + ALLTRIM(STR(MAXIMO))
   ENDIF
ENDDO
@ 3,17 TO 4,17
@ 3,3  TO 3,25
@ 1,1 TO 5,25 
@ 2,4 SAY "COMPUTADOR X JOGADOR"
@4,4 SAY ALLTRIM (STR(MAXIMO))
@ 4,18 SAY ALLTRIM (STR(MAX))
INKEY(5)
IF (MAX>MAXIMO.AND.MAX<22).OR.(MAX<21.AND.MAXIMO>21).OR. MAX=21
   J=2
   TELA()
   @ 15,10 SAY"!!!! VOCE GANHOU!!!!"
ELSE
   IF (MAX<MAXIMO.AND.MAXIMO<22).OR.(MAX>21.AND.MAXIMO<21) .OR. MAXIMO=21
      J=14
      TELA()
      @ 15,10 SAY "####VOCE PERDEU####"
   ELSE
      IF MAX=MAXIMO
         J=178
         TELA()
         @ 15,10 SAY "JOGO EMPATADO "
      ENDIF
   ENDIF
ENDIF
@ 24,1 SAY "DESEJA CONTINUAR ? ENTER/ESC"
IF LASTKEY()=27
   RETURN
ENDIF
INKEY(6)
ENDDO

*****************
PROCEDURE DECLARA
  PUBLIC B:=ARRAY(52)
  PUBLIC EMB,CONT,PARA,AUX1,AUX2,ULT,P1X,P1Y,Y,C,I,J,MAX,MAXIMO,P1,P2,DIV
  EMB:=CONT:=1
  PARA:=AUX1:=AUX2:=ULT:=P1X:=P2X:=Y:=C:=I:=J:=MAX:=MAXIMO:=P1:=P2:=DIV:=PARA1:=0

******************  
PROCEDURE IMPRIMIR
  @x,Y TO x+6,Y+5
  P1Y:=P1Y+6
  IF AUX1=1
     @ X+1,Y+1 SAY "A"
  ELSE
     IF AUX1=11
        @ X+1,Y+1 SAY "J"
     ELSE
        IF AUX1=12
           @ X+1,Y+1 SAY "Q"
        ELSE
           IF AUX1=13
              @ X+1,Y+1 SAY "K"
           ELSE
              @ X+1,Y+2 SAY ALLTRIM(STR(AUX1))
           ENDIF
        ENDIF
     ENDIF
  ENDIF
  IF AUX2=1
   @ X+3,Y+3 SAY CHR(3)
ENDIF
IF AUX2=2
   @ X+3,Y+3 SAY CHR(4)
ENDIF
IF AUX2=3
   @ X+3,Y+3 SAY CHR(6)
ENDIF
IF AUX2=4
   @ X+3,Y+3 SAY CHR(5)
ENDIF

******************
PROCEDURE CALCULAR
IF AUX1>=10
   AUX1:=10
ENDIF

**************
PROCEDURE TELA
X=0
DO WHILE X<=24
   Y=0
   DO WHILE Y<=79
      @ X,Y SAY CHR(J)
      Y++
   ENDDO
   X++
ENDDO

**************
PROCEDURE FORA
PARA1:=1
DO WHILE PARA1=1
   IF B[C]=2
      @1,1 SAY ALLTRIM(STR(C))
      Y=Y+(3*DIV)
      C=C+DIV
      IF C>26.OR.C<1
         C=1
      ENDIF
      IF Y>76
         X=X+2
         Y=1
         IF I=1
            C=1
            I=2
         ELSE
            C=27
            I=1
         ENDIF
         IF X>12
            X=10
            C:=Y:=I:=1
         ENDIF
      ELSE 
         IF Y<1
            X=X+2
            Y=76
            IF I=1
               C=26
               I=2
            ELSE
               C=52
               I=1
            ENDIF
            IF X>12
               X=10
               C:=26
               Y:=76
               I:=1
            ENDIF
         ENDIF
      ENDIF
   ELSE
      @ X+1,Y+1 SAY CHR(2)
      PARA1=0
   ENDIF
ENDDO
