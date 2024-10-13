.model small
.stack
.data
    base dw 10

.code
main proc
    mov ax, @data
    mov ds, ax

    mov cx, 4

next:
    mov ah, 01h
    int 21h

    ; to value
    mov ah, 0
    sub al, 30h

    ; together
    mov si, ax
    mov ax, base
    mul bx  ; ignore dx for simple
    add ax, si
    mov bx, ax

    loop next

    ; return control to DOS
    mov ah, 4ch
    int 21h

main endp
end main
