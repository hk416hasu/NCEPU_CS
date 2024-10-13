.model small
.stack
.data
    arr dw 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    len dw 10*2

.code
main proc
    mov ax, @data
    mov ds, ax

; ex_for
    mov si, 0   ; i = 0
ex_loop_begin:
    cmp si, len
    jae exit
; in_for
    mov di, 2   ; j = '1'
in_loop_begin:
    cmp di, len
    jae ex_loop_end
; if
    mov ax, arr[di-2]
    cmp ax, arr[di]
    jbe in_loop_end
    xchg ax, arr[di]
    xchg ax, arr[di-2]
in_loop_end:
    add di, 2
    jmp in_loop_begin
ex_loop_end:
    add si, 2
    jmp ex_loop_begin

exit:

    mov ah, 4ch
    int 21h

main endp
end main
