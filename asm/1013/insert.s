.model small
.stack
.data
    abc dw ?, -2, -1, 0, 1, 3, 4
    len dw 7*2

.code
main proc
    mov ax, @data
    mov ds, ax

; initialize
    mov ax, 2   ; insert_num = 2
    mov si, 2   ; '1' * sizeof(dw) = 2

next:
    cmp si, len
    jge exit
    mov bx, abc[si] ; bx = curr_num
    cmp bx, ax
    jge assign
    mov abc[si-2], bx
    add si, 2
    jmp next
assign:
    mov abc[si-2], ax

exit:
    ; return control to DOS
    mov ah, 4ch
    int 21h

main endp
end main
