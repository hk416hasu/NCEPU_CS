; masm version : 5.10
.model small
.stack
.data   ; before actual-datas are "metadatas" needed by masm
    arr dw 1, 2, 3, 4, 10, 255
    len db 6
    msg db 'hello, world!!$'

.code
main proc
    mov ax, @data
    mov ds, ax

    ; Add your code here
    lea dx, msg
    mov ah, 9
    int 21h

    ; return control to DOS
    mov ah, 4ch
    int 21h

main endp
end main
