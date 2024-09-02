code segment
    assume cs:code
start:

; input x
mov ah, 1
int 21h     ; the ASCII is now in AL
sub al, 30h ; to get the value 
mov dl, al

; input y
mov ah, 1h
int 21h
sub al, 30h

; make x + y
add dl, al

; output res
add dl, 30h ; to output the num, u need to make it back to ASCII
mov ah, 2h
int 21h


; return control to the terminal
mov ah, 4ch
int 21h

code ends
    end start
