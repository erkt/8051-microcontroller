CSEG AT 00H
MOV TMOD,#0X02
MOV TH0,#255
MOV TL0,#00
SETB TR0
JNB TF0,$
CLR TR0
CLR TF0
SJMP $
END