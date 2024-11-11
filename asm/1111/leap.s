.model small
.stack
.data
    year dw 2023
    t db 0, ?

.code
leap proc
    ; many push
    mov ax, year
    mov dx, 0
    mov bx, 100
    div bx
    cmp dx, 0
    jz elsesta
    mov ax, year
    mov dx, 0
    mov bx, 4
    div bx
    cmp dx, 0
    jz ifsta
    mov ax, year
    mov bx, 400
    mov dx, 0
    div bx
    cmp dx, 0
    jnz elsesta
ifsta:
    mov [t+1], 29
    jmp leapexit
elsesta:
    mov byte ptr [t+1], 28
leapexit:
    ; many pop
    ret
leap endp

main proc
    mov ax, @data
    mov ds, ax
    call leap
exit:
    mov ah, 4ch
    int 21h
main endp

end main
