; output a num in binary

data segment
    ; so u can -[d]isplay ds:0 to find that 
    ; dos's memory is Little Endian mode
    num1 dw 0abcdh  ; need a 0 prefix to indicate it's a num
    num2 dw 1234h
    array1 dw 0cdefh, 12345 ; 12345 is 0x3039h
data ends

code segment
    assume cs:code, ds:data

start:

; Set up the data segment
mov bx, data
mov ds, bx








; Return control to dos
mov ah, 2ch
int 21h


code ends
    end start
