.model small
.stack
.data

.code
main proc

    ;mov ax, 1
    mov ax, -1
    
    cmp ax, 0
    jge exit
    mov bx, 0
    sub bx, ax  ; 0 - neg
    xchg ax, bx ; bx = neg, ax = abs(neg)

exit:
    mov ah, 4ch
    int 21h

main endp
end main
