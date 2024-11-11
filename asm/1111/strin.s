.model small
.stack
.data
    buf db 10 dup (0)
    zhan dw ?,?

.code
main proc
    mov ax, @data
    mov ds, ax

    mov dx, offset buf
    mov buf, 5
    mov ah, 10
    int 21h


    mov ah, 4ch
    int 21h
main endp
end main
