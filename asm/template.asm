; Template for 8086 Assembly Program

data segment
    msg db 'hello world!!$', 0 ; Define a customizable message string
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

    ; Display the message
    lea dx, msg
    mov ah, 9
    int 21h         ; system calls, plz RTFM(about dos) for more

    ; Return control to DOS
    mov ah, 4ch
    int 21h

code ends
    end start

