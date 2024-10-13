.model small
.stack
.data
    num dw ?
    times db 4
    base dw 10h

.code
main proc
    mov ax, @data
    mov ds, ax

; input_for_loop
    mov times, 4
input_loop_begin:
    cmp times, 0
    jz output
; times != 0
    mov ah, 1
    int 21h
    mov ah, 0
; trans ascii to value
    sub al, 30h
    cmp al, 9
    jbe noSub
    sub al, 27h
noSub:
; now val in al is right
; then make them together
    xchg ax, bx ; val in bx now
    mov ax, num
    mul base    ; Ans * Base, and ignore dx
    add ax, bx  ; T1 + val
    mov num, ax
input_loop_end:
    dec times
    jmp input_loop_begin



output:
    mov bx, num
    mov cl, 4   ; each time, we rol 4 bits
    mov times, 4

; out_for_loop
out_loop_begin:
    cmp times, 0
    jz exit

    rol bx, cl
    mov dx, 000fh
    and dl, bl  ; the output val is in dl now

    cmp dl, 0ah
    jl noAdd7
    add dl, 7
noAdd7:
    add dl, 30h
; now ascii is in dl

    mov ah, 2
    int 21h

out_loop_end:
    dec times
    jmp out_loop_begin
    


exit:
    mov ah, 4ch
    int 21h

main endp
end main
