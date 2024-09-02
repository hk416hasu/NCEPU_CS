; input 3 digits (in decimal)
code segment
    assume cs:code
start:

; input the hundreds digit
mov ah, 1h
int 21h     ; now the ASCII is in AL
sub al, 30h ; get the value
mov bl, al

; mul with base
mov al, 10h
mul bl



; return control to the terminal
mov ah, 4ch
int 21h

code ends
    end start
