code segment
    assume cs:code
start:

; input a char
mov ah, 1h
int 21h

; output that char
mov dl, al
mov ah, 2h
int 21h

; return control to the terminal
mov ah, 4ch
int 21h

code ends
    end start
