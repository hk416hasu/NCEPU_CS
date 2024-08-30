data segment
abc db 'hello world!!', 03, 02, 13, 10
bcd dw -2
data ends

code segment
assume cs:code,ds:data
start:
    mov bx, data
    mov ds, bx
    lea dx, abc
    mov ah,9
    int 21h

    mov ah,4ch
    int 21h
code ends
end start
