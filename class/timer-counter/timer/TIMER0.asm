CSEG AT 00H
MOV TMOD ,#0X00
MOV TH0 , #0X0E0
MOV TL0 , #0X17+2
SETB TR0
JNB TF0 ,$
CLR TR0
CLR TF0
END