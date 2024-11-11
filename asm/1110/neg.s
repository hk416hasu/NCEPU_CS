.model small
.stack
.data

.code
main proc
    mov ax, @data
    mov ds, ax

    mov al, 9
    neg al

    mov bl, -125
    neg bl

    mov cl, 131
    neg cl

    mov ax, 9
    neg ax

    mov bx, -125
    neg bx

    mov cx, 131
    neg cx

    mov ah, 4ch
    int 21h


main endp
end main
