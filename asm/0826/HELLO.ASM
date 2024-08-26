DATA SEGMENT
str db 'Hello World!!$'    ;the output str should use $ as end
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA    ;make connection with CS between CODE, DS and DATA
START: 
       MOV BX,DATA 
       MOV DS,BX
       LEA DX,str 
       MOV AH,9
       INT 21H

       MOV AH,4CH        ;return control to the terminal
       INT 21H
CODE ENDS
END START
