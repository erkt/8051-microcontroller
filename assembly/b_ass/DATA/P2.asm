CSEG AT 00H
MOV 27H,#99H
MOV DPTR,#0027H
MOV A,27H
MOVX @DPTR,A
END
