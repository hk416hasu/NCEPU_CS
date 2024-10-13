.model small
.stack
.data
    arr dw 255, 8, 7, 6, 5, 4, 3, 2, 1, 0
    len dw 10*2 ; 10 * '1'

.code
main proc
    mov ax, @data
    mov ds, ax

    mov si, 0*2 ; i = 0
ex_loop_begin:
    cmp si, len
    jae exit
    mov di, 1*2 ; j = 1
in_loop_begin:
    cmp di, len
    jae ex_loop_end
    mov ax, arr[di-2]
    cmp ax, arr[di]
    jbe in_loop_end
    xchg ax, arr[di]
    xchg ax, arr[di-2]
in_loop_end:
    add di, 1*2
    jmp in_loop_begin
ex_loop_end:
    add si, 1*2
    jmp ex_loop_begin

exit:
    mov ah, 4ch
    int 21h

main endp
end main
