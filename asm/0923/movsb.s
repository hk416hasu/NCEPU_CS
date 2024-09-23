data segment
    abc db 1,2,3
data ends

abab segment
    bcd db 2,3,4
abab ends

stack segment stack
    dw 0,0,0,0,0,0,0,0
stack ends

code segment
    assume cs:code, ds:data, ss:stack, es:abab   ; put into segment registers

start:
    ; Set up the data segment
    mov ax, data    ; because INTEL tells us to use segment register
    mov ds, ax

    mov ax, abab
    mov es, ax

    mov cx, 3
next:
    movsb
    loop next

    ; Return control to DOS
    mov ah, 4ch
    int 21h

code ends
    end start

