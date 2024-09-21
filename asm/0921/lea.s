code segment
    assume cs:code

start:

mov bx, 0100h
mov si, 0002h
mov ax ,3000h
mov ss, ax
mov sp, 0020h


lea ax, 1100h[bx][si]

code ends
    end start
