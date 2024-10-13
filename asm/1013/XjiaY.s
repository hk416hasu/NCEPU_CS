.model small
.stack
.data
    x db 1, 2, 3, 4, 5, 6
    y db 6, 5, 4, 3, 2, 1
    z db 6 dup(?)
    op db '+', '-', '+', '-', '-', '+'
    len dw 6

.code
main proc
    mov ax, @data
    mov ds, ax

    mov si, 0*1 ; int i = 0;
loop_begin:
    cmp si, len ; condition judge
    jae exit
    mov bl, op[si]
    cmp bl, 2bh ; (op[si] == '+')?
    jz jiaFa
    mov al, x[si]
    mov bl, y[si]
    sub al, bl  ; x[i] - y[i]
    mov z[si], al
    jmp loop_end
jiaFa:
    mov al, x[si]
    mov bl, y[si]
    add al, bl  ; x[i] + y[i]
    mov z[si], al
loop_end:
    add si, 1*1 ; i++
    jmp loop_begin

exit:
    mov ah, 4ch
    int 21h

main endp
end main

