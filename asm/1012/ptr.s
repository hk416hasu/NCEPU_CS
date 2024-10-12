data segment
    a db 255, 0, 1, 2, 3
data ends

stack segment stack
    dw 0,0,0,0,0,0,0,0
stack ends

code segment
    assume cs:code, ds:data, ss:stack   ; put into segment registers

start:
    ; Set up the data segment
    mov ax, data    ; because INTEL tells us to use segment register
    mov ds, ax

// word ptr do NOT change the type of pointer
    mov ax, (word ptr a)+1
    mov ax, word ptr a+1

    ; Return control to DOS
    mov ah, 4ch
    int 21h

code ends
    end start

