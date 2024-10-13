.model small
.stack
.data
    base dw 10

.code
main proc
    mov ax, @data
    mov ds, ax

; examples
    ; 4096 = 0x1000h
    ; 1234 = 0x04d2h
    ; 0256 = 0x0100h

    mov cx, 4   ; loop times
    mov bx, 0   ; initial num / previous answer(Ans)

next:
    ; get a digit (ascii)
    mov ah, 01h
    int 21h ; al
    mov ah, 0

    ; ascii -> value
    sub al, 30h

    ; (Ans * Base) + input_value
    xchg bx, ax ; exchange Ans and input_value, for MUL
                ; now Ans is in AX, and input_value is in BX
    mul base    ; Ans * Base => AX * base
    add bx, ax  ; + value, answer is in BX

    loop next

    ; return control to DOS
    mov ah, 4ch
    int 21h

main endp
end main
