data segment
    var db 1
data ends

code segment
    assume cs:code, ds:data
start:

mov ax, data
mov ds, ax

mov di, 2
mov si, 1

;xor word ptr [bx], 1

sub ax, var[bx]

code ends
    end start
