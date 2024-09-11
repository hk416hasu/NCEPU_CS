; output a num in binary

data segment
    ; so u can -[d]isplay ds:0 to find that 
    ; dos's memory is Little Endian mode
    num1 dw 0abcdh  ; need a 0 prefix to indicate it's a num
    num2 dw 12345   ; 12345 is 0x3039h
data ends

code segment
    assume cs:code, ds:data

start:

    ; Set up the data segment
    mov bx, data
    mov ds, bx

    mov bx, num2
    mov cl, 12

abab:
    mov dx, 0fh
    shl dx, cl
    and dx, bx
    shr dx, cl
    add dx, 48
    mov ah, 2
    int 21h
    sub cl, 4
    jnl abab

    ; Return control to dos
    mov al, 0
    mov ah, 4ch
    int 21h


code ends
    end start
