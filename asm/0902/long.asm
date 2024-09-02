; input 3 digits (in decimal)
data segment
    base dw 10h    
data ends

code segment
    assume cs:code, ds:data
start:

; Load DS with the address of the data segment
mov ax, data
mov ds, ax

; input the HUNDREDS DIGIT
mov ah, 1h
int 21h     ; now the ASCII is in AL
sub al, 30h ; get the value

; mul with base
    ; attention ! mul R will mul R with AL/AX, and the res will in AX(DX)
mov bl, base
mul bl
mov bx, ax

; input the TENS DIGIT
mov al, 1h
int 21h
sub al, 30h

; mul with base
mov 


; return control to the terminal
mov ah, 4ch
int 21h

code ends
    end start
