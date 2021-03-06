//1.Write  8051 assembly programs to create  generate a square wave of duty cycles 33%.
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
DELAY:
	MOV TMOD,#0X01
	MOV TH0,#(63535>>8)
	MOV TL0,#(63535 & 0XFF)
	SETB TR0
	JNB TF0 ,$
	CLR TR0
	CLR TF0
	RET

INIT:
 	MOV R5,#0X01
	ACALL CMD
	MOV R5,#0X02
	ACALL CMD
	MOV R5,#0X06
	ACALL CMD
	MOV R5,#0X38
	ACALL CMD
    MOV R5,#0X0C
    ACALL CMD
    MOV R5,#0X80
    ACALL CMD
    RET
DIS:	
	MOV LCD,A
	SETB RS
	CLR RW
	SETB EN
	ACALL DELAY
	CLR EN
	RET
CMD:
	MOV LCD ,R5
	CLR RS
	CLR RW
	SETB EN
	ACALL DELAY
	CLR EN
	RET
L_INI:
	MOV DPTR,#1000H
	MOV R7,#32
	MOV R5,#0X40
	ACALL CMD
L:
	CLR A
	MOVC A,@A+DPTR
	ACALL DIS
	INC DPTR
	DJNZ R7,L
	MOV R5,#0X80
	ACALL CMD
	RET

CSEG AT 50H
MAIN:
	ACALL INIT
	ACALL L_INI
LOOP:	
	MOV A,#0
	ACALL DIS
	ACALL DELAY
	MOV A,#1
	ACALL DIS 
	ACALL DELAY
	MOV A,#2
	ACALL DIS 
	ACALL DELAY
	MOV A,#3
	ACALL DIS
	ACALL DELAY
	SJMP LOOP
	
END