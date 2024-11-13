.model small
.stack
.data
.code
main proc
    mov ax, 0
    sub ax, ax

    mov ah, 4ch
    int 21h
main endp
end main
