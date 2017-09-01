//1.	Write  8051 assembly programs to create  generate a square wave of duty cycles 75%.
LCD EQU P0
RS BIT P3.4
RW BIT P3.5
EN BIT P3.6
CSEG AT 00H
	AJMP MAIN
CSEG AT 1000H
	DB 0XFF,0X10,0X10,0X10,0X10,0X10,0X10,0X10
	DB 0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00
	DB 0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF
	DB 0X10,0X10,0X10,0X10,0X10,0X10,0X10,0XFF

CSEG AT 100H
INI:
    MOV R5,#0X01
	ACALL CMD
	MOV R5,#0X02
	ACALL CMD
	MOV R5,#0X06
	ACALL CMD
	MOV R5,#0X0C
	ACALL CMD
	MOV R5,#0X38
	ACALL CMD
	MOV R5,#0X80
	ACALL CMD
	RET
DEL:
	MOV TMOD,#0X01
	MOV TH0,#(64548>>8)
	MOV TL0,#(64548& 0XFF)
	SETB TR0
	JNB TF0,$
	CLR TR0
	CLR TF0
	RET
CMD:
	MOV LCD,R5
	CLR RS
	CLR RW
	SETB EN
	ACALL DEL
	CLR EN
	RET
DIS:
	MOV LCD,A
	SETB RS
	CLR RW
	SETB EN
	ACALL DEL
	CLR EN
	RET	
		 
CSEG AT 50H
MAIN: 
   	ACALL INI
	MOV R2,#32
	MOV DPTR,#1000H
	MOV R5,#0X40
	ACALL CMD
LP:	
	CLR A
	MOVC A,@A+DPTR
	ACALL DIS
	INC DPTR
	DJNZ R2, LP	

	MOV R5,#0X80
	ACALL CMD

 LOO1:
	MOV A,#0
	ACALL DIS
	ACALL DEL
	MOV A,#1
	ACALL DIS
	ACALL DEL
	MOV A,#1
	ACALL DIS
	ACALL DEL
	MOV A,#3
	ACALL DIS
	ACALL DEL
	SJMP LOO1
	END