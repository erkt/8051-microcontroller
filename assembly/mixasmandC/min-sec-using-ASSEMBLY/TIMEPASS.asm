CSEG AT 1000H
DB 0X40,0X79,0X24,0X30,0X19,0X12,0X02,0X78,0X00,0X10

CSEG AT 00H
MOV DPTR ,#1000H
MOV R5,#56
LOOP:
MOV A,R5
MOV B,#10
DIV AB
MOVC A,@A+DPTR
MOV P0,A
CLR P2.0
MOV R2,#10
DJNZ R2,$
MOV A,B
MOVC A,@A+DPTR
SETB P2.0
CLR P2.1
MOV P0,A
SJMP LOOP
SJMP $
END