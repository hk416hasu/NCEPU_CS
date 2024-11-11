.model small
.stack
.data
    str db 'hello, world!!$'

.code
abab proc
    mov ax, @data
    mov ds, ax

    mov dx, offset str
    mov ah, 9h
    int 21h

    mov ah, 4ch
    int 21h
abab endp
end abab
